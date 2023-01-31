#include <iostream>

class Player3
{
private:
	char* myBuf;

public:

	//Constructor
	Player3(const char* buf = NULL);

	//Destructor
	~Player3();

	// Copy constructor
	Player3(const Player3& source);

	// move constructor
	Player3(Player3 &&source) noexcept;

	// Assignment operator
	Player3 &operator=(const Player3& rhs);

	// Move operator
	Player3 &operator=(Player3&& rhs) noexcept;

	// Unary operator
	Player3 operator-() const;

	//comparison operator
	bool operator==(const Player3& rhs) const;
};
