
#include "base1.h"

base1::base1()
{
	balance = 0;
	printf("Constructor with no param for class named base1 is called\n");
}
base1::base1(int bal)
	: balance{ bal }
{
	printf("Constructor with one param for class named base1 is called\n");
}

base1::~base1()
{
	printf("Destructor called for base1 class\n");
}

base1::base1(const base1& rhs)
	:balance{ rhs.balance }
{
	printf("Base1 class copy constructor called\n");
}

base1& base1::operator=(const base1& rhs)
{
	if (this != &rhs)
	{
		balance = rhs.balance;

	}
	printf("Base1 class assignment operator called \n");
	return *this;
}
derived1::derived1()
	: base1 {}
{
	dblBalance = 0;
	printf("Derived1 class no param constructor called");
}

derived1::derived1(int dblBal)
	:base1{dblBal}, dblBalance{ dblBal*2 }
{
	printf("Derived1 class one param constructor called\n");
}

derived1::~derived1()
{
	printf("Destructor called for derive1 class\n");
}

derived1::derived1(const derived1& rhs) 
	:base1{ rhs }, dblBalance{ rhs.dblBalance } {
	printf("derived1 class copy constructor is called\n");
}

derived1 &derived1::operator=(const derived1& rhs)
{
	if (this != &rhs)
	{
		base1::operator=(rhs);
		dblBalance = rhs.dblBalance;
	}
	printf("Derived class assignment operator called\n");
	return *this;
}