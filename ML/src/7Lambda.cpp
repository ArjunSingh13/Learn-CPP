
#include "7lambda.h"
#include <functional>
#include <vector>

// we can also pass lambda to function param in multiple ways
static void passLambda(std::function<void(int, int)> l)
{
	l(10, 20);
}

static void passLambda1(void (*pl)(int, int))
{
	pl(10, 30);
}
// c++ 20 can also do just (auto l) as param

static void printIf(std::vector<int>& vec, bool (*pLambda)(int))
{
	std::cout << "Print if numbers are even : ";
	for (auto i : vec)
	{
		if (pLambda(i)) { std::cout << i << std::endl; }
	}
}

void testMultiplyClass(void)
{
	multiply mulObj{ 10 };
	mulObj(10);
}

void testLambdaStateless(void)
{
	// brackets at last are the reason this lambda expression will actually execute
	// if there are any params to pass we can also pass in the last () the values itself
	// but there are no params passed here in first () so last () will stay empty too
	[]() { std::cout << "Hello from Lambda's world" << std::endl; }();

	// anotherway is
	// also notice this syntax is much simpler than creating function class
	auto func = [](int x, int y) { std::cout << "Lambda's world addition " << x+y << std::endl; };
	func(2,3);

	// mentioning return type with -> is optional
	auto func1 = [](int x, int y) -> int { std::cout << "Lambda's world Multiplication " << x*y << std::endl; };
	func1(2, 3);
}

void testPassLambdaToFunction(void)
{
	auto l = [](int x, int y) { std::cout << "data passed are " << x << " " << y << std::endl; };
	passLambda(l);

}

void testPredicateLambda(void)
{
	// implement where a vector of numbers and a predicate lambda is passed to a function
	// function that receives these two should print depending on when predicate lambda returns true
	// predicate lambda should return true if number is even
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	printIf(vec, [](int num) {return (num % 2 == 0);});

}

void testStatefulLambdaExpression(void)
{
	int x{ 100 };
	int y{ 2 };
	float z{ 3.0 };
	// x in lambda will stay const by default. so () operator will be deduced as Const in expanded class definition of lambda
	[x]() { std::cout << "Data passed to capture list is " << x << std::endl; };

	// to get rid of const in lambda we can use keyword mutable

	[x]() mutable {	x += 20;
	std::cout << "value of x is " << x << std::endl;
	};

	// we can also capture by reference to make changes but now whatever change done in lambda will be visible outside too
 
	// [=] : capture all variables by value
	// [&] : capture all variables by reference
	// [this] : capture this object by reference
	// can also have exceptions eg: [&, x]
	[=, &z]() {std::cout << "params x,y,z are : " << x << y << z; }();
}

/*
* if we pass by value a variable , that is done only once and if we modify that value in lambda, every time we call 
* lambda function it will operate on the previous modified value because eg in below function x is passed only once 
* to lambda and then when l() is called second time lambda is incremented from 200 to 300. think of it as class as well
* x here becomes a private variable and ofcourse its value will be stored and used for next time l() is called.
*/
void testStatefulLambdaExpression1(void)
{
	int x{ 100 };
	int y{ 2 };
	int z{ 3 };

	// here constructor is called
	auto l = [x]() mutable {
		x += 100;
		std::cout << x << std::endl;
	};
	
	l(); // operator called
	l(); // operator called

	//but printiing x here will print 100 as x has different copy in l() .

	// note if we use [=] and then only operate or use x and y and not do anything with z then we will 
	// get warning that why capture z if you dont need it.

}