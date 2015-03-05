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
	Account* account;

public:
	Customer(std::string newName, std::string newAddress, std::string newPhone)
	{
		name = newName;
		address = newAddress;
		phone = newPhone;
		account = nullptr;
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
		account = new Account(pin, accountNumber, this);
	}

	void removeAccount(int accountNumber)
	{
		account = nullptr;
	}

	Account* getAccount()
	{
		return account;
	}
};