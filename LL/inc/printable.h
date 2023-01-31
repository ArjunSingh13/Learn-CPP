#pragma once
/*
Purpose of this file is to show how to implement a pure virtual class that can be used as interface
by other class.

when this class is inherited , derived class gets to use friend function '<<' and you need to implement
print function as well. operator overloaded << gives a call to print function with ostream param.
so now you can implement print function with ostream param and thats it, it should work with actual
definition hidden in this library.

Other benefit is friend function cant be inherited so better to make them as different class interface to use.

*/

#include <iostream>

using namespace std;

class Printable
{
	friend ostream &operator<<(ostream &os, const Printable& obj);

public:
	virtual void print(ostream& os) const = 0;
	virtual ~Printable();
};