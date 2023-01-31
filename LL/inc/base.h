#pragma once
/*
this file covers basics of inheritance

- Public derived class has all params and objects access same way,
- Protected derived class has public and protected as protected and private as is.
- Private derived class has everything derived with private access.

- Protected is same as private but the only difference in protected variables can 
be accessed in derived class' public function itself and which is not possible for
private members. both private and protected cant be access by objects.

- When derived class object is created first base class constructor executes then 
derived class.
- Destructor called opposite way, derived class first then base class.

- if an overload constructor is not defined in derived class but same
present in base class then using syntax: using baseClassName::baseClassName;
can make compiler use base class constructor but issue persists that it wont
initialize if there is any variable in dervied class.

- if a derived class constructor with param called (for example) it will
still call base class default constructor (one with no param) 

*/

#include <iostream>

class base
{
private:
	int balance;
public:
	base();				// constructor
	base(int bal);  //constructor overloading
	~base();			// destructor
};

class derived:public base
{
private:
	int derBalance;

public:
	derived();
	derived(int derBal);
	~derived();
};