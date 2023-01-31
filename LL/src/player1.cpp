/* Player1.cpp file covers about:
*
* 1. Constructor Parameters and Default values. Default values are passed in .h file. 
* 2. Copy Constructors
* 
* C
*/

#include "player1.h"
#include "define.h"

using namespace std;

// Constructor
Player1::Player1(std::string nameVal, int healthVal, int xpVal)
	: name{ nameVal }, health{ healthVal }, xp{ xpVal }
{
	cout << "Constructor with 3 params called\n";
}

// Destructor
Player1::~Player1(void)
{
	cout << "Destructor is called\n\n";
}

// Copy Constructor
Player1::Player1(const Player1& source)
	: name{source.name}, health{ source.health }, xp{source.xp}
{
	cout << "Copy constructor called\n";
}

/*
 *
 *	Methods for this class
 *
 *
*/
void Player1::set_name(std::string nameStr)
{
	name = nameStr;
}

void Player1::get_name(std::string& nameStr)
{
	nameStr = name;
}

bool Player1::is_dead(void)
{
	cout << "I am happily Clearing all variables\r\n";

	xp = 0;
	health = 0;
	name = "null";
	return true;
}
