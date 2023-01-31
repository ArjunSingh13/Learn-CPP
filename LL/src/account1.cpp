#include "account1.h"


ChequingAccount1::ChequingAccount1(void)
{
	cout << "ChequingAccount1 destructor with no params\n";
}

ChequingAccount1::~ChequingAccount1(void)
{
	cout << "ChequingAccount1 destructor with no params\n";
}


void Account1::deposit1(double amount)
{
	cout << "Main account1\n";
}

void SavingAccount1::deposit1(double amount)
{
	cout << "Saving account1\n";
}

void ChequingAccount1::deposit1(double amount)
{
	cout << "Chequing account1\n";
}

ostream& operator<<(ostream& os, const Account1& account)
{
	os << "Friend function called for Chequing Account\n";
	return os;
}