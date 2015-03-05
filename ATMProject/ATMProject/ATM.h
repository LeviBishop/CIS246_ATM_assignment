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
	Account* account;
	int accountNum;



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

	double getBalance(void)
	{
		return customer->getAccount()->getBalance();
	}

	bool withdraw(double amount)
	{
		if (account->withdraw(amount))
		{
			return true;
		}
		
		return false;
	}

	void deposit(double amount)
	{
		account->deposit(amount);
	}

	bool changePin(int pin)
	{
		int oldPin;
		bool pinChanged = false;
		
		if (account->changePin(oldPin, pin))
		{
			return true;
		}

		return false;

	}

	void destroyCard(void)
	{
		std::cout << "Your card has been destroyed!\n";
	}


	void assignCustomer(std::string name, std::string address, std::string phone)
	{
		customer = new Customer(name, address, phone);
	}

	void assignAccount(int pin, int accountNumber)
	{
		customer->addAccount(pin, accountNumber);
	}
};
