#pragma once
/*
this file shows how to call correct base class constructor wrt derived class

also covers derive class copy constructor and assignment operator: trick is 
these operators is require to be called in derived class must also take care
of base class as well. we can pass the same input to base class as well. as 
derived class is super set of base class. base class can take care of slicing 
extra content and only use base class content for overloading operation.
*/

#include <iostream>

class base1
{
private:
	int balance;
public:
	base1();				// constructor
	base1(int bal);  //constructor overloading
	~base1();			// destructor

	base1(const base1& rhs);
	base1& operator=(const base1 &rhs);
};

class derived1 :public base1
{
private:
	int dblBalance;

public:
	derived1();
	derived1(int dblBal);
	~derived1();

	derived1(const derived1& rhs); // copy constructor
	derived1& operator=(const derived1& rhs);  //assignment operator
};