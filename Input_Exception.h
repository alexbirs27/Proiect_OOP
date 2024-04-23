#pragma once
#include <iostream>
using namespace std;
class Input_Exception : public exception
{
public:
	virtual const char* what() const throw() = 0;
	virtual ~Input_Exception() = default;

};
class Name_Exception : public Input_Exception
{
public:
	const char* what() const throw()
	{
		return "Rescrie numele!\n";
	}
	~Name_Exception() {};
};
class Number_Exception :public Input_Exception {
public:
	const char* what() const throw()
	{
		return "Rescrie numarul!\n";
	}
	~Number_Exception() {};
};