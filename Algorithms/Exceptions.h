#pragma once

#include <exception>

class OverflowException : public std::exception
{
public:
	virtual const char* what() const { return "Overflow exception is thrown!"; }
};

class UnderflowException : public std::exception
{
public:
	virtual const char* what() const { return "Underflow exception is thrown!"; }
};