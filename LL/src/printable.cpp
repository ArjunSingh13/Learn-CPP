#include "printable.h"

ostream& operator<<(ostream& os, const Printable& obj)
{
	obj.print(os);
	return os;
}

Printable:: ~Printable(void)
{
	cout << "Destroying object of printable class\n";
}