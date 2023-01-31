#include <iostream>

using namespace std;

class Player2
{
	/* there can be 3 different ways to give access:
	 - non class function
	 - function of some other class
	 - an entire object of other class
	 
	 giving such access makes them use private data of the class

	 eg,
	 - friend void display_player(Player2 &p);
	 - friend void other_class::display_player(Player2 &p);
	 - friend other_class object_from_other_class;
	 */
	friend void display_player(Player2 &p);


	int* data;

	/* 
	a variable can be declared static so it is shared in all classes.
	Eg use is to count total number of objects of the class. Can be 
	incremented and decremented in constructor and destructor.

	We can also add a static method in class that can return the count.
	*/
	static int count; 
public:

	// Constructor
	Player2(int dataVal = 0);

	//Destructor
	~Player2();

	//Copy Constructor
	Player2(const Player2& source);

	//Move Constructor
	/* Move Constructor is used to get rid of overhead of deep copy constructor
	R value (temporary objects or just values) is passed in param for move constructor.

	 - It actually moves the pointer and then nullify source pointer. 
	 - Used while returning value from a function, r values passed to a function.
	*/
	Player2(Player2&& source) noexcept;

	/* assignment operator */
	Player2& operator=(const Player2& rhs);

	//Methods
	/*
	// usage of const means this method wont make any changes in data of this class.
	So if we create a constant object and pass to this method it wont give any error.
	otherwise if a constant object is created, we cant do any operation on it.
	*/
	void get_val(int& data) const; 

	/* function shared among all objects of Class */
	static int get_num_players();
};


void display_player(Player2 &p);