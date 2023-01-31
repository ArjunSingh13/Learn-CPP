/* - this file demonstrates deep vs shallow copy
   - this file demonstrates use of const
   - this file demonstrates use of static variable in class.
   - this file demonstrates use of friend functionality.
*/

#include "player2.h"
#include "console.h"
#include "define.h"

// defining the static variable for the class
int Player2::count = 0;

//Constructor
Player2::Player2(int dataVal)
{
	count++; // increment Player2 object count

	data = new int;
	*data = dataVal;

	printData(__FILE__, "Constructor Called", GREEN);
}

//Destructor
Player2::~Player2()
{
	count--; // decrement Player2 object count

	if (data != nullptr)
	{
		printData(__FILE__, "Destructor called", RED);
		cout << "freeing data for : " << *data << endl;
	} 
	else
	{
		printData(__FILE__, "Destructor deleting data for nullptr", RED);
	}

	delete data;
}

/*
* Copy Constructor is called when we are copying one object to another,
* eg passing object to a function or just assigning one object to another
* 
* Drawback of Player2 copy: Now old object and new object both have same 
* address where they pointing to so if one of the object's life cycle 
* is completed then other one is pointing to released memory as first one
* ran destructor for itself.
*/

#if SHALLOW_COPY_ENABLED
//Shallow Copy Constructor
Player2::Player2(const Player2 &source)
	: data{source.data}
{
	printData(__FILE__, "Shallow Copy Constructor Called", WHITE);
}

#elif DEEP_COPY_ENABLED
//Deep Copy Constructor
Player2::Player2(const Player2& source)
{
	data = new int;
	*data = *(source.data);
	printData(__FILE__, "Deep Copy Constructor Called", WHITE);
}

#else
/* Please enable only one of the above macro otherwise
shallow copy will be done everytime */
#endif

// Move Constructor: just nullify the incoming ptr
Player2::Player2(Player2 &&source) noexcept
	:data{source.data}
{
	source.data = nullptr;
	printData(__FILE__, "Move Constructor Called", ORANGE);
}


/*Methods of Class*/
void Player2::get_val(int& dataVal) const
{
	printData(__FILE__, "get_val method is called", WHITE);
	dataVal = *data;
	return;
}

/* being a static method it only has access to static
data memmbers of the class
*/
int Player2::get_num_players(void)
{
	return count;

}

/* Non member methods */
void display_player(Player2& p)
{
	cout << "Actual data is " << *(p.data) << endl;
}

/* 
	Operator Overloading
*/

//assignment operator
Player2 &Player2::operator=(const Player2& rhs)
{
	if (this == &rhs)
		return *this;

	// de allocate previously assigned string
    delete [] data;

	// strlen is used with char so i just typecasted rhs.data below
	data = new int[sizeof(int)];

	// now copy the data
	memcpy(data, rhs.data, sizeof(int));

	return *this;
}
