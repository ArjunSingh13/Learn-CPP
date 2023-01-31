#include "1Constructor.h"
#include <vector>


void testDefaultConstructor(void)
{
    string data;

    // default constructor is called as no arguments passed here
    Player cPlayer;
    cPlayer.set_name("Arjun");
    cPlayer.get_name(data);
    std::cout << "First name set is : " << data << "\n";
}

void test2ParamConstructor(void)
{
    // 2 Params constructor called
    Player dPlayer{ "Joti", 100 };

    string dName;
    dPlayer.get_name(dName);
    cout << "Second name set is : " << dName << "\n";
}

void testPointerConstructor(void)
{
    // Pointer object created and 3 params constructor passed
    Player* enemy = new Player{ "Samita", 0, 0 };
    string dName;
    enemy->get_name(dName);
    cout << "Enemy name is : " << dName << "\n";
    delete enemy;
}

void testConstructorParamAndDefaultValue(void)
{
    // for Player1
    string pName;
    Player1 empty;
    empty.get_name(pName);
    cout << "first player1 getname is " << pName << "\n";
    Player1 frank{ "Frank" };
    frank.get_name(pName);
    cout << "Second player1 getname is " << pName << "\n";

    Player1 villain{ "Samita moti", 69, 69 };
    villain.get_name(pName);
    cout << "third player1 get name is " << pName << "\n";

}

void testCopyConstructor(void)
{
    Player1 empty;

    Player1 villain{ empty };
    string name;
    villain.get_name(name);
    cout << "Villain name after copy constructor :" << name << endl;
}

/*
Shallow copy : issues occur when pointer is copied through constructor copy. Issue is the new copy and the old one
both points to same memory location. Now if one of the object is released in destructor then other is still pointing
to release location.

*/
void testDeepCopyConstructor(void)
{
    Player2 notEmpty{ 110 };
    Player2 test{ notEmpty };

    int data = 0;
    test.get_val(data);
    cout << data << endl;
}

/* Here on each new call of Push_back a new initialization is needed
for entire vector so move constructor is called twice when 20 is pushed
back, move constructor is called thrice when 30 is push back and so on.

- First, a temporary object is created for value 10 on heap So Constructor is called first.
- Second, Move Constructor is called to move data to vector array.
- Third, Destructor is called because we nullified 10 object.

*/
void testMoveConstructor(void)
{
    vector<Player2> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
}

// showing how to use static variables
void testDisplayActivePlayers(void)
{
    int count = 0;
    Player2 p1{ 1 };
    count = p1.get_num_players();
    cout << "Total players are : " << count << endl;
    Player2 p2{ 2 };
    count = p1.get_num_players();
    cout << "Total players are : " << count << endl;
    count = p2.get_num_players();
    cout << "Total players are : " << count << endl;

    display_player(p2);
}

void testAssignmentOperator(void)
{
    Player3 p1{ "arjun" };  // default constructor
    Player3 p2{ p1 };       // copy constructor
    Player3 p3 = p1;        // copy constructor

    // assignment operator: cant be done at initialization period
    // only be used after that
    p3 = p2;
}

void testMoveOperator(void)
{
    Player3 p1 = Player3{ "Arjun" };  // copy constructor
    p1 = "Joii";  // move constructor
}