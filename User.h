#pragma once
#include <string>

class User
{
private:
	std::string name;
	std::string type;	//programmer or tester
public:
	User();
	User(std::string name, std::string type);
	bool operator==(User user);
	std::string getName();
	std::string getType();
	~User();
};

