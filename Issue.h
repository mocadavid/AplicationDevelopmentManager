#pragma once
#include <string>

class Issue
{
private:
	std::string description;
	std::string status;
	std::string reporter;
	std::string solver;
public:
	Issue();
	Issue(std::string description, std::string status, std::string reporter, std::string solver);
	bool operator==(Issue issue);
	std::string toString();
	std::string getStatus();
	std::string getDescription();
	std::string getSolver();
	void setStatus(std::string newStatus);
	void setSolver(std::string newStatus);
	~Issue();
};

