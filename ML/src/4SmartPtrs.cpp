/*
Smart pointers were introduced to get rid of memory leakage that can 
occur if we do not delete the pointer before the end of scope of the 
function.

there are three main smart pointers that are each covered in 
individual functions in this file.

Custom deleters example is given here too
*/
#include "4SmartPtrs.hpp"
#include <memory>
#include <vector>
#include "player2.h"

using namespace std;

/* 
- No two pointers can point to Unique pointer at same time
- automatic deletion
- ptr.get() return address
- ptr.reset() makes ptr nullptr

*/
void testUniquePtr(void)
{
	unique_ptr<Player2> pArjun{ new Player2(100) };

	// better way than above as new keyword not used.
	unique_ptr<Player2> pJoti = make_unique<Player2>(1000);

	// cant copy but move the pointer
	unique_ptr<Player2> pRand;

	//pRand = pJoti; // error

	pRand = move(pJoti); // should work

	// creating vector
	vector<unique_ptr<Account1>> pList;

	// if there was constructor defined with params, 
	// we could pass them here in () those values
	pList.push_back(make_unique<ChequingAccount1>()); 
	pList.push_back(make_unique<ChequingAccount1>()); 

#if 1
	// here acc is traversing through the entire pList one at a time.
	for (const auto &acc : pList)
	{
		cout << *acc;
	}
#endif

}

/*
 - one heap object can be shared by multiple pointers.
 - support both copy and move semantics.
 - when use count is zero the object is destroyed on heap memory.
 - some overhead introduced 
 - use_count() can return number of pointers pointing to the memory.
*/
void testSharedPtr(void)
{

	shared_ptr<Account1> acc1 = make_shared< ChequingAccount1>();
	shared_ptr<Account1> acc2 = make_shared< ChequingAccount1>();

	cout << "Count is : " << acc1.use_count() << "\n";
	cout << "Count is : " << acc2.use_count() << "\n";


	vector<shared_ptr<Account1>> accounts;

	accounts.push_back(acc1);
	accounts.push_back(acc2);


	cout << "Count is : " << acc1.use_count() << "\n";
	cout << "Count is : " << acc2.use_count() << "\n";

}

/*
 - similar to shared ptr but no actual ownership.
 - used in case for example: iterating over a list.
 - shared ptr can have issue incase lets say two classes are
 setting shared ptr of each other and when there scope is 
 completed they will still have reference to each other's 
 ptr and can cause memory leak.

 - implementation needs to be added.
*/
void testWeakPtr(void)
{

}


/* 
* Below two functions show implementation of custom deleter.
*/
void my_deleter(Account1* pAcc)
{
	cout << "Custom deleter function called my_deleter called\n";
	delete pAcc;
}

/*
	Cutom deleter can be provided in special cases.
*/
void testCustomDeleter(void)
{
	shared_ptr<Account1> pAcc = { new Account1{}, my_deleter };
}