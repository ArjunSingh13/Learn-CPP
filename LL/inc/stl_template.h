/*
* Template classes are typically contained completely in header file as 
* its just a blue print and not compiled
*/

#pragma once
#include <iostream>

/* Function templates*/
template <typename T>
T greaterNumber(T val1, T val2)
{
	return (val1 > val2) ? val1 : val2;
}

template <typename T1, typename T2>
T1 printTwoNumbers(T1 number1, T2 number2)
{
	std::cout << "Number 1 and 2 are " << number1 << " " << number2;

	return 0;
}

/* Class template */
template <typename T1, typename T2>
class item
{
private:
	T1 name;
	T2 value;

public:
	item (T1 name, T2 value)
		: name{name}, value{value}
	{ }

	T1 get_name() const { return name; }
	T2 get_value() const { return value; }
};

/* Structure template */
template <typename T1, typename T2>
struct myPair
{
	T1 first;
	T2 second;
};

/* Array template

It can be useful for creating array of any size and any datatype.

We create a class template for this which has features just like an array

overloading of << and [] is done here to provide complete functionality of an 
array using Class 
*/

template <typename T, int n>
class arra
{
	int size{ n }; //  storing length of array
	T values[n]; // initializing array here with the help of template

	// cout is an object of class ostream
	// here we putting array values to the object os which is cout passed
	// to this function << so it needs to be returned so can actually print
	friend std::ostream &operator<<(std::ostream &os, const arra <T,n>&arrData) {
		os << "[";

		for (const auto& val : arrData.values)
			os << val << " ";
		os << "]"<< std::endl;

		return os;
	}
public:
	arra() = default;

	arra(int initVal) {
		for (auto& item : values)
			item = initVal;
	}

	void fill(int val)
	{
		for (auto& item : values)
		{
			item = val;
		}
	}

	int getSize(void) const
	{
		return size;
	}

	int& operator[](int index)
	{
		return values[index];
	}
};
