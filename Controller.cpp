#include "Controller.h"
#include "RepositoryException.h"
#include <QMessageBox>
#include <fstream>
#include <iostream>

Controller::Controller(IssueRepository& repository) :repository{repository}
{
}

std::vector<Issue> Controller::getIssues() {
	return this->repository.getIssues();
}

std::vector<User> Controller::getUsers() {
	return this->repository.getUsers();
}

void Controller::updateIssue(std::string description, std::string solver) {
	this->repository.update(description, solver);
	/*QMessageBox mm;
	mm.setText("a");
	mm.exec();*/
	this->notify();
	this->save();
}

void Controller::save()
{
	std::ofstream fileDescriptor("Saved.txt");
	std::vector<Issue> issues = this->repository.getIssues();
	for (auto issue : issues) {
		fileDescriptor << issue.toString() << std::endl;
	}
	fileDescriptor.close();
}

void Controller::addIssue(Issue issue) {
	try {
		this->repository.addIssue(issue);
		this->notify();
		this->save();
	}
	catch (RepositoryException& re) {
		QMessageBox message;
		message.setText(re.what());
		message.exec();
	}
}

Controller::~Controller()
{
}

void Controller::deleteIssue(std::string description) {
	Issue issue{ description,"1","1","1" };
	try {
		this->repository.deleteIssue(issue);
		this->notify();
		this->save();
	}
	catch (RepositoryException& re) {
		
	}
}