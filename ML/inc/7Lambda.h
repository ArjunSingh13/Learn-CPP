#pragma once
/*
	Lambda expression can be useful when code is just a line or few lines of code. otherwise use function objects.
	Function objects are where () operator is overloaded so objects can be used as functions as well.

	Class multiply is having function object. now in STLs for example we can just use one line of lambda expression.

	Also Behind the scene compiler generate function object for lambdas. (structure can be used as well to create function
	objects)

	Structure of lambda: [] () -> return_type specifiers {};
	where , 

	[] is capture list (empty means lambda capture no info from its environment and only have a param list)
	() is parameter list
	-> return_type is optional if its not provided then compiler will try to deduce it
	specifiers -> are mutable and constexpr
	{} where you write the code

	Lambda expression can be passed to functions as parameter and can be returned from a function as well

	Predicate lambda return bool

	Stateful Lambda expressions:
	Lambda expressions are detailed by compiler as a class which has () as operator. so now class has 
	constructor too so whatever is passed in [] are passed to constructor params. So you can pass variables 
	from environment in [] which is passed to constructor. so now that param automatically become a private
	member of this class for lambda. 

	we pass capture list in this [] for stateful. Examples are:
	int x {100};
	[x] () { cout << x;}

	// Note : we cant capture global or static variable

*/
#include <iostream>

class multiply
{
	int data;

public:
	multiply(int n) : data{ n } {
		std::cout << "constructor called" << std::endl;
	}

	int operator()(int val) {
		data = data * val;
		std::cout << "data is " << data << std::endl;
		return data;
	}
};

void testMultiplyClass(void);
void testLambdaStateless(void);
void testPassLambdaToFunction(void);
void testPredicateLambda(void);
void testStatefulLambdaExpression(void);