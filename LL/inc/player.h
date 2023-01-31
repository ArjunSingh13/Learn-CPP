#pragma once

#include <iostream>
#include "define.h"


using namespace std;

class Player {

    friend std::ostream& operator<<(std::ostream& os, const Player& obj)
    {
        os << obj.name << " " << obj.health << std::endl;
        return os;
    }
public:
    string name;
    int health;
    int xp;

    // constructors
    Player(void);
    Player(string nameVal, int healthVal);
    Player(string nameVal, int healthVal, int xpVal);

    // destructor
    ~Player();

    // methods
    void set_name(string nameStr);
    void get_name(string &nameStr);
    bool is_dead(void);

    bool operator==(const Player &obj) const {
        if (obj.health == this->health && this->name == obj.name)
        {
            return true;
        }
        return false;
    }

    bool operator<(const Player& obj) const {
        if (this->health < obj.health)
        {
            return true;
        }
        return false;
    }
};
