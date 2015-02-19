#pragma once
#include <string>
#include "Account.h"

/*
GetCustInfo()
SetName()
SetAddress()
setPhone()
AddAccount()
RemoveAccount()
GetAccounts()
TransferBalance()

*/

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