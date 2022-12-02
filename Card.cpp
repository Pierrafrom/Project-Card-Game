#include "Card.h"
#include <iostream>

using namespace std;

Card::Card()
{
    _name = "bare hands";
    _attack = 1;
    _defense = 1;
    _magic = 0;
}

Card::Card(const string &name, int attack, int defense, int magic)
{
    _name = name;
    _attack = attack;
    _defense = defense;
    _magic = magic;
}

void Card::display() const
{
    cout << "****************************" << endl;
    cout << "name: " << _name << endl;
    cout << "attack: " << _attack << endl;
    cout << "defense: " << _defense << endl;
    cout << "magic: " << _magic << endl;
    cout << "****************************" << endl;
}

int Card::PhysicalDamage(const Card &card) const
{
    if (_attack > card._attack)
    {
        if (_attack < card._defense)
        {
            return 0;
        }
        else
        {
            return (_attack - card._defense);
        }
    }
    else
    {
        if (card._attack > _defense)
        {
            return -(card._attack - _defense);
        }
        else
        {
            return 0;
        }
    }
}
