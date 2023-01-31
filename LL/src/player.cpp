/* Player.cpp file covers the concepts of Constructor overloading and 3 different methods of overloading 
Including Obsolete_method_1, method_2 and latest_method

*/

#include "player.h"
#include "define.h"
#include "console.h"

using namespace std;

#if (OBSOLETE_METHOD_1)
/*
	Default Constructor : Showing also the most basic way of 
	initializing private members. But its inefficient as the
	moment we enter the body all variables already initialize 
	and then we giving them value which is inefficient. 
	that is why 2 params construct is using better approach.
*/
Player::Player(void)
{
	xp = 0;
	name = "none";
	health = 0;
	cout << "Default Constructor with 0 params called\n";
}

#elif(OBSOLETE_METHOD_2)
/* This method covers Constructor Initialization list and is better
   than above method because no duplicate initialization happen in this case.
*/
Player::Player(void)
	: xp{ 0 }, name{ "null" }, health{ 0 }
{
	cout << "Default Constructor with 0 params called\n";
}

#elif (LATEST_METHOD)
/* This default constructor is using Delegating Constructor technique
	It is helpful to reduce duplicate code as we are initializing same
	variables in all constructors. So just delegate to the constructor
	that is setting all 3 params.
*/
Player::Player(void)
	: Player{ "none", 0, 0 }
{
	cout << "Default Constructor with 0 params called\n";
}

#else
/* Please define one of the method in define.h */
#endif

/*
*  below is 2 params constructor and it is using Constructor 
*  Delegating technique
*/
Player::Player(std::string nameVal, int healthVal)
	: Player{ nameVal, healthVal, 0}{
	cout << "Constructor with 2 params called\n";
}


Player::Player(std::string nameVal, int healthVal, int xpVal)
	: name{nameVal}, health{healthVal}, xp{xpVal}
{
	xp = 100;
	name = nameVal;
	health = healthVal;

	//printData(__FILE__, "Constructor with 3 params called\n", RED);
}

Player::~Player(void)
{
	cout << "Destructor is called\n\n";
}

/*
 *
 *	Methods for this class
 * 
 * 
*/
void Player::set_name(std::string nameStr)
{
	name = nameStr;
}

void Player::get_name(std::string& nameStr)
{
	nameStr = name;
}

bool Player::is_dead(void)
{
	cout << "I am happily Clearing all variables\r\n";

	xp = 0;
	health = 0;
	name = "null";
	return true;
}
