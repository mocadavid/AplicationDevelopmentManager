#include "User.h"



User::User()
{
}

User::User(std::string name, std::string type) :name{ name }, type{type}
{
}

bool User::operator==(User user) {
	if (this->name == user.name)
		return true;
	return false;
}

std::string User::getName() {
	return this->name;
}

std::string User::getType() {
	return this->type;
}

User::~User()
{
}
