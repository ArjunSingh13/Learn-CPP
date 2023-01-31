/*
Constructor concepts are yet not tested in this library. Sole purpose
is to test inheritance.
*/

#include "2Inheritance.h"

/* function should call base class no param constructor first
then should call derive class one param constructor
when it leaves the function, derive class destructor called first
then base class */
void testBasicInheritance(void)
{
	derived d2{ 100 };
}

void testInheritance_CorrectBaseConstructorCall(void)
{
	derived1 d1{ 100 };
}

void testOperators(void)
{
	derived1 d1 = 10;
	printf("First task over\n\n");
	derived1 d2{ d1 };
	printf("Second task over\n\n");
	d1 = 10;
	printf("Third task over\n\n");
}

void testStaticBinding(void)
{
	Account* pa1 = new SavingAccount();

	// here account class deposit is called because of static binding
	// but ideally savingAccount deposit should have called because 
	// thats what we used above. this issue is solved later using
	// polymorphism.
	pa1->deposit(100);

	//<< operator overloading
	cout << *pa1;
}

