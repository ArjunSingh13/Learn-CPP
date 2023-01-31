#pragma once
#include <iostream>
/*
	This file shows how you can call base class functions from derived class functions.

	CPP compiler does static binding by default. that is deposit below function will be 
	called depending on if call is from Account class or SavingAccount Class

*/

using namespace std;

class Account
{
	friend ostream& operator<<(ostream& os, const Account& account);
private:
	double balance;

public:
	Account(void);
	Account(double initAmount);
	~Account(void);
	void deposit(double amount);
	int getBalance(void) const;
};


class SavingAccount: public Account
{

protected:
	double interest;
public:
	SavingAccount(void);
	SavingAccount(double amount, double intRate);
	~SavingAccount(void);
	void deposit(double amount);

};