#include "3Polymorphism.h"
#include <vector>

using namespace std;

void testDynamicBinding(void)
{
	Account1* acc = new Account1();
	acc->deposit1(100);

	Account1* savAcc = new SavingAccount1();
	savAcc->deposit1(100);

	Account1* chqAcc = new ChequingAccount1();
	chqAcc->deposit1(100);

	cout << "Delete pointers\n";

	delete acc;
	delete savAcc;
	delete chqAcc;

}

void testVectorDynamicBinding(void)
{
	Account2* c1 = new ChequingAccount2();
	Account2* c2 = new ChequingAccount2();
	Account2* c3 = new ChequingAccount2();

	vector <Account2*> accounts{ c1, c2, c3 };
	for (const auto p : accounts)
	{
		p->deposit2(100);
	}
}

void testInterfacePrintable(void)
{
	SavingAccount2 *s = new SavingAccount2();
	SavingAccount2 s1;
	cout << *s;
	cout << s1;

	cout << "Delete Pointer\n";
	delete s;
}