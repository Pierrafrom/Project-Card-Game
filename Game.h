// Project Card Game
// by Pierre
// and Samuel

#ifndef PROJECT_CARD_GAME_GAME_H
#define PROJECT_CARD_GAME_GAME_H

#include <vector>
#include "Card.h"
#include "Player.h"

class Game
{
    vector<Card> _reserve;
    Player _player1;
    Player _player2;

public:
    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * Empty constructor with default values                                                         *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    Game();

    /*
   *************************************************************************************************
   *                                                                                               *
   *                                                                                               *
   * Description :                                                                                 *
   * ===========                                                                                   *
   * Game constructor                                                                              *
   *                                                                                               *
   *                                                                                               *
   *************************************************************************************************
   */
    Game(const vector<Card> &reserve, Player &player1, Player &player2);

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * returns if the game has ended or not, if it has, the player object taken as parameter         *
    * takes the information of the winner between both player                                       *
    *                                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * a Player object that is updated when the game ends                                            *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * a boolean which indicates whether the game has ended or not                                   *
    * if there is a draw, throw an exception                                                        *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    bool ended(Player &winner) const;

    /*
   *************************************************************************************************
   *                                                                                               *
   *                                                                                               *
   * Description :                                                                                 *
   * ===========                                                                                   *
   * one round ouf the game is done                                                                *
   *                                                                                               *
   *                                                                                               *
   *************************************************************************************************
   */
    void operator++();

    bool IsGameFinished() const;

    // The following methods are not in the instructions, but we had them because they are useful for tests

    bool compareReserve(const vector<Card> &vector) const;

    void modifyPlayerTwoPrestige(int num);

    void clearPlayerTwoDeck();

    bool compareGame(const Game &game);

    Player GetPlayerOne();

    Player GetPlayerTwo();

    int winner();

    /*
   *************************************************************************************************
   *                                                                                               *
   * Description                                                                                   *
   * ===========                                                                                   *
   * the reserve is filled with the information found in the file given as parameter               *
   *                                                                                               *
   *                                                                                               *
   *                                                                                               *
   * Input parameters                                                                              *
   * ====================                                                                          *
   * the name of the file we want to read on                                                       *
   *                                                                                               *
   *                                                                                               *
   * Output parameters                                                                             *
   * ====================                                                                          *
   * nothing because it's a procedure                                                              *
   *                                                                                               *
   *************************************************************************************************
   */
    void fillReserve(const string &filename);

    void getReserve();

    void sort(vector<Card> &reserve);



};
bool compareCards(Card obj1, Card obj2);

#endif //PROJECT_CARD_GAME_GAME_H

