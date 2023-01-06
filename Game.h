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

    void playsARound();

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

    int winner();

    // The following methods are not in the instructions, but we had them because they are useful for tests

    bool compareReserve(const vector<Card> &vector) const;

    void modifyPlayerTwoPrestige(int num);

    void modifyPlayerOnePrestige(int num);

    void clearPlayerTwoDeck();

    bool compareGame(const Game &game);

    Player GetPlayerOne();

    Player GetPlayerTwo();

    vector<Card> getReserve();

    void fillReserve(const string &filename);

    int getSizeReserve();

    //~Game();
};

vector<int> vectorOfRanks(const vector<Card> &reserve, Tri sortCriteria);

void mergeCard(vector<int> &deck, int start1, int end1, int end2, Tri sortcriteria, const vector<Card> &reserve);

void mergeSortBisCard(vector<int> &deck, int start, int end, Tri sortcriteria, const vector<Card> &reserve);

void mergeSortCard(vector<int> &deck, int length, Tri sortCriteria, const vector<Card> &reserve);

void sortVectorOfCard(vector<int> &deck, Tri sortCriteria, const vector<Card> &reserve);

void sortReserve(vector<Card> &reserve);

#endif //PROJECT_CARD_GAME_GAME_H
