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
   *                                                                                               *
   * Description :                                                                                 *
   * ===========                                                                                   *
   * Game constructor                                                                              *
   *                                                                                               *
   *                                                                                               *
   *************************************************************************************************
   */
    bool ended(Player &winner);
};

#endif //PROJECT_CARD_GAME_GAME_H

