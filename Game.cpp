// Project Card Game
// by Pierre
// and Samuel

#include <vector>
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
bool Game::ended(Player &winner)
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
