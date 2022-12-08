#include <vector>
#include <iostream>
#include "Game.h"

using namespace std;


Game::Game() {
    _reserve={};
    _player1("name", 0, cards);
    _player2("name", 0, cards);
}

Game::Game(vector<Card> reserve, Player player1, Player player2) {
    _reserve = reserve;
    _player1 = player1;
    _player2 = player2;
}

bool Game::ended(Player & winner){
    if (0 == winner.GetPrestige()) ///demander clarification au prof question 3 classe Jeu
    {
        return true;
    }
}
