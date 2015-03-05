#pragma once
#include "Transaction.h"
#include <cstdlib>
#include <vector>

class Customer;

class Account
{
private:
	int pin;
	double balance;
	int accountNum;
	Customer* customer;

	void decBalance(double change)
	{
		balance -= change;
	}

	void incBalance(double change)
	{
		balance += change;
	}

public:
	Account(int pin, int accountNum, Customer* customer)
	{
		this->pin = pin;
		this->accountNum = accountNum;
		balance = 0.0;
		this->customer = customer;
	}
	
	Customer* getCustomer(void)
	{
		return customer;
	}
	
	bool verifyPin(int inputPin)
	{
		if (inputPin == pin)
			return true;

		return false;
	}

	bool changePin(int oldPin, int newPin)
	{		
		if (verifyPin(oldPin))
		{
			pin = newPin;
			return true;
		}

		return false;
	}

	double getBalance(void)
	{
		return balance;
	}

	bool withdraw(double withAmt)
	{
		if (balance >= withAmt)
		{
			decBalance(withAmt);
			return true;
		}
		return false;
	}

	void deposit(double depAmt)
	{
		incBalance(depAmt);
	}

	int getAccountNum(void)
	{
		return accountNum;
	}

}; 


