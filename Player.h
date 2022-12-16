// Project Card Game
// by Pierre
// and Samuel

#ifndef PROJECT_CARD_GAME_PLAYER_H
#define PROJECT_CARD_GAME_PLAYER_H

#include <vector>
#include <iostream>
#include "Card.h"

using namespace std;

class Player
{
    string _name;
    int _prestige;
    vector<int> _deck;

public :
    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Empty constructor                                                                             *
    * Constructs a Player named "Yugi" with 25 prestige points and a vector of Card with 5 cards    *
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
    Player();

    /*
     *************************************************************************************************
     *                                                                                               *
     * Description                                                                                   *
     * ===========                                                                                   *
     * Player on the basis of given information                                                      *
     * Constructs a Player with given name, prestige and a deck                                      *
     *                                                                                               *
     * Input parameters                                                                              *
     * ====================                                                                          *
     * A string for the name an integer for the prestige points and a vector of int                  *
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
    Player(const string &name, int prestige, const vector<int> &deck);

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * get the name of targeted player                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    string GetName() const;

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * get the number prestige points of targeted player                                             *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    int GetPrestige() const;

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * Displaying targeted player information                                                        *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    void display();

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * Initialising the targeted player's pile of int                                                *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    void init(vector<Card> &);

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * returns true if there is enough cards in the deck                                             *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    bool enoughCards() const;

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * returns true if there is still in the game                                                    *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    bool enoughPrestige() const;

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Prints the next card if there is one if not throws an exception                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * a Card object                                                                                 *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * prints the next card of the target's deck                                                     *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */

    void nextCard(int &card);

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * changes the prestige of the targeted player / player taken as parameter                       *
    * it depends on the stats of the players next card                                              *
    *                                                                                               *
    *                                                                                               *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * a player object                                                                               *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * update the object taken as parameter                                                          *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    void playsACard(Player &player, const vector<int> &reserve);


};

#endif //PROJECT_CARD_GAME_PLAYER_H

