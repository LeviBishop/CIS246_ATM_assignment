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

		//ADAM section
		/*TEST_METHOD(ATMGetCustomerInfoValid)//Tests GetCustomerInfo in ATM class with a customer object that has valid info
		{

			Customer* testCustomer = new Customer("Adam Cameron", "123 Green Ln", "777-777-7777");
			Assert::AreSame("Adam Cameron", testCustomer.getName());
			Assert::AreSame("151 Green Ln", testCustomer.getAddress());
			Assert::AreSame("777-777-7777", testCustomer.getPhone());
			delete testCustomer;
		}

		TEST_METHOD(ATMGetCustomerInfoInvalid)//Tests GetCustomerInfo in ATM class with a customer object that has no info
		{
			Customer* testCustomer = new Customer();
			customer.setName("Adam Cameron");
			customer.setAddress("123 Green Ln");
			customer.setPhone("777-777-7777");
			Assert::AreSame(customer.getName(), "");//not sure this is right
			Assert::AreSame(customer.getAddress(), "");
			Assert::AreSame(customer.getPhone(), "");
			delete testCustomer;
		}

		TEST_METHOD(ATMGetBalance)//Tests GetBalance on the ATM class with no account pointer
		{
			Customer* testBalance = new Customer();
			testBalance->setBalance(500);
			Assert::AreEqual(500, testBalance->getBalance());
			delete testCustomer;
		}

		TEST_METHOD(ATMWithdrawlValid)//Tests Withdrawal on the ATM class when the ATM has sufficient funds
		{
			customer* testwithdrawal = new customer();
			testwithdrawal->withdraw(500);
			assert::areequal(500, testwithdrawal->getbalance());
			delete testcustomer;
		}

		TEST_METHOD(ATMWithdrawlInvalid)//Tests Withdrawal on the ATM class when the ATM has insufficient funds
		{
			Customer* testWithdrawal = new Customer();
			testWithdrawal->setBalance(200);
			testWithdrawal->withdrawal(500);
			Assert::AreEqual(testWithdrawal->getBalance(), testWithdrawal->withdrawal());//not right yet
			delete testWithdrawal;
		}

		TEST_METHOD(ATMDeposit)//Tests deposit on the ATM class
		{
			Customer* testDeposit = new Customer();
			testDeposit->deposit(500);
			Assert::AreSame(500, account1->getBalance());
			delete testDeposit;
		}

		TEST_METHOD(ATMSetPin)//Tests SetPin on the ATM class
		{
			Customer* testPIN = new Customer();
			testPIN->setPin(5555)
			testPIN->testPin(5555)
			Assert::AreEqual(setPin, verifyNewPin);
			delete testPIN;
		}*/

		//JAMES Section

		TEST_METHOD(ATMTransferBalanceValid)//Tests TransferBalance on the ATM class with sufficient funds to transfer
		{
			//atm.transferBalance(500);
			//Assert::AreEqual(500, account1->getBalance());
			//Assert::AreEqual(500, account2->getBalance());
		}

		TEST_METHOD(ATMTransferBalanceInvalid)//Tests TransferBalance on the ATM class with insufficient funds to transfer
		{
			//atm.transferBalance(500);
			//Assert::AreEqual(0, account1->getBalance());
			//Assert::AreEqual(0, account2->getBalance());
		}

		TEST_METHOD(ATMDestroyCard)//Tests DestroyCard on the ATM class to ensure the card is destroyed?
		{
			//Assert::IsTrue(atm.destroyCard());
		}

		//CUSTOMER CLASS TESTS ******************

		TEST_METHOD(CustomerGetName)//Tests GetName on the Customer class to make sure it returns the correct value
		{
			//Assert::AreEqual("James", customer.getName());
		}

		TEST_METHOD(CustomerGetAddress)//Tests GetAddress on the Customer class to make sure it returns the correct value
		{
			//Assert::AreEqual("1234 Street", customer.getAddress());
		}

		TEST_METHOD(CustomerGetPhone)//Tests GetPhone on the Customer class to make sure it returns the correct value
		{
			//Assert::AreEqual("541-555-1234", customer.getPhone());
		}

		TEST_METHOD(CustomerSetName)//Tests SetName on the Customer class to make sure it sets the correct value
		{
			//customer.setName("James");
			//Assert::AreEqual("James", customer.getName());
		}

		//JUSTIN section
		
		TEST_METHOD(CustomerSetAddress)//Tests SetAddress on the Customer class to make sure it sets the correct value
		{
			Customer* testCustomer = new Customer("","","");
			std::string testAddress = "123 Fake Street, Eugene, OR 97405";
			testCustomer->setAddress(testAddress);
			Assert::AreSame(testAddress, testCustomer->getAddress());
			delete testCustomer;
		}

		TEST_METHOD(CustomerSetPhone)//Tests SetPhone on the Customer class to make sure it sets the correct value
		{
			Customer* testCustomer = new Customer("","","");
			testCustomer->setPhone("541-555-5555");
			std::string testPhone = "541-555-5555";
			Assert::AreSame(testPhone, testCustomer->getPhone());
			delete testCustomer;
		}

		TEST_METHOD(CustomerAddAccount)//Tests AddAccount on the Customer class to make sure it adds the account reference to the customer correctly
		{
			Customer* testCustomer = new Customer("", "", "");
			testCustomer->addAccount(1111, 12345);
			std::vector<Account*>* testAccounts = testCustomer->getAccounts();
			Account* testAccount = new Account(1111, 121345, testCustomer);
			Assert::AreSame(testAccount, testAccounts[0][0]);
			delete testCustomer;
		}

		TEST_METHOD(CustomerRemoveAccount)//Tests RemoveAccount on the Customer class to make sure it removes the correct account
		{
			Customer* testCustomer = new Customer("", "", "");
			testCustomer->addAccount(1111, 12345);
			testCustomer->addAccount(2222, 54321);
			testCustomer->removeAccount(12345);
			std::vector<Account*>* testAccounts = testCustomer->getAccounts();
			Account* testAcct = new Account(2222, 54321, testCustomer);
			Assert::AreEqual(testAcct, testAccounts[0][0]);
			delete testCustomer;
		}

		TEST_METHOD(CustomerGetAccounts)//Tests GetAccounts on the Customer class to make sure it returns the correct account information
		{
			Customer* testCustomer = new Customer("","","");
			testCustomer->addAccount(1111, 12345);
			testCustomer->addAccount(2222, 12346);
			testCustomer->addAccount(3333, 12347);

			std::vector<Account*>* testAccounts = testCustomer->getAccounts();

			Account* testAccountOne = new Account(1111, 12345, testCustomer);
			Account* testAccountTwo = new Account(2222, 12346, testCustomer);
			Account* testAccountThree = new Account(3333, 12347, testCustomer);

			Assert::AreEqual(testAccountOne, testAccounts[0][0]);
			Assert::AreEqual(testAccountTwo, testAccounts[0][1]);
			Assert::AreEqual(testAccountThree, testAccounts[0][2]);
			delete testCustomer;
		}

		//ACCOUNT CLASS TESTS *******************************

		TEST_METHOD(AccountGetCustomer)//Tests GetCustomer on the Account class to make sure it returns the correct customer information
		{
			Customer* testCustomer = new Customer("", "", "");
			testCustomer->addAccount(1111, 12345);
			std::vector<Account*>* testAccounts = testCustomer->getAccounts();
			Assert::AreSame(testCustomer, testAccounts[0][0]->getCustomer());
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

		/*TEST_METHOD(AccountStatement)//Tests Statement on the Account class to make sure it returns all the transaction information for the specified time period
		{
			Account* testStatement = new Account();
			testStatement->statement("acctStatement");
			Assert::AreEqual("acctStatement", testStatement->statement());
			delete testStatement;
		}*/

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