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
    * Display of a Card                                                                             *
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
    void display() const;

    int PhysicalDamage(const Card &) const;

};


#endif //PROJECT_CARD_GAME_CARD_H
