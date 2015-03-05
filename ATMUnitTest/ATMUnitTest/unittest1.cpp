#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include <iostream>
#include "ATM.h"
#include "Account.h"
#include "Customer.h"
#include <cstdlib>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ATMUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		//TEST CLASS FOR CUSTOMER: customer
		//TEST CLASS FOR ACCOUNT: account
		//TEST CLASS FOR ATM: atm


		//ATM CLASS TESTS ************

		std::string testAddress = "123 Green Ln, Eugene, OR 97405";
		std::string testName = "Adam Cameron";
		std::string testPhone = "541-555-1234";

		//ADAM section
		TEST_METHOD(ATMGetCustomerInfoValid)//Tests GetCustomerInfo in ATM class with a customer object that has valid info
		{
			ATM* testAtm = new ATM();
			testAtm->assignCustomer(testName, testAddress, testPhone);
			Assert::AreEqual(testName, testAtm->getCustomer()->getName());
			Assert::AreEqual(testAddress, testAtm->getCustomer()->getAddress());
			Assert::AreEqual(testPhone, testAtm->getCustomer()->getPhone());
			delete testAtm;
		}

		TEST_METHOD(ATMGetCustomerInfoInvalid)//Tests GetCustomerInfo in ATM class with a customer object that has no info
		{
			ATM* testAtm = new ATM();
			testAtm->assignCustomer("wrong", "more wrong", "wrongest");
			Assert::AreNotEqual(testName, testAtm->getCustomer()->getName());//not sure this is right
			Assert::AreNotEqual(testAddress, testAtm->getCustomer()->getAddress());
			Assert::AreNotEqual(testPhone, testAtm->getCustomer()->getPhone());
			delete testAtm;
		}

		TEST_METHOD(ATMGetBalance)//Tests GetBalance on the ATM class
		{
			ATM* testAtm = new ATM();
			testAtm->assignCustomer("", "", "");
			testAtm->assignAccount(1111, 12345);
			Assert::AreEqual(0.0, testAtm->getBalance());
			delete testAtm;
		}

		TEST_METHOD(ATMWithdrawlValid)//Tests Withdrawal on the ATM class when the ATM has sufficient funds
		{
			ATM* testAtm = new ATM();
			testAtm->assignCustomer("", "", "");
			testAtm->assignAccount(1111, 12345);
			testAtm->deposit(200.0);
			Assert::IsTrue(testAtm->withdraw(150.0));
			Assert::AreEqual(50.0, testAtm->getBalance());
			delete testAtm;
		}

		TEST_METHOD(ATMWithdrawlInvalid)//Tests Withdrawal on the ATM class when the ATM has insufficient funds
		{
			ATM* testAtm = new ATM();
			testAtm->assignCustomer("", "", "");
			testAtm->assignAccount(1111, 12345);
			testAtm->deposit(200.0);
			Assert::IsFalse(testAtm->withdraw(250.0));
			delete testAtm;
		}

		TEST_METHOD(ATMDeposit)//Tests deposit on the ATM class
		{
			ATM* testAtm = new ATM();
			testAtm->assignCustomer("", "", "");
			testAtm->assignAccount(1111, 12345);
			testAtm->deposit(200.0);
			Assert::AreEqual(200.0, testAtm->getBalance());
			delete testAtm;
		}

		TEST_METHOD(ATMSetPin)//Tests SetPin on the ATM class
		{
			ATM* testAtm = new ATM();
			testAtm->assignCustomer("", "", "");
			testAtm->assignAccount(1111, 12345);
			Assert::IsTrue(testAtm->verifyPin(1111));
			testAtm->changePin(2222);
			Assert::IsTrue(testAtm->verifyPin(2222));
			delete testAtm;
		}

		//JAMES Section

		//CUSTOMER CLASS TESTS ******************

		TEST_METHOD(CustomerGetName)//Tests GetName on the Customer class to make sure it returns the correct value
		{
			Customer* testCustomer = new Customer(testName, "", "");
			Assert::AreEqual(testName, testCustomer->getName());
			delete testCustomer;
		}

		TEST_METHOD(CustomerGetAddress)//Tests GetAddress on the Customer class to make sure it returns the correct value
		{
			Customer* testCustomer = new Customer("", testAddress, "");
			Assert::AreEqual(testAddress, testCustomer->getAddress());
			delete testCustomer;
		}

		TEST_METHOD(CustomerGetPhone)//Tests GetPhone on the Customer class to make sure it returns the correct value
		{
			Customer* testCustomer = new Customer("", "", testPhone);
			Assert::AreEqual(testPhone, testCustomer->getPhone());
			delete testCustomer;
		}

		TEST_METHOD(CustomerSetName)//Tests SetName on the Customer class to make sure it sets the correct value
		{
			Customer* testCustomer = new Customer("", "", "");
			testCustomer->setName(testName);
			Assert::AreEqual(testName, testCustomer->getName());
			delete testCustomer;
		}

		//JUSTIN section
		
		TEST_METHOD(CustomerSetAddress)//Tests SetAddress on the Customer class to make sure it sets the correct value
		{
			Customer* testCustomer = new Customer("","","");
			//std::string testAddress = "123 Fake Street, Eugene, OR 97405";
			testCustomer->setAddress(testAddress);
			Assert::AreEqual(testAddress, testCustomer->getAddress());
			delete testCustomer;
		}

		TEST_METHOD(CustomerSetPhone)//Tests SetPhone on the Customer class to make sure it sets the correct value
		{
			Customer* testCustomer = new Customer("","","");
			testCustomer->setPhone(testPhone);
			//std::string testPhone = "541-555-5555";
			Assert::AreEqual(testPhone, testCustomer->getPhone());
			delete testCustomer;
		}

		TEST_METHOD(CustomerAddAccount)//Tests AddAccount on the Customer class to make sure it adds the account reference to the customer correctly
		{
			Customer* testCustomer = new Customer("", "", "");
			testCustomer->addAccount(1111, 12345);
			Account* testAccount = testCustomer->getAccount();
			Assert::AreEqual(12345, testAccount->getAccountNum());
			Assert::IsTrue(testAccount->verifyPin(1111));
			delete testCustomer;
		}

		TEST_METHOD(CustomerRemoveAccount)//Tests RemoveAccount on the Customer class to make sure it removes the correct account
		{
			Customer* testCustomer = new Customer("", "", "");
			testCustomer->addAccount(1111, 12345);
			testCustomer->removeAccount(12345);
			Account* testAccount = testCustomer->getAccount();
			Assert::IsTrue(testAccount == nullptr);
			delete testCustomer;
		}

		TEST_METHOD(CustomerGetAccount)//Tests GetAccounts on the Customer class to make sure it returns the correct account information
		{
			Customer* testCustomer = new Customer("","","");
			testCustomer->addAccount(1111, 12345);

			Account* testAccounts = testCustomer->getAccount();

			Account* testAccount = new Account(1111, 12345, testCustomer);

			Assert::AreEqual(12345, testAccount->getAccountNum());
			Assert::IsTrue(testAccount->verifyPin(1111));

			delete testCustomer;
		}

		//ACCOUNT CLASS TESTS *******************************

		TEST_METHOD(AccountGetCustomer)//Tests GetCustomer on the Account class to make sure it returns the correct customer information
		{
			Customer* testCustomer = new Customer(testName, testAddress, testPhone);
			testCustomer->addAccount(1111, 12345);
			Account* testAccount = testCustomer->getAccount();
			Assert::AreEqual(testCustomer->getName(), testAccount->getCustomer()->getName());
			Assert::AreEqual(testCustomer->getAddress(), testAccount->getCustomer()->getAddress());
			Assert::AreEqual(testCustomer->getPhone(), testAccount->getCustomer()->getPhone());
			delete testCustomer;
		}

		TEST_METHOD(AccountVerifyPin)//Tests VerifyPin on the Account class to make sure it verifies the pin properly
		{
			Account* testAccount = new Account(1111, 12345, nullptr);
			Assert::IsTrue(testAccount->verifyPin(1111));
			delete testAccount;
		}

		//LEVI section

		TEST_METHOD(AccountChangePin)//Tests ChangePin on the Account class to make sure the pin is properly updated to the new pin
		{
			Account* testPin = new Account(1111, 12345, nullptr);
			testPin->changePin(1111, 5555);
			Assert::IsTrue(testPin->verifyPin(5555));
			delete testPin;
		}

		TEST_METHOD(AccountGetBalance)//Tests GetBalance on the Account class 
		{
			Account* balance = new Account(1111, 12345, nullptr);
			balance->deposit(200.00);
			Assert::AreEqual(200.00, balance->getBalance());
			delete balance;
		}

		TEST_METHOD(AccountWithdrawalValid)//Tests Withdrawal on the Account class with sufficient funds 
		{
			double acctBal = 100.00;
			Account* balance = new Account(1111,12345, nullptr);
			balance->deposit(acctBal);
			balance->withdraw(75.00);
			Assert::AreEqual(25.00, balance->getBalance());
			delete balance;
		}

		TEST_METHOD(AccountWithdrawalInvalid)//Tests Withdrawal on the Account class with insufficient funds
		{
			double acctBal = 100.00;
			Account* balance = new Account(1111, 12345, nullptr);
			bool passWithdraw;
			passWithdraw = balance->withdraw(150.00);
			Assert::IsFalse(passWithdraw);
			delete balance;
		}

		TEST_METHOD(AccountDeposit)//Tests Deposit on the Account class 
		{
			Account* balance = new Account(1111, 12345, nullptr);
			balance->deposit(111.50);
			Assert::AreEqual(111.50, balance->getBalance());
			delete balance;
		}
	};
}