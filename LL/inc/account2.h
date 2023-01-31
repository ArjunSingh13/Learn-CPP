#pragma once
#include <iostream>
#include "printable.h"
/*
	- Abstract class : Cant be instantiate but are used to derive your own classes from it.they are called
	concrete class.Abstract base class is too generic so we make them concrete.Eg account is concrete class
	and chequing, saving etc derived useful classes.

	- There is no implementation for this but below code can be checked for implementation of Abstract class

	- C++ doesnt provide true interface so Abstract class with pure virtual functions are used to
	get that Interface that can be further used. 

	- Printable class is inherited so no need to explicitly redefine friend function for every class.

	- Smart pointers are discussed in this library.
*/
using namespace std;

class Account2 : public Printable
{
//	friend ostream& operator<<(ostream& os, const Account2& account);
private:
	double balance;

public:
	virtual void deposit2(double amount) = 0; // = 0 makes it pure virtual function
	virtual void print(ostream& os) const override {
		os << "Hello from account via using pure interface class printable\n";
	} // override from Printable class
};

class ChequingAccount2 : public Account2
{
protected:
	double chequingInterest;
public:
	virtual void deposit2(double amount) override ; // with final now this function cant be derived anymore
	virtual void print(ostream& os) const override {
		os << "Hello from chequing account via using pure interface class printable\n";
	} // override from Printable class
};

class SavingAccount2 : public Account2 
{
protected:
	double savingInterest;
public:
	virtual void deposit2(double amount) override;
	virtual void print(ostream& os) const override {
		os << "Hello from saving account via using pure interface class printable\n";
	} // override from Printable class
};


