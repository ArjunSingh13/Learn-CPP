#include <iostream>

using namespace std;

typedef enum
{
	BLUE = 1,  // File name
	GREEN,     // Constructor
	SKY_BLUE,  // Prints from Main file 
	RED,	   // Destructor
	PURPLE,
	ORANGE,    // Move Constructor
	WHITE,     // Normal
	GRAY,
	COLOR_MAX
}eConsoleColor;


void printData(string fileName, string data, eConsoleColor color, ...);