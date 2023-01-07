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

    /**
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
    * @return 1 if player 1 won the game and -1 if player 2 won and 0 if it's a draw                *
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

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Clear the player's two deck                                                                   *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * (none)                                                                                        *
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
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param game an object of Game different from the actual game                                  *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @returns a boolean, true if the games are the same and false if they ain't                    *
    *                                                                                               *
    *************************************************************************************************
    */
    bool compareGame(const Game &game);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Get the first player of the game.                                                             *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return The first player of the game.                                                         *
    *                                                                                               *
    *************************************************************************************************
    */
    Player GetPlayerOne();

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Get the second player of the game.                                                            *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return The second player of the game.                                                        *
    *                                                                                               *
    *************************************************************************************************
    */
    Player GetPlayerTwo();

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Get the reserve of cards for the game.                                                        *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return A vector of Card objects representing the reserve of cards for the game.             *
    *                                                                                               *
    *************************************************************************************************
    */
    vector<Card> getReserve();

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Reads the card data from a file and stores them in the reserve of the game object.            *
    * The cards are sorted in alphabetical order based on their name.                               *
    *                                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                    ¯\_(¨_¨)_/¯                                           *
    * @param filename which is the file name      | |                                               *
    *                                            /   \                                              *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @throws out_of_range If the file cannot be opened                                             *
    *                                                                                               *
    *************************************************************************************************
    **/
    void fillReserve(const string &filename);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Get the size of the game's reserve                                                            *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * no input parameters                                                                           *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return an int representing the reserve's size                                                *
    *                                                                                               *
    *************************************************************************************************
    */
    int getSizeReserve();

};

/**
*************************************************************************************************
*                                                                                               *
* Description :                                                                                 *
* ============                                                                                  *
* This function takes a vector of cards and a sorting criteria, and returns a vector of ranks   *
* corresponding to the sorted order of the cards.                                               *
* The rank of a card is its position in the original unsorted vector of cards.                  *
*                                                                                               *
* Input parameters                                                                              *
* ====================                                                                          *
* @param reserve The vector of cards to be sorted and ranked                                    *
* @param sortCriteria The sorting criteria to be used. This is a function that takes two Card   *
* objects and returns a boolean indicating which one should come first in the sorted vector.    *
*                                                                                               *
* Output parameters                                                                             *
* ====================                                                                          *
* @return A vector of integers representing the ranks of the cards in the sorted order.         *
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
* Input parameters                                                                              *
* ====================                                                                          *
* @param deck -> a reference to the vector of integers that will be sorted                      *
* @param start1 -> an integer representing the start index of the first half of the vector      *
* @param end1 -> an integer representing the end index of the first half of the vector          *
* @param end2 -> an integer representing the end index of the second half of the vector         *
* @param sortcriteria -> a Tri type value representing the sorting criterion                    *
* @param reserve -> a constant reference to a vector of Card objects called                     *
*                                                                                               *
* Output parameters                                                                             *
* ====================                                                                          *
* returns nothing                                                                               *
*                                                                                               *
*************************************************************************************************
*/
void mergeCard(vector<int> &deck, int start1, int end1, int end2, Tri sortcriteria, const vector<Card> &reserve);

/**
*************************************************************************************************
*                                                                                               *
* Description                                                                                   *
* ===========                                                                                   *
* recursive implementation of mergeCard()                                                       *
*                                                                                               *
* Input parameters                                                                              *
* ====================                                                                          *
* @param deck -> a reference to the vector of integers that will be sorted                      *
* @param start -> an integer representing the start index of the first half of the vector       *
* @param end -> an integer representing the end index of the first half of the vector           *
* @param sortcriteria -> a Tri type value representing the sorting criterion                    *
* @param reserve -> a constant reference to a vector of Card objects called                     *
*                                                                                               *
* Output parameters                                                                             *
* ====================                                                                          *
* returns nothing                                                                               *
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
* Input parameters                                                                              *
* ====================                                                                          *
* @param deck -> a reference to the vector of integers that will be sorted                      *
* @param length -> an integer representing the length of the vector (length)                    *
* @param sortcriteria -> a Tri type value representing the sorting criterion                    *
* @param reserve -> a constant reference to a vector of Card objects called                     *
*                                                                                               *
* Output parameters                                                                             *
* ====================                                                                          *
* returns nothing                                                                               *
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
* Input parameters                                                                              *
* ====================                                                                          *
* @param deck -> a reference to the vector of integers that will be sorted                      *
* @param sortcriteria -> a Tri type value representing the sorting criterion                    *
* @param reserve -> a constant reference to a vector of Card objects called                     *
*                                                                                               *
* Output parameters                                                                             *
* ====================                                                                          *
* returns nothing                                                                               *
*                                                                                               *
*************************************************************************************************
*/
void sortVectorOfCard(vector<int> &deck, Tri sortCriteria, const vector<Card> &reserve);

/**
*************************************************************************************************
*                                                                                               *
* Description                                                                                   *
* ===========                                                                                   *
* sorts the reserve of the targeted game in alphabetic order                                    *
*                                                                                               *
* Input parameters                                                                              *
* ====================                                                                          *
* @param reserve -> the vector of Card we want to sort                                          *
*                                                                                               *
* Output parameters                                                                             *
* ====================                                                                          *
* returns nothing                                                                               *
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
*/
