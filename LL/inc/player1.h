#pragma once

#include <iostream>
#include "define.h"

using namespace std;

class Player1 {

    string name;
    int health;
    int xp;

public:

    // constructors Param and default values
    /* Initialize values along with declaration so no multiple constructor 
    overloading needed anymore, you can pass 0-3 params for below declaration 
    and if you dont pass any param then below value is used. */
    Player1(string nameVal = "none", int healthVal = 0, int xpVal = 0);

    // destructor
    ~Player1();

    // Copy Constructor
    /* By default Compiler provides a copy constructor but that does shallow copy
     We provide our own Definition to do deep copy which is needed especially if 
     pointers are there
     - We use Const because we dont want to mess source and we pass it by reference.
     - By reference because if we pass by value, copy constructor gets called by default,
     which will again do copy and then we will be in infinite recursion.
     */
    Player1(const Player1& source);

    // methods
    void set_name(string nameStr);
    void get_name(string& nameStr);
    bool is_dead(void);
};
