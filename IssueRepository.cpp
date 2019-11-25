#include "IssueRepository.h"
#include <fstream>
#include <string>
#include <QMessageBox>
#include "RepositoryException.h"
using namespace std;

IssueRepository::IssueRepository()
{
	this->loadIssues();
	this->loadUsers();
}

void IssueRepository::addIssue(Issue issue) {
	bool duplicate = false;
	for (auto issueFromRepository : this->issues) {
		if (issueFromRepository == issue) {
			duplicate = true;
			break;
		}
	}
	if (!duplicate) {
		this->issues.push_back(issue);
	}
	else {
		throw RepositoryException{ "Same description!" };
	}
}

void IssueRepository::addUser(User user) {
	bool duplicate = false;
	for (auto userFromRepository : this->users) {
		if (userFromRepository == user) {
			duplicate = true;
			break;
		}
	}
	if (!duplicate) {
		this->users.push_back(user);
	}
	else {
		
	}
}

void IssueRepository::loadIssues()
{
	char buffer[101];
	char* argument;
	ifstream fileDescriptor("IssuesFile.txt");
	while (fileDescriptor.getline(buffer, 100)) {
		argument = strtok(buffer, ",\n");
		string description{ argument };
		argument = strtok(NULL, ",\n");
		string status{ argument };
		argument = strtok(NULL, ",\n");
		string reporter{ argument };
		argument = strtok(NULL, ",\n");
		string solver{ argument };
		Issue issue{ description,status,reporter,solver };
		this->addIssue(issue);
	}
	fileDescriptor.close();
}

void IssueRepository::loadUsers()
{
	char buffer[101];
	char* argument;
	ifstream fileDescriptor("UsersFile.txt");
	while (fileDescriptor.getline(buffer, 100)) {
		argument = strtok(buffer, ",\n");
		string name{ argument };
		argument = strtok(NULL, ",\n");
		string type{ argument };
		User user{ name,type };
		this->addUser(user);
	}
	fileDescriptor.close();
}

int IssueRepository::getSizeIssues() {
	return this->issues.size();
}

int IssueRepository::getSizeUsers() {
	return this->users.size();
}

std::vector<User> IssueRepository::getUsers() {
	return this->users;
}

std::vector<Issue> IssueRepository::getIssues() {
	return this->issues;
}

void IssueRepository::update(std::string description, std::string solver) {
	
	int index = 0;
	for (auto issue : this->issues) {
		if (issue.getDescription() == description) {
			break;
		}
		index++;
	}
	this->issues[index].setStatus("closed");
	this->issues[index].setSolver(solver);
}

IssueRepository::~IssueRepository()
{
}

void IssueRepository::deleteIssue(Issue issue) {
	int index = 0;
	for (auto issueFromRepository : this->issues) {
		if (issue == issueFromRepository) {
			if (issueFromRepository.getStatus() == "open") {
				throw RepositoryException{ "It is still open!" };
			}
			break;
		}
		index++;
	}
	this->issues.erase(this->issues.begin() + index);
}