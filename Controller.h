#pragma once
#include "IssueRepository.h"
#include "Subject.h"


class Controller:public Subject
{
private:
	IssueRepository& repository;
public:
	Controller(IssueRepository& repository);
	std::vector<Issue> getIssues();
	std::vector<User> getUsers();
	void addIssue(Issue issue);
	void deleteIssue(std::string description);
	void updateIssue(std::string description, std::string solver);
	void save();
	~Controller();
};

