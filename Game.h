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
    * Description                                                                                   *
    * ===========                                                                                   *
    * plays a round of the game by calling the function playsACard                                  *
    *                                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * no parameters                                                                                 *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * no visible output, but it actualises the stats of the players depending on                    *
    * the result of the function playsACard                                                         *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    void playsARound();

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * one round ouf the game is done, the operator ++ is the equivalent of playsARound              *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    void operator++();

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * returns if the game is finished                                                               *
    *                                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * no parameters                                                                                 *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * returns a bollean wich is set to true when game has ended, false when game has not ended      *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    bool IsGameFinished() const;

    /*
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * returns a specific integer depending on the winner of the game                                *
    * we know if the game has ended by calling the function ended with a default Player object      *
    * so when the function ended has ended ;) the default object is set with the data of the winner *
    *                                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * no parameters                                                                                 *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * returns 1 if player 1 won the game and -1 if player 2 won                                     *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    int winner();

    // The following methods are not in the instructions, but we had them because they are useful for tests

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * compare the actual reserve with another reserve                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    bool compareReserve(const vector<Card> &vector) const;

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * modify the prestige of player 2                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    void modifyPlayerTwoPrestige(int num);

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * modify the prestige of player 1                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    void modifyPlayerOnePrestige(int num);

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * clears player 2 deck                                                                          *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    void clearPlayerTwoDeck();

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * compares the actual game with the game taken as parameter                                     *
    *                                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param game an object of Game different from the actual game                                  *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * returns a boolean, 1 if the games are the same and 0 if they ain't                            *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    bool compareGame(const Game &game);

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * returns the object of Player named player1                                                    *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    Player GetPlayerOne();

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * returns the object of Player named player1                                                    *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    Player GetPlayerTwo();

    /*
    *************************************************************************************************
    *                                                                                               *
    *                                                                                               *
    * Description :                                                                                 *
    * ===========                                                                                   *
    * returns the vector of Card named reserve                                                      *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    vector<Card> getReserve();

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * fills the game's reserve with the data found in @param filename                               *
    *                                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param filename wich is the file name  ¯\_(¨_¨)_/¯                                            *
    *                                            | |                                                *
    *                                           /   \                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * nothing is directly returned of displayed but the targeted game's reserve                     *
    * is filled and sorted by alphabetical order                                                    *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    **/
    void fillReserve(const string &filename);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * compares the actual game with the game taken as parameter                                     *
    *                                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * no input parameters                                                                           *
    *                                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * returns an int representing the reserve's size                                                *
    *                                                                                               *
    *                                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    int getSizeReserve();

    //~Game();
};

/**
*************************************************************************************************
*                                                                                               *
*                                                                                               *
* Description :                                                                                 *
* ============                                                                                  *
* gets the vector of ranks from @param reserve a vector of Card                                 *
* with @param sortCriteria a chosen sort criteria                                               *
*                                                                                               *
*************************************************************************************************
*/
vector<int> vectorOfRanks(const vector<Card> &reserve, Tri sortCriteria);

/**
*************************************************************************************************
*                                                                                               *
* Description                                                                                   *
* ===========                                                                                   *
* the function applies a merge sort to the vector @param deck                                   *
*                                                                                               *
*                                                                                               *
* Input parameters                                                                              *
* ====================                                                                          *
* @param deck -> a reference to the vector of integers that will be sorted                      *
* @param start1 -> an integer representing the start index of the first half of the vector      *
* @param end1 -> an integer representing the end index of the first half of the vector          *
* @param end2 -> an integer representing the end index of the second half of the vector         *
* @param sortcriteria -> a Tri type value representing the sorting criterion                    *
* @param reserve -> a constant reference to a vector of Card objects called                     *
*                                                                                               *
*                                                                                               *
* Output parameters                                                                             *
* ====================                                                                          *
* returns nothing                                                                               *
*                                                                                               *
*                                                                                               *
*                                                                                               *
*************************************************************************************************
*/
void mergeCard(vector<int> &deck, int start1, int end1, int end2, Tri sortcriteria, const vector<Card> &reserve);

/**
*************************************************************************************************
*                                                                                               *
* Description                                                                                   *
* ===========                                                                                   *
* recursive implementation of mergeCard() function that sorts the vector in descending order    *
*                                                                                               *
*                                                                                               *
* Input parameters                                                                              *
* ====================                                                                          *
* @param deck -> a reference to the vector of integers that will be sorted                      *
* @param start -> an integer representing the start index of the first half of the vector       *
* @param end -> an integer representing the end index of the first half of the vector           *
* @param sortcriteria -> a Tri type value representing the sorting criterion                    *
* @param reserve -> a constant reference to a vector of Card objects called                     *
*                                                                                               *
*                                                                                               *
* Output parameters                                                                             *
* ====================                                                                          *
* returns nothing                                                                               *
*                                                                                               *
*                                                                                               *
*                                                                                               *
*************************************************************************************************
*/
void mergeSortBisCard(vector<int> &deck, int start, int end, Tri sortcriteria, const vector<Card> &reserve);

/**
*************************************************************************************************
*                                                                                               *
* Description                                                                                   *
* ===========                                                                                   *
* this wrapper function provides a simpler interface for calling the "mergeSortBisCard"         *
* function and starting the process of sorting the input vector.                                *
*                                                                                               *
*                                                                                               *
* Input parameters                                                                              *
* ====================                                                                          *
* @param deck -> a reference to the vector of integers that will be sorted                      *
* @param length -> an integer representing the length of the vector (length)                    *
* @param sortcriteria -> a Tri type value representing the sorting criterion                    *
* @param reserve -> a constant reference to a vector of Card objects called                     *
*                                                                                               *
*                                                                                               *
* Output parameters                                                                             *
* ====================                                                                          *
* returns nothing                                                                               *
*                                                                                               *
*                                                                                               *
*                                                                                               *
*************************************************************************************************
*/
void mergeSortCard(vector<int> &deck, int length, Tri sortCriteria, const vector<Card> &reserve);

/**
*************************************************************************************************
*                                                                                               *
* Description                                                                                   *
* ===========                                                                                   *
* sorts a vector of integers using the merge sort algorithm, with the ability to specify a      *
* sorting criterion using a Tri type value and a reference to a vector of Card objects.         *
*                                                                                               *
*                                                                                               *
* Input parameters                                                                              *
* ====================                                                                          *
* @param deck -> a reference to the vector of integers that will be sorted                      *
* @param sortcriteria -> a Tri type value representing the sorting criterion                    *
* @param reserve -> a constant reference to a vector of Card objects called                     *
*                                                                                               *
*                                                                                               *
* Output parameters                                                                             *
* ====================                                                                          *
* returns nothing                                                                               *
*                                                                                               *
*                                                                                               *
*                                                                                               *
*************************************************************************************************
*/
void sortVectorOfCard(vector<int> &deck, Tri sortCriteria, const vector<Card> &reserve);

/**
*************************************************************************************************
*                                                                                               *
* Description                                                                                   *
* ===========                                                                                   *
* sorts the reserve of the targeted game in ascending order                                     *
*                                                                                               *
*                                                                                               *
* Input parameters                                                                              *
* ====================                                                                          *
* @param reserve -> the vector of Card we want to sort                                          *
*                                                                                               *
*                                                                                               *
* Output parameters                                                                             *
* ====================                                                                          *
* returns nothing                                                                               *
*                                                                                               *
*                                                                                               *
*                                                                                               *
*************************************************************************************************
*/
void sortReserve(vector<Card> &reserve);

#endif //PROJECT_CARD_GAME_GAME_H














































































































































/*

 ⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆
⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿
⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀
⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉



 ⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆
⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿
⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀
⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉

 ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠀⣀⣀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⠛⠀⠂⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠋⠉⠁⠀⡄⠀⠉⠉⠛⠿⢿⣿⣿⡋⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠛⠉⠁⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠈⠉⠛⠦⡀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠛⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⠿⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠐⠚⠛⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣶⣶⣦⣄⡀⠀⠀⠀⠈⠀⠈⠙⠛⠛⠻⣿⣿⣿⣿
⣿⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠐⠒⠒⠒⠒⠻⣿⣿⣆⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣶⣶⡦⠀⢀⠠⠀⢀⠀⠀⢸⣿⣿⣿
⣿⣿⣿⣷⣀⣠⣤⣤⣾⣷⣶⣾⣿⣿⣿⣿⣷⣶⣶⣿⣿⡇⠀⠀⠈⠁⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣟⣫⣿⠗⠋⢀⣼⣿⣴⣴⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢁⣠⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⣤⡀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠀⢀⣾⣿⣷⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⢀⣿⣿⣿⣿⡆⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⣾⣿⣿⣿⣿⣿⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣄⡀⠀⠈⠻⣿⣿⣿⣿⣇⠀⠀⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⠀⠀⣿⣿⣿⣿⣿⡀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⣼⣿⣿⣿⣿⣿⡇⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣀⣀⣼⣿⣿⣿⣿⣿⣿⡇⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿

 ⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆
⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿
⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀
⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉

 ⢀⡴⠑⡄⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠸⡇⠀⠿⡀⠀⠀⠀⣀⡴⢿⣿⣿⣿⣿⣿⣿⣿⣷⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠑⢄⣠⠾⠁⣀⣄⡈⠙⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⡀⠁⠀⠀⠈⠙⠛⠂⠈⣿⣿⣿⣿⣿⠿⡿⢿⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⡾⣁⣀⠀⠴⠂⠙⣗⡀⠀⢻⣿⣿⠭⢤⣴⣦⣤⣹⠀⠀⠀⢀⢴⣶⣆
⠀⠀⢀⣾⣿⣿⣿⣷⣮⣽⣾⣿⣥⣴⣿⣿⡿⢂⠔⢚⡿⢿⣿⣦⣴⣾⠁⠸⣼⡿
⠀⢀⡞⠁⠙⠻⠿⠟⠉⠀⠛⢹⣿⣿⣿⣿⣿⣌⢤⣼⣿⣾⣿⡟⠉⠀⠀⠀⠀⠀
⠀⣾⣷⣶⠇⠀⠀⣤⣄⣀⡀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠉⠈⠉⠀⠀⢦⡈⢻⣿⣿⣿⣶⣶⣶⣶⣤⣽⡹⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠉⠲⣽⡻⢿⣿⣿⣿⣿⣿⣿⣷⣜⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣷⣶⣮⣭⣽⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⣀⣀⣈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠻⠿⠿⠿⠿⠛⠉

 */
