#include "Issue.h"



Issue::Issue()
{
}

bool Issue::operator==(Issue issue) {
	if (this->description == issue.description)
		return true;
	return false;
}

Issue::Issue(std::string description, std::string status, std::string reporter, std::string solver)
	:description{ description }, status{ status }, reporter{ reporter }, solver{ solver }
{
}

std::string Issue::getStatus() {
	return this->status;
}

std::string Issue::getDescription() {
	return this->description;
}

std::string Issue::toString() {
	std::string finalString{""};
	finalString += this->description;
	finalString += ",";
	finalString += this->status;
	finalString += ",";
	finalString += this->reporter;
	finalString += ",";
	finalString += this->solver;
	return finalString;
}

Issue::~Issue()
{
}

void Issue::setStatus(std::string newStatus) {
	this->status = newStatus;
}

void Issue::setSolver(std::string newSolver) {
	this->solver = newSolver;
}

std::string Issue::getSolver() {
	return this->solver;
}