// Project Card Game
// by Pierre
// and Samuel

#include <vector>
#include "Game.h"
#include "Player.h"
#include "Card.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Empty constructor
Game::Game()
{
    _reserve = {};
    _player1;
    _player2;
}

// Constructor
Game::Game(const vector<Card> &reserve, Player &player1, Player &player2)
{
    _reserve = reserve;
    _player1 = player1;
    _player2 = player2;
}

// Know if the game is finished and give the winner
bool Game::ended(Player &winner) const
{
    bool finish = this->IsGameFinished();
    if (finish)
    {
        if (_player1.GetPrestige() > _player2.GetPrestige())
        {
            winner = _player1;
        }
        else
        {
            if (_player1.GetPrestige() < _player2.GetPrestige())
            {
                winner = _player2;
            }
        }
    }
    return finish;
}

// Plays one round of the game
void Game::playsARound()
{
    _player1.playsACard(_player2, _reserve);
};

// plays one round of the game
void Game::operator++()
{
    this->playsARound();
}

// return true if the game is finished
bool Game::IsGameFinished() const
{
    return !(_player1.enoughCards() && _player1.enoughPrestige() && _player2.enoughCards() &&
             _player2.enoughPrestige());
}

// Return the winner with an integer
int Game::winner()
{
    Player winner;
    if (this->ended(winner))
    {
        if (winner == _player1)
        {
            return 1;
        }
        if (winner == _player2)
        {
            return -1;
        }
    }
    return 0;
}

// Get the vector of ranks from a vector of Card with a chosen sort criteria
vector<int> vectorOfRanks(const vector<Card> &reserve, Tri sortCriteria)
{
    // Create the vector of card index
    vector<int> cards = {};
    unsigned int size = reserve.size();
    for (int i = 0; i < size; i++)
    {
        cards.push_back(i);
    }

    // Sort the vector with the expected criteria
    sortVectorOfCard(cards, sortCriteria, reserve);

    // Create the vector of ranks
    vector<int> ranks = {};
    int k;
    bool found;
    for (int i = 0; i < size; i++)
    {
        k = 0;
        found = false;
        while (k < size && !found)
        {
            if (cards[k] == i)
            {
                ranks.push_back(k);
                found = true;
            }
            k++;
        }
    }
    return ranks;
}

// Merge vectors into one vector
void mergeCard(vector<int> &deck, int start1, int end1, int end2, Tri sortCriteria, const vector<Card> &reserve)
{
    // create a temporary vector to hold the elements of the first half of the input vector
    vector<int> deck1(deck.size());

    // calculate the starting index of the second half of the input vector
    int start2 = end1 + 1;
    // initialize indices for the two halves of the input vector
    int cpt1 = start1;
    int cpt2 = start2;
    int i;

    // copy the elements of the first half of the input vector into the temporary vector
    for (i = start1; i <= end1; i++)
    {
        deck1[i - start1] = deck[i];
    }

    // iterate through the input vector from start to end
    for (i = start1; i <= end2; i++)
    {
        // if all elements of the first half have been used, break
        if (cpt1 == start2)
        {
            break; // all elements have been sorted
        }
            // if all elements of the second half have been used, add the remaining elements from the first half
        else if (cpt2 == (end2 + 1))
        {
            deck[i] = deck1[cpt1 - start1];
            cpt1++;
        }
            // if the element from the first half is greater than or equal to the element from the second half, add it to the input vector
        else if (reserve[deck1[cpt1 - start1]].compareCard(reserve[deck[cpt2]], sortCriteria))
        {
            deck[i] = deck1[cpt1 - start1];
            cpt1++;
        }
            // otherwise, add the element from the second half to the input vector
        else
        {
            deck[i] = deck[cpt2];
            cpt2++;
        }
    }
}

// recursive function to sort the input vector in descending order using merge sort
void mergeSortBisCard(vector<int> &deck, int start, int end, Tri sortCriteria, const vector<Card> &reserve)
{
    // if the start index is not the same as the end index, the list is not fully sorted
    if (start != end)
    {
        // calculate the midpoint of the list
        int mid = (end + start) / 2;
        // sort the first half of the list
        mergeSortBisCard(deck, start, mid, sortCriteria, reserve);
        // sort the second half of the list
        mergeSortBisCard(deck, mid + 1, end, sortCriteria, reserve);
        // merge the two sorted halves
        mergeCard(deck, start, mid, end, sortCriteria, reserve);
    }
}

// wrapper function to start the descending merge sort process on the input vector
void mergeSortCard(vector<int> &deck, int length, Tri sortCriteria, const vector<Card> &reserve)
{
    // if the input vector has at least one element, begin the sorting process
    if (length > 0)
    {
        // sort the entire input vector
        mergeSortBisCard(deck, 0, length - 1, sortCriteria, reserve);
    }
}

// Sort a vector of card
void sortVectorOfCard(vector<int> &deck, Tri sortCriteria, const vector<Card> &reserve)
{
    // Here we use the merge sort with a vector of card
    mergeSortCard(deck, deck.size(), sortCriteria, reserve);
}

// sort the reserve of the game
void sortReserve(vector<Card> &reserve)
{
    sort(reserve.begin(), reserve.end(),
         [] (const Card& c1, const Card& c2) { return c1.getName() < c2.getName(); });
}

void Game::fillReserve(const string &filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        throw out_of_range("Error while opening the file");
    }
    int i=0;
    string actual_line, name;
    int attack, defense, magic;
    while(!file.eof()) {
        //while (i<_reserve.size()) {
        getline(file, actual_line);
        Card c;
        c.fill(actual_line);
        _reserve.push_back(c);
    }

    sortReserve(_reserve);
    file.close();
    _reserve.pop_back();
}

// The following methods are not in the instructions, but we had them because they are useful for tests

// compare game
bool Game::compareGame(const Game &game)
{
    return this->compareReserve(game._reserve) &&
           ((_player1 == game._player1 && _player2 == game._player2) ||
            (_player1 == game._player2 && _player2 == game._player1));
}

// Modify the prestige of the player two
void Game::modifyPlayerTwoPrestige(int num)
{
    _player2.modifyPrestige(num);
}

// Modify the prestige of the player two
void Game::modifyPlayerOnePrestige(int num)
{
    _player1.modifyPrestige(num);
}

// Clear the deck of the player Two
void Game::clearPlayerTwoDeck()
{
    _player2.clearDeck();
}

// Compare the reserve of card
bool Game::compareReserve(const vector<Card> &vector) const
{
    bool ok = true;
    int size = _reserve.size();
    if (vector.size() != size)
    {
        ok = false;
    }
    if (ok)
    {
        int i = 0;
        while (ok && i < size)
        {
            if (!(_reserve[i] == vector[i]))
            {
                ok = false;
            }
            i++;
        }
    }
    return ok;
}

// Get the player 1
Player Game::GetPlayerOne()
{
    return _player1;
}

// Get the player 2
Player Game::GetPlayerTwo()
{
    return _player2;
}

// Get the reserve of the game
vector <Card> Game::getReserve()
{
    return _reserve;
}

// Get the size of the reserve
int Game::getSizeReserve()
{
    return _reserve.size();
}

// destructor
//Game::~Game()=default;
