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
    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function creates a new Player object with default values for its member variables.       *
    * The player's name is set to "Yugi", their prestige is set to 25, and their deck is            *
    * initialized to contain the indices 0, 1, 2, 3, and 4.                                         *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return A new Player object with default values for its attributes.                           *
    *                                                                                               *
    *************************************************************************************************
    */
    Player();

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function creates a new Player object with the given values for its member variables.     *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param name The name of the player.                                                           *
    * @param prestige The prestige of the player.                                                   *
    * @param deck The deck of the player, represented as a vector of indices in the game's reserve. *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return A new Player object with given values for its attributes.                             *
    *                                                                                               *
    *************************************************************************************************
    */
    Player(const string &name, int prestige, const vector<int> &deck);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function returns the name of the player.                                                 *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return The name of the player.                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    string GetName() const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function returns the number of prestige points of the player.                            *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return The number of prestige points of the player.                                          *
    *                                                                                               *
    *************************************************************************************************
    */
    int GetPrestige() const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function displays the name, prestige points, and number of cards left in the             *
    * player's deck.                                                                                *
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
    void display() const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function fills the player's deck with indices from 0 to 19.                              *
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
    void init();

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function returns a boolean value indicating whether the player has at least one card     *
    * left in their deck.                                                                           *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return True if the player has at least one card left in their deck, False otherwise.         *
    *                                                                                               *
    *************************************************************************************************
    */
    bool enoughCards() const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function returns a boolean value indicating whether the player has at least one prestige *
    * point.                                                                                        *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return True if the player has at least one prestige point, False otherwise.                  *
    *                                                                                               *
    *************************************************************************************************
    */
    bool enoughPrestige() const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function retrieves the last card in the player's deck and removes it from the deck.      *
    * If the player's deck is empty, an out_of_range exception is thrown.                           *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param card The retrieved card, represented as an index in the game's reserve.                *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @param card The retrieved card, represented as an index in the game's reserve.                *
    *                                                                                               *
    *************************************************************************************************
    */
    void nextCard(int &card);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function retrieves the next card from each player's deck and compares them using the     *
    * physical and magical match rules. The physical match rule compares the sum of the attack and  *
    * defense values of the two cards, and the magical match rule compares the magic values of the  *
    * two cards. The prestige points of players are updated based on the results of these           *
    * comparisons.                                                                                  *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param player The other player in the play.                                                   *
    * @param reserve The game's reserve of cards.                                                   *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    *************************************************************************************************
    */
    void playsACard(Player &player, const vector<Card> &reserve);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function shuffles the player's deck by randomly swapping the positions of the cards.     *
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
    void shuffle();

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function fills the player's deck with cards from the game's reserve, based on the given  *
    * sorting criteria. The cards are chosen in order of ranking according to the sorting criteria, *
    * starting with the highest ranked card.                                                        *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param reserve The game's reserve of cards.                                                   *
    * @param sortCriteria The sorting criteria to use for selecting the cards.                      *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    *************************************************************************************************
    */
    void fillDeckWithCriteria(const vector<Card> &reserve, Tri sortCriteria);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function allows players to manually select 20 cards from the game's reserve and add      *
    * them to their deck. Players can input the names of the cards they wish to add, and the        *
    * function will search the game's reserve for the matching cards. The search can be performed   *
    * using either a dichotomy search or a sequential search, depending on the value of the sort    *
    * parameter.                                                                                    *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param reserve The game's reserve of cards.                                                   *
    * @param sort A boolean value indicating whether to use a dichotomy search (if True) or a       *
    * sequential search (if False).                                                                 *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    *************************************************************************************************
    */
    void fillDeckManually(const vector<Card> &reserve, bool sort);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function clears the player's current deck and fills it with 20 random cards from the     *
    * game reserve.                                                                                 *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param reserve The game reserve from which to draw the random cards.                          *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * None. The function modifies the player's deck in place.                                       *
    *                                                                                               *
    *************************************************************************************************
    */
    void fillDeckRandom(const vector<Card> &reserve);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function allows the player to choose how to fill their deck of cards.                    *
    * The player can either choose to fill their deck manually by selecting individual cards from   *
    * the reserve, or they can choose to fill their deck automatically using one of several         *
    * sorting criteria.                                                                             *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param reserve A vector of Card objects representing the available cards that the player      *
    * can choose from                                                                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * None. The function modifies the player's deck in place.                                       *
    *                                                                                               *
    *************************************************************************************************
    */
    void fillDeck(const vector<Card> &reserve);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function allows the player to manually sort their deck by swapping cards in the deck.    *
    * The player is prompted to choose the indices of the cards they wish to swap,                  *
    * and the function continues to allow the player to swap cards until they indicate that         *
    * they are finished by entering -1 -1.                                                          *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param reserve The game's reserve of cards.                                                   *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * None. The function modifies the player's deck in place.                                       *
    *                                                                                               *
    *************************************************************************************************
    */
    void sortDeckManually(const vector<Card> &reserve);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function asks the player how they want to sort their deck. The player can choose to      *
    * keep their deck as is, sort the deck manually, shuffle the deck randomly, or sort the deck    *
    * according to various criteria.                                                                *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param reserve The game's reserve of cards.                                                   *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * None. The function modifies the player's deck in place.                                       *
    *                                                                                               *
    *************************************************************************************************
    */
    void chooseStrategy(const vector<Card> &reserve);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function sets the deck for an AI player based on the selected difficulty.                *
    * There are three possible strategies for each difficulty level, and one of them is chosen      *
    * randomly.                                                                                     *
    * The first strategy for easy difficulty is to fill the deck with the lowest score,             *
    * the second strategy is to fill the deck with the best Defense (if equality: magic, then       *
    * attack) in descending order, and the third strategy is to fill the deck with the lowest score *
    * with coefficient (3 * Att + Def + 2 * Mag).                                                   *
    * The first strategy for medium difficulty is to fill the deck with the best Magic              *
    * (if equality: attack, then defense) in descending order, the second strategy is to fill       *
    * the deck with the best Attack(if equality: defense, then magic) in descending order and       *
    * sort it with the best Defense (if equality: attack, then magic) in descending order,          *
    * and the third strategy is to fill the deck with the best Magic (if equality: defense,         *
    * then attack) in descending order.                                                             *
    * The first strategy for hard difficulty is to fill the deck with the best Attack (if equality: *
    * magic, then defense) in descending order and sort it with the highest score with coefficient  *
    * (3 * Att + Def + 2 * Mag), the second strategy is to fill the deck with the highest score     *
    * with coefficient (3 * Att + Def + 2 * Mag), and the third strategy is to fill the deck with   *
    * the best Attack (if equality: magic, then defense) in descending order and sort it with the   *
    * best Magic (if equality: attack, then defense) in descending order.                           *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param difficulty The selected difficulty of the AI player.                                   *
    * @param reserve The game's reserve of cards.                                                   *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * None. The function modifies the player's deck in place.                                       *
    *                                                                                               *
    *************************************************************************************************
    */
    void setAIDeck(char difficulty, const vector<Card> &reserve);

    // The following methods are not in the instructions, but we had them because they are useful many times

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Modify the prestige number of a player.                                                       *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param num The new prestige number for the player.                                            *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * None. The function modifies the player's deck in place.                                       *
    *                                                                                               *
    *************************************************************************************************
    */
    void modifyPrestige(int num);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Clear the deck of the player.                                                                 *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * None. The function modifies the player's deck in place.                                       *
    *                                                                                               *
    *************************************************************************************************
    */
    void clearDeck();

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function compares the player's deck with a given deck. It returns true if the two decks  *
    * have the same size and the same cards in the same order.                                      *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param vector The given deck to compare with the player's deck.                               *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return bool Returns true if the two decks have the same size and the same cards in the       *
    * same order, false otherwise.                                                                  *
    *                                                                                               *
    *************************************************************************************************
    */
    bool compareDeck(const vector<int> &);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Retrieves the current deck of cards for the player.                                           *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return A vector of integers representing the cards in the player's deck.                     *
    *                                                                                               *
    *************************************************************************************************
    */
    vector<int> getDeck();

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function modifies the current deck of a player with a new deck.                          *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param deck A vector of integers representing the new deck of the player.                     *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    *************************************************************************************************
    */
    void modifyDeck(const vector<int> &deck);

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Check if a player is equal to another player.                                                 *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param player The other player to compare to.                                                 *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return true if the players are equal, false otherwise.                                       *
    *                                                                                               *
    *************************************************************************************************
    */
    bool operator==(const Player &player);
};

/**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function searches the game's reserve of cards for a card with a given name. The search   *
    * can be performed using either a dichotomy search or a sequential search, depending on the     *
    * value of the sort parameter.                                                                  *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param name The name of the card to search for.                                               *
    * @param reserve The game's reserve of cards.                                                   *
    * @param sort A boolean value indicating whether to use a dichotomy search (if True) or a       *
    * sequential search (if False)                                                                  *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return True if a card with the given name was found in the game's reserve, False otherwise.  *
    *                                                                                               *
    *************************************************************************************************
    */
bool isInReserve(const string &name, const vector<Card> &reserve, bool sort);

/**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function searches a vector of strings for a given name. The search can be performed      *
    * using either a dichotomy search or a sequential search, depending on the value of the         *
    * sort parameter.                                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param name The name to search for.                                                           *
    * @param nameChosen The vector of strings to search in.                                         *
    * @param sort A boolean value indicating whether to use a dichotomy search (if True) or a       *
    * sequential search (if False).                                                                 *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return True if the given name was found in the vector, False otherwise.                      *
    *                                                                                               *
    *************************************************************************************************
    */
bool isInVector(const string &name, const vector<string> &nameChosen, bool sort);

/**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function prompts the player to enter the name of a card, and then checks that the name   *
    * is valid. The name is considered valid if it corresponds to a card in the game's reserve that *
    * has not already been selected by the player. The search for a matching card in the reserve    *
    * can be performed using either a dichotomy search or a sequential search, depending on the     *
    * value of the sort parameter.                                                                  *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param reserve The game's reserve of cards.                                                   *
    * @param nameChosen A vector of strings containing the names of the cards that have already     *
    * been selected by the player.                                                                  *
    * @param name A reference to a string where the name entered by the player will be stored.      *
    * @param ind The index of the card being selected (for display purposes only).                  *
    * @param sort A boolean value indicating whether to use a dichotomy search (if True) or a       *
    * sequential search (if False).                                                                 *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @param name A reference to a string where the name entered by the player will be stored.      *
    *                                                                                               *
    *************************************************************************************************
    */
void enterName(const vector<Card> &reserve, vector<string> &nameChosen, string &name, int ind, bool sort);

#endif //PROJECT_CARD_GAME_PLAYER_H
