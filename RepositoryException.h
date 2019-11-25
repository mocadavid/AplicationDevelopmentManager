#pragma once
#include <iostream>

class RepositoryException :
	public std::exception
{
private:
	std::string message;
public:
	RepositoryException(std::string message);
	const char* what() const override;
	~RepositoryException();
};

