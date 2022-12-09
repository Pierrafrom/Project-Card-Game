#ifndef PROJECT_CARD_GAME_CARD_H
#define PROJECT_CARD_GAME_CARD_H

#include <string>

using namespace std;

//Declaration of class
class Card
{
    string _name;
    int _attack;
    int _defense;
    int _magic;

public:
    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Empty constructor                                                                             *
    * Constructs a card named "bare hands" with 1 attack, 1 defense, 0 magic                        *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * Empty because we don't need any parameters to create default card                             *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * Empty because it's a constructeur                                                             *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    Card();

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Constructor on the basis of given information                                                 *
    * Constructs a Card with given name, attack, defense and magic                                  *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * A string for the name and 3 integers for attack, defense and magic                            *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * Empty because it's a constructor                                                              *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    Card(const string &name, int attack, int defense, int magic);

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Short display of a Card                                                                       *
    * Displays all data associated with the target Card                                             *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * Empty because we don't need any parameters to display a Card                                  *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * Empty because it's a procedure                                                                *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    void displayShort() const;

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * returns the physical damage taken                                                             *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * One object Card which is targeted and one object Card as a parameter                          *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * returns an integer                                                                            *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    int physicalDamage(const Card &card) const;

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Long display of a Card                                                                        *
    * Displays all data associated with the target Card                                             *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * Empty because we don't need any parameters to display a Card                                  *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * Empty because it's a procedure                                                                *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    void displayLong() const;

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * returns the magical damage taken                                                              *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * One object Card which is targeted and one object Card as a parameter                          *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * returns an integer                                                                            *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    int magicalDamage(const Card &card) const;

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * returns the function physicalDamage(const Card &card)                                         *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * One object Card which is targeted and one object Card as a parameter                          *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * returns an int                                                                                *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    int operator+(const Card &card) const;

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * returns the function magicalDamage(const Card &card)                                          *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * One object Card which is targeted and one object Card as a parameter                          *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * returns an int                                                                                *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    int operator^(const Card &card) const;
};

/*
*************************************************************************************************
*                                                                                               *
* Description                                                                                   *
* ===========                                                                                   *
* returns the short display of a card                                                           *
*                                                                                               *
*                                                                                               *
*                                                                                               *                                                                                               *
* Input parameters                                                                              *
* ====================                                                                          *
* An output stream and the card we want to display                                              *
*                                                                                               *
*                                                                                               *
* Output parameters                                                                             *
* ====================                                                                          *
* Nothing because it's a procedure                                                              *
*                                                                                               *
*                                                                                               *
*                                                                                               *
*                                                                                               *
*                                                                                               *
*************************************************************************************************
*/
void operator<<(ostream &os, const Card &card);

#endif //PROJECT_CARD_GAME_CARD_H
