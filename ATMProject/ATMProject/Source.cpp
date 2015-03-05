#include <cstdlib>
#include "ATM.h"

using namespace std;

int main(void)
{
	ATM* atm = new ATM;
	int accountAccess = 12341234;
	int testPin = 1111;
	int accessPin;
	char choice;

	cout << "Welcome to telebank! Please enter your card.\n";
	cout << "(simulating card being inserted)(Entering 12341234)\n";

	atm->assignCustomer("name", "address", "phone");
	atm->assignAccount(testPin, accountAccess);

	do 
	{
		cout << "Please enter your PIN for this account. (testing PIN is 1111)\n";
		cin >> accessPin;

		if (!atm->verifyPin(accessPin))
		{
			cout << "Invalid PIN!\n";
		}

	} while (!atm->verifyPin(accessPin));
	
	do 
	{
		int value;
		cout << "(C)heck Balance\n";
		cout << "(D)eposit\n";
		cout << "(W)ithdraw\n";
		cout << "(E)xit\n";
		cin >> choice;

		if (choice == 'c')
		{
			cout << "Your current balance is " << atm->getBalance() << ".\n";
		}

		else if (choice == 'd')
		{
			cout << "How much would you like to deposit?\n";
			cin >> value;
			atm->deposit(value);
			cout << "You have deposited " << value << " into your account\n";
		}

		else if (choice == 'w')
		{
			cout << "How much would you like to withdraw?\n";
			cin >> value;
			if (atm->withdraw(value))
			{
				cout << "You withdrew " << value << " from your account (money comes out)\n";
			}

			else
			{
				cout << "You have insufficient funds.\n";
			}

		}


	} while (choice != 'e');

	cout << "Thank you for using telebank. See you next time!\n";
	system("pause");

	return 0;
}