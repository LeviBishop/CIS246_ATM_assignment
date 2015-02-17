#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include "ATM.h"
#include "Account.h"
#include "Customer.h"

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
		
		TEST_METHOD(SampleTestMethod)//Tests GetCustomerInfo in ATM class with a customer object that has valid info
		{
			ATM* ATMTest = new ATM();
			Assert::AreEqual(1, ATMTest->getTestInt());
		}

		TEST_METHOD(ATMGetCustomerInfoValid)//Tests GetCustomerInfo in ATM class with a customer object that has valid info
		{

		}

		TEST_METHOD(ATMGetCustomerInfoInvalid)//Tests GetCustomerInfo in ATM class with a customer object that has no info
		{
			
		}

		TEST_METHOD(ATMGetBalance)//Tests GetBalance on the ATM class with no account pointer
		{
			
		}

		TEST_METHOD(ATMWithdrawlValid)//Tests Withdrawal on the ATM class when the ATM has sufficient funds
		{
			
		}

		TEST_METHOD(ATMWithdrawlInvalid)//Tests Withdrawal on the ATM class when the ATM has insufficient funds
		{
			
		}

		TEST_METHOD(ATMDeposit)//Tests deposit on the ATM class
		{
			
		}

		TEST_METHOD(ATMSetPin)//Tests SetPin on the ATM class
		{
			
		}

		//JAMES Section

		TEST_METHOD(ATMTransferBalanceValid)//Tests TransferBalance on the ATM class with sufficient funds to transfer
		{
			
		}

		TEST_METHOD(ATMTransferBalanceInvalid)//Tests TransferBalance on the ATM class with insufficient funds to transfer
		{
			
		}

		TEST_METHOD(ATMDestroyCard)//Tests DestroyCard on the ATM class to ensure the card is destroyed?
		{
			
		}

		//CUSTOMER CLASS TESTS ******************

		TEST_METHOD(CustomerGetName)//Tests GetName on the Customer class to make sure it returns the correct value
		{
			
		}

		TEST_METHOD(CustomerGetAddress)//Tests GetAddress on the Customer class to make sure it returns the correct value
		{
			
		}

		TEST_METHOD(CustomerGetPhone)//Tests GetPhone on the Customer class to make sure it returns the correct value
		{
			
		}

		TEST_METHOD(CustomerSetName)//Tests SetName on the Customer class to make sure it sets the correct value
		{
			
		}

		//JUSTIN section
		
		TEST_METHOD(CustomerSetAddress)//Tests SetAddress on the Customer class to make sure it sets the correct value
		{
			Customer* testCustomer = new Customer();
			testCustomer->setAddress("123 Fake Street, Eugene, OR 97405");
			Assert::AreSame("123 Fake Street, Eugene, OR 97405", testCustomer->getAddress());
			delete testCustomer;
		}

		TEST_METHOD(CustomerSetPhone)//Tests SetPhone on the Customer class to make sure it sets the correct value
		{
			Customer* testCustomer = new Customer();
			testCustomer->setPhone("541-555-5555");
			Assert::AreSame("541-555-5555", testCustomer->getPhone());
			delete testCustomer;
		}

		TEST_METHOD(CustomerAddAccount)//Tests AddAccount on the Customer class to make sure it adds the account reference to the customer correctly
		{
			Customer* testCustomer = new Customer();
			testCustomer->addAccount(new Account());
			vector<Account*> testAccounts = testCustomer->getAccounts();

			Assert::AreSame(new Account(), testCustomer->getAccounts());
			delete testCustomer;
		}

		TEST_METHOD(CustomerRemoveAccount)//Tests RemoveAccount on the Customer class to make sure it removes the correct account
		{
			
		}

		TEST_METHOD(CustomerGetAccounts)//Tests GetAccounts on the Customer class to make sure it returns the correct account information
		{
			
		}

		//ACCOUNT CLASS TESTS *******************************

		TEST_METHOD(AccountGetCustomer)//Tests GetCustomer on the Account class to make sure it returns the correct customer information
		{
			
		}

		TEST_METHOD(AccountVerifyPin)//Tests VerifyPin on the Account class to make sure it verifies the pin properly
		{
			
		}

		//LEVI section

		TEST_METHOD(AccountChangePin)//Tests ChangePin on the Account class to make sure the pin is properly updated to the new pin
		{
			
		}

		TEST_METHOD(AccountStatement)//Tests Statement on the Account class to make sure it returns all the transaction information for the specified time period
		{
			
		}

		TEST_METHOD(AccountGetBalance)//Tests GetBalance on the Account class 
		{
			
		}

		TEST_METHOD(AccountWithdrawalValid)//Tests Withdrawal on the Account class with sufficient funds 
		{
			
		}

		TEST_METHOD(AccountWithdrawalInvalid)//Tests Withdrawal on the Account class with insufficient funds
		{
			
		}

		TEST_METHOD(AccountDeposit)//Tests Deposit on the Account class 
		{
			
		}
	};
}