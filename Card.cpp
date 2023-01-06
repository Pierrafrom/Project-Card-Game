// Project Card Game
// by Pierre
// and Samuel

#include "Card.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

void Card::fill(const string &line) {
    // opening the file
    ifstream file;
    file.open("cards_data.txt");

    if (!file.is_open()) {
        throw out_of_range("Error while opening the file, check if the path specified in Card.cpp is right");
    }
    else {
        string actual_line;

        while (getline(file, actual_line)) {

            if (actual_line == line) {
                stringstream stream(line);
                string value;


                /*

                 * Reads the first value (name) in the string until the next coma and stocks the first value onside the string "value"
                 * then uses "istringstream" in order to convert the string into an int then stocking it into the variable "_name".

                */
                getline(stream, _name, ',');


                /*

                 * Reads the second value (attack) in the string until the next coma and stocks the second value onside the string "value"
                 * then uses "istringstream" in order to convert the string into an int then stocking it into the variable "_attack".

                */
                getline(stream, value, ',');
                istringstream(value) >> _attack;


                /*

                 * Reads the third value (defense) in the string until the next coma and stocks the third value onside the string "value"
                 * then uses "istringstream" in order to convert the string into an int then stocking it into the variable "_defense".

                */
                getline(stream, value, ',');
                istringstream(value) >> _defense;

                /*

                 * Reads the fourth value (magic) in the string until the next coma and stocks the fourth value onside the string "value"
                 * then uses "istringstream" in order to convert the string into an int then stocking it into the variable "_magic".

                */
                getline(stream, value, ',');
                istringstream(value) >> _magic;

            }

        }
    }
    file.close();
}



void Card::changeName(const string &newname) {
    this->_name = newname;
}

void Card::changeAttack(int newatt) {
    this->_attack = newatt;
}

void Card::changeDefense(int newdef) {
    this->_defense = newdef;
}

void Card::changeMagic(int newmag) {
    this->_magic = newmag;
}
