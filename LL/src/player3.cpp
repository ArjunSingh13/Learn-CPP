/*
This file we are covering :
 - Assignment Operator Overloading 
ClassType &ClassType operator=(const ClassType &rhs);

 - Move Operator overloading
ClassType &ClassType operator=(ClassType &&rhs);

Note:

1. Difference in Constructor and operator overload is constructor overload called when 
we initialize the object and operator overload is called when we assign or move value 
anytime after initialization.

2. Unary operator take no param and binary operator take one param but if we want to use non 
member operator overload functions then we need to declare them friend functions and 
unary then takes one arg and binary takes two args.

*/
#include "player3.h"
#include "console.h"
#include "define.h"

//Constructor
Player3::Player3(const char* buf)
{
	if (buf == nullptr)
	{
		myBuf = new char[1];
		*myBuf = '\0';
	}
	else
	{
		// not sure if its correct to do in constructor , its in copy constructor too
		int myBufSize = strlen(buf) + 1;
		myBuf = new char[myBufSize];
		strcpy_s(myBuf, myBufSize, buf);
	}

	printData(__FILE__, "Constructor Called", GREEN);
}

//Destructor
Player3::~Player3()
{
	delete [] myBuf;
	printData(__FILE__, "Destructor Called", GREEN);
}

// Copy constructor
Player3::Player3(const Player3& source)
	:myBuf{ nullptr }
{
	int myBufLen = strlen(source.myBuf) + 1;
	myBuf = new char[myBufLen];
	strcpy_s(myBuf, myBufLen, source.myBuf);
}

// move constructor
Player3::Player3(Player3 &&source) noexcept
	:myBuf{source.myBuf}
{
	source.myBuf = nullptr;
}


/*
 Assignment operator

 It is called when objects are assigned to each other with
 = sign.
 example Player3 o2{"Hello"}; Player3 o1 = o2.

*/
Player3 &Player3::operator=(const Player3& rhs)
{
	printData(__FILE__, "Copy Assignment operator", GREEN);
	if (this == &rhs)
	{
		printData(__FILE__, "Assigning same value to itself", GREEN);
		return *this;
	}

	// square bracket because we deleting an array
	delete [] myBuf;

	int myBufLen = strlen(rhs.myBuf) + 1;
	myBuf = new char[myBufLen];
	strcpy_s(myBuf, myBufLen, rhs.myBuf);
	return *this;
}

/*
* Move operator
* 
* example p1 = Player3{"Hello World"};
*/
Player3& Player3::operator=(Player3&& rhs) noexcept
{
	// self assignment, return current object
	if (this == &rhs)
	{
		return *this;
	}

	// previously might be pointing with some dynamic mem, free that first
	delete[] myBuf;

	//steal the pointer
	myBuf = rhs.myBuf;

	// null out the rhs object
	rhs.myBuf = nullptr;

	// return current object
	return *this;
}

/* Unary Operator:
*  Not tested yet in main.c
*/
Player3 Player3::operator-() const
{
	int len = strlen(myBuf) + 1;
	char* buf = new char[len];

	for (size_t i = 0; i < len; i++)
	{
		buf[i] = tolower(myBuf[i]);
	}

	Player3 temp{ buf };

	delete[] buf;

	return temp;
}

/* comparison operator: 
* should return bool as result
* 
* Note: not tested yet in main.c
*/
bool Player3::operator==(const Player3& rhs) const
{
	if (strcmp(myBuf, rhs.myBuf) == 0)
	{
		return true;
	}
	else
		return false;
}

/*
Note : similar to above other operators can 
be overloaded as well
*/