#pragma once
#include "Issue.h"
#include "User.h"
#include <vector>

class IssueRepository
{
private:
	std::vector<Issue> issues;
	std::vector<User> users;
public:
	IssueRepository();
	void addIssue(Issue issue);
	void deleteIssue(Issue issue);
	void addUser(User user);
	void loadIssues();
	void loadUsers();
	void update(std::string description, std::string solver);
	int getSizeIssues();
	int getSizeUsers();
	std::vector<User> getUsers();
	std::vector<Issue> getIssues();
	~IssueRepository();
};

