#pragma once
#include <iostream>
/*
This file is used to explain polymorphism's late binding concepts(Dynamic binding).

Virtual keyword in base class makes function to bind dynamically.

(Not implemented in code but important to know)
Virtual destructors are required when we want to use dynamic binding: so make virtual destructors.
Virtual keyword is only needed for base class and all derived class destructor become virtual too so 
correct destructor called when pointers are used to initialize in case like:
base* b1 = new derived();  

override specifier: if make mistake in function name then its not redefine in derived class but 
different functions. so override helps to tell us no same definition in base class. 
only needed in derived class.

final specifier: if used then no more classes with that function can be derived.
*/

using namespace std;

class Account1
{
	friend ostream& operator<<(ostream& os, const Account1& account);
private:
	double balance;

public:
	virtual void deposit1(double amount) ;
	int getBalance1(void) const;
};

class SavingAccount1 : public Account1
{
protected:
	double savingInterest;
public:
	virtual void deposit1(double amount) override;

};


class ChequingAccount1 : public Account1
{
	friend ostream& operator<<(ostream& os, const Account1& account);
protected:
	double chequingInterest;
public:
	ChequingAccount1(void);
	~ChequingAccount1(void);
	virtual void deposit1(double amount) override final; // with final now this function cant be derived anymore
};

