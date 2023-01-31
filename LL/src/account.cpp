#include "account.h"
#include "console.h"

Account::Account(void)
	:Account{0.0}
{
	printf("Account class default constructor called\n");
	balance = 0;
}

Account::Account(double initAmount)
{
	printf("Account class default constructor called\n");
	balance = initAmount;
}

Account::~Account(void)
{
	printf("Account class destructor called\n");
	balance = 0;
}
void Account::deposit(double amount)
{
	printf("Account class deposit called\n");
	balance += amount;
}

int Account::getBalance(void) const
{
	return balance;
}

ostream& operator<<(ostream& os, const Account& account)
{
	os << "Saving Account balance: " << account.getBalance();
	return os;
}
SavingAccount::SavingAccount(void)
	: Account{}  // this is done to init Base class, can explictly mention especially if constructor is overloaded
{
	printf("SavingAccount class default constructor called\n");
	interest = 1;
}

SavingAccount::SavingAccount(double amount, double intRate)
	:Account(amount), interest{intRate}
{
	printf("SavingAccount one param class constructor called\n");
}

SavingAccount::~SavingAccount(void)
{
	printf("SavingAccount class destructor called\n");
	interest = 0;
}

void SavingAccount::deposit(double amount)
{
	printf("SavingAccount class Deposit called\n");
	amount = 1.01 * amount;
	Account::deposit(amount);
}
