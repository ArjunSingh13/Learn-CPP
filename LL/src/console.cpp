#include <windows.h>
#include <iostream>
#include "console.h"

using namespace std;

// fileName should always be __FILE__ to give path of current file
// TODO: Add option to send n number of variables to this function
void printData(string fileName, string data, eConsoleColor color, ...)
{
	HANDLE  hConsole;
	size_t index;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// take out file name and not complete path
	for (index = fileName.size(); index > 0; index--)
	{
		if (fileName[index - 1] == '\\' || fileName[index - 1] == '/')
			break;
	}

	SetConsoleTextAttribute(hConsole, BLUE);
	std::cout << fileName.substr(index);

	SetConsoleTextAttribute(hConsole, color);
	cout <<" : " << data << endl;

	SetConsoleTextAttribute(hConsole, WHITE);

	return;
}