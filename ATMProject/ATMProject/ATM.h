#pragma once
#include "ATM.h"

/*
BankBalance
Customer*
Accounts[]*

GetCustomerInfo()
GetBalance()
Withdrawal()
Deposit()
SetPIN()
TransferBalance()
DestroyCard()

*/

class ATM
{
private:
	int testInt;



public:

	ATM(void)
	{
		testInt = 0;
	}

	int getTestInt(void)
	{
		return testInt;
	}
};
