// Project Card Game
// by Pierre
// and Samuel

#include "Card.h"
#include <iostream>

using namespace std;

// Empty constructor
Card::Card()
{
    _name = "bare hands";
    _attack = 1;
    _defense = 1;
    _magic = 0;
}

// Constructor
Card::Card(const string &name, int attack, int defense, int magic)
{
    _name = name;
    _attack = attack;
    _defense = defense;
    _magic = magic;
}

// Display long
void Card::displayLong() const
{
    cout << "****************************" << endl;
    cout << "name: " << _name << endl;
    cout << "attack: " << _attack << endl;
    cout << "defense: " << _defense << endl;
    cout << "magic: " << _magic << endl;
    cout << "****************************" << endl;
}

// Display short
void Card::displayShort() const
{
    cout << _name << " [ " << _attack << " ; " << _defense << " ; " << _magic << " ] " << endl;
}

// Physical damages
int Card::physicalDamage(const Card &card) const
{
    if (_attack > card._attack)
    {
        if (_attack < card._defense)
        {
            return 0;
        }
        else
        {
            return -(_attack - card._defense);
        }
    }
    else
    {
        if (card._attack == _attack)
        {
            return 0;
        }
        else
        {
            if (card._attack > _defense)
            {
                return (card._attack - _defense);
            }
            else
            {
                return 0;
            }
        }
    }
}

// Magical damages
int Card::magicalDamage(const Card &card) const
{
    if (_magic == card._magic)
    {
        return 0;
    }
    else
    {
        return (card._magic - _magic);
    }
}

// operator + for physicalDamage
int Card::operator+(const Card &card) const
{
    return physicalDamage(card);
}

// operator ^ for magicalDamage
int Card::operator^(const Card &card) const
{
    return magicalDamage(card);
}

// operator << for display short
void operator<<(ostream &os, const Card &card)
{
    card.displayShort();
}

//operator for equality
bool Card::operator==(const Card &card) const
{
    return (this->_name==card._name && this->_attack==card._attack &&
    this->_defense==card._defense && this->_magic==card._magic);
}

// The following methods are not in the instructions, but we had them because they are useful for tests

// Get the Name
string Card::getName() const
{
    return _name;
}

// Get the attack
int Card::getAttack() const
{
    return _attack;
}

// Get the defense
int Card::getDefense() const
{
    return _defense;
}

// Get the magic
int Card::getMagic() const
{
    return _magic;
}

