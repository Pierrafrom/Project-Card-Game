// Project Card Game
// by Pierre
// and Samuel

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Game.h"
#include "Player.h"
#include "Card.h"

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
    bool finish = !_player1.enoughCards() || !_player2.enoughCards() || _player1.GetPrestige() <= 0
                  || _player2.GetPrestige() <= 0;
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
            else
            {
                throw out_of_range("Draw : no winner");
            }
        }
    }
    return finish;
}

int Game::winner()
{
    Player winner;
    if (this->ended(winner)){
        if (winner==_player1)
        {
            return 1;
        }
        if (winner==_player2)
        {
            return -1;
        }
    }
    return 0;
}

// plays one round of the game
void Game::operator++()
{
    _player1.playsACard(_player2, _reserve);
}

// return true if the game is finished
bool Game::IsGameFinished() const
{
    return !(_player1.enoughCards() && _player1.enoughPrestige() && _player2.enoughCards() && _player2.enoughPrestige());
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

//useful for tests only
void Game::getReserve() {
    for(int i = 0;i<_reserve.size();i++){
        _reserve[i].displayShort();
        cout<<endl;
    }
}

bool compareCards(Card obj1, Card obj2)  {
    return obj1.getName() < obj2.getName();
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
            /*
            //stringstream stream(actual_line);
            string value;

            getline(file, value, ',');
            istringstream(value) >> name;

            getline(file, value, ',');
            istringstream(value) >> attack;

            getline(file, value, ',');
            istringstream(value) >> defense;

            getline(file, value);
            istringstream(value) >> magic;

            file >> ws;

            _reserve.push_back()
            _reserve[i].changeName(name);
            _reserve[i].changeAttack(attack);
            _reserve[i].changeDefense(defense);
            _reserve[i].changeMagic(magic);

            i++;
    */
    }

    sort(_reserve);
    file.close();
    _reserve.pop_back();
}

void Game::sort(vector<Card> &reserve) {
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = i+1; j < reserve.size(); j++) {
            if (compareCards(reserve[j], reserve[i])) {
                swap(reserve[i], reserve[j]);
            }
        }
    }
}




