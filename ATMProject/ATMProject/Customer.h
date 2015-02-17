#pragma once
#include <string>
#include "Account.h"

class Customer
{
private:
	std::string name;
	std::string address;
	std::string phone;
	Account** accounts;

public:
	std::string getName(void)
	{
		return name;
	}

};