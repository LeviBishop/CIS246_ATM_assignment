#pragma once
#include <string>
#include <vector>
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
	std::vector<Account*> accounts;
	int numAccounts;

public:
	Customer(std::string newName, std::string newAddress, std::string newPhone)
	{
		numAccounts = 0;
		name = newName;
		address = newAddress;
		phone = newPhone;
	}
	std::string getName(void)
	{
		return name;
	}
	std::string getAddress(void)
	{
		return address;
	}
	std::string getPhone(void)
	{
		return phone;
	}
	void setName(std::string newName)
	{
		name = newName;
	}

	void setAddress(std::string newAddress)
	{
		address = newAddress;
	}

	void setPhone(std::string newPhone)
	{
		phone = newPhone;
	}

	void addAccount(int pin, int accountNumber)
	{
		accounts[numAccounts] = new Account(pin, accountNumber, this);
		numAccounts++;
	}

	void removeAccount(int accountNumber)
	{
		for (int i = 0; i < numAccounts; i++)
		{
			if (accountNumber == accounts[numAccounts]->getAccountNum())
			{
				delete accounts[i];
				std::vector<Account*>::const_iterator tempIter = accounts.begin() + i;
				accounts.erase(tempIter);
				break;
			}
		}
	}

	std::vector<Account*>* getAccounts()
	{
		return &accounts;
	}

	void transferBalance(double amount, int accountFrom, int accountTo)
	{
		int accountIndexFrom;
		int accountIndexTo;

		accountIndexFrom = getAccountIndex(accountFrom);
		accountIndexTo = getAccountIndex(accountTo);

		if (accounts[accountIndexFrom]->transferOut(amount))
		{
			accounts[accountIndexTo]->transferIn(amount);
		}
	}

	int getAccountIndex(int accountNum)
	{
		for (int i = 0; i < numAccounts; i++)
		{
			if (accountNum == accounts[i]->getAccountNum())
			{
				return i;
			}
		}
	}
};