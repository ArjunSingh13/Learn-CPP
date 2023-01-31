
#include "base.h"

base::base()
{
	balance = 0;
	printf("Constructor with no param for class named base is called\n");
}
base::base(int bal)
	: balance{bal}
{
	printf("Constructor with one param for class named base is called\n");
}

base::~base()
{
	printf("Destructor called for base class\n");
}

derived::derived()
{
	derBalance = 0;
	printf("Derived class no param constructor called");
}

derived::derived(int derBal)
	:derBalance{derBal}
{
	printf("Derived class one param constructor called\n");
}

derived::~derived()
{
	printf("Destructor called for derive class\n");
}