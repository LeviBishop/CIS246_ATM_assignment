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

	cout << "Welcome to telebank! Please enter your card\n";
	cout << "(simulating card being inserted)(Enter 12341234)\n";

	atm->assignCustomer("name", "address", "phone");
	atm->assignAccount(testPin, accountAccess);

	do 
	{
		cout << "Please enter your PIN for this account\n";
		cin >> accessPin;

	} while (!atm->verifyPin(accessPin));
	
	do 
	{
		int value;
		cout << "(D)eposit\n";
		cout << "(W)ithdraw\n";
		cout << "(E)xit\n";
		cin >> choice;

		if (choice == 'd')
		{
			cout << "How much would you like to deposit?\n";
			cin >> value;
			cout << "You have deposited " << value << " into your account\n";
		}

		else if (choice == 'w')
		{
			cout << "How much would you like to withdraw?\n";
			cin >> value;
			if (atm->withdraw(value))
			{
				cout << "You withdrew " << value << " from your account\n";
				cout << "(money comes out)\n";
			}

		}


	} while (choice != 'e');


	system("pause");

	return 0;
}