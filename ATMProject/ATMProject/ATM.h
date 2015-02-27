#pragma once
//<<<<<<< HEAD
#include "Customer.h"
#include <vector>
#include <iostream>

//=======
//#include "ATM.h"
//#include <iostream>
//>>>>>>> origin/master

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
	double bankBalance;
	Customer* customer;
	std::vector<Account*> accounts;



public:

	ATM(void);
	void getCustomerInfo(void)
	{
		std::cout << "Name: \n" << customer->getName() << "\n";
		std::cout << "Address: \n" << customer->getAddress() << "\n";
		std::cout << "Phone: \n" << customer->getPhone() << "\n";
	}

	int getTestInt(void)
	{
		int testInt = 5;
		return testInt;
	}

	void getBalance(int account)
	{
		int index = customer->getAccountIndex(account);
		std::cout << "Your current balance is: " << accounts[index]->getBalance() << ".\n";
	}

	void withdraw(double amount, int account)
	{
		int index = customer->getAccountIndex(account);
		if (accounts[index]->withdraw(amount))
		{
			std::cout << "You have received " << amount << ".\n";
		}
		else
		{
			std::cout << "You have insufficient funds!\n";
		}
	}

	void deposit(double amount, int account)
	{
		int index = customer->getAccountIndex(account);
	}

	void changePin(int pin, int account)
	{
		int index = customer->getAccountIndex(account);
		int oldPin;
		bool pinChanged = false;
		for (int i = 0; i < 3; i++)
		{
			std::cout << "Please enter your old Pin";
			std::cin >> oldPin;
			if (accounts[index]->changePin(oldPin, pin))
			{
				std::cout << "You have successfully changed your PIN\n";
				pinChanged = true;
			}
			else
			{
				std::cout << "That entry is invalid\n";
			}
		}
		if (!pinChanged)
		{
			std::cout << "You have entered an invalid PIN to many times. \n";
			std::cout << "Your account is now locked. Please speak with someone inside the bank to resolve this. \n";
		}

	}

	void transferBalance(double amount, int accountFrom, int accountTo)
	{
		int indexFrom = customer->getAccountIndex(accountFrom);
		int indexTo = customer->getAccountIndex(accountTo);

		if (customer->transferBalance(amount, accountFrom, accountTo))
		{
			std::cout << "You have successfully transfered " << amount << " from \n"
				 << accountFrom << " to " << accountTo << ".\n";
		}

	}

	void destroyCard(void)
	{
		std::cout << "Your card has been destroyed!\n";
	}

};
