#include "Account.h"

bool Account::verifyPin(int inputPin)
{
	if (inputPin == pin)
	{
		return true;
	}
	return false;
}
