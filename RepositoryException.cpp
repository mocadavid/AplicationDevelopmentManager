#include "RepositoryException.h"



RepositoryException::RepositoryException(std::string message) :message{message}
{
}

const char* RepositoryException::what() const {
	return this->message.c_str();
}

RepositoryException::~RepositoryException()
{
}
