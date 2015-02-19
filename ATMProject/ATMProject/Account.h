#pragma once
#include "Account.h"
#include <cstdlib>
/*
WithdrawalValid
WithdrawalInvalid

Pin
Balance
Account #
Customer *
History []
*/

class Account
{
private:
	int pin;
	int balance;
	int acctNumber;
	Customer** customer;
	Customer* History;

public:
	std::string getCustomer()
	{
	}
	
	std::bool verifyPin()
	{
	}

	std::void changePin()
	{		
	}

	std::bool statement()
	{
	}

	std::double getBalance()
	{
	}

	std::void withdraw()
	{
	}

	std::void deposit()
	{
	}

}; 
