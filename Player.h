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
    // here, we use an integer vector. the integers are the indices of the cards in the reserve.
    // This avoids using objects as parameters and therefore saving resources
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
    * Description                                                                                   *
    * ===========                                                                                   *
    * Displays information about the player                                                         *
    *                                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * Empty because we don't need any parameters to display a Player                                *
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
    void init();

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
    *                                                                                               *
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
    *                                                                                               *
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

    void playsACard(Player &player, const vector<Card> &reserve);

    //need to add comments

    void shuffle();

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * the player chooses from the reserve given in argument which card he wants in his deck         *
    *   -makes a sequential search                                                                  *
    *                                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * the reserve of the game                                                                       *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * nothing it's a procedure                                                                      *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */

    void letChoose(const vector<Card> &reserve);

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * the player chooses from the reserve given in argument which card he wants in his deck         *
    *   -makes a dichotomic search                                                                  *
    *                                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * the reserve of the game                                                                       *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * nothing it's a procedure                                                                      *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */

    void letChooseDicho(const vector<Card> &reserve);

    // The following methods are not in the instructions, but we had them because they are useful for tests

    void modifyPrestige(int num);

    void clearDeck();

    bool compareDeck(const vector<int> &);

    vector<int> getDeck();

    void modifyDeck(const vector<int> &deck);

    bool operator==(const Player &player);



};

#endif //PROJECT_CARD_GAME_PLAYER_H
