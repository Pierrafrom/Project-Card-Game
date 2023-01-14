// Project Card Game
// by Pierre
// and Samuel

#include "Tests.h"
#include <iostream>
#include <vector>
#include "Game.h"
#include "Card.h"
#include "Player.h"
#include <string>

//#define TEST ON

using namespace std;

#ifdef TEST
int main()
{
    testAll();
    return 0;
}
#endif

#ifndef TEST

int main()
{
    try
    {
        // The functions to fill the reserve with a data file are in the class Game,
        // So we create a temporary Game to initialize a reserve;
        Player tempP1;
        Player tempP2;
        Game tempGame({}, tempP1, tempP2);

        // Here we fill the reserve with the full path defined with constant in the Card.h file
        tempGame.fillReserve((PATH + FILENAME));

        // Now, we have a reserve initialised
        vector<Card> reserve = tempGame.getReserve();

        // Variable Declaration
        char answer;
        string answer1;
        string namePlayer1, namePlayer2;

        do
        {
            // Choose game mode
            cout << "Choose your mode (1 or 2)" << endl;
            cout << "1. One player" << endl;
            cout << "2. Two players" << endl;
            cin >> answer;
            while (answer != '1' && answer != '2')
            {
                cout << "Please, enter a correct value (1 or 2) :" << endl;
                cin >> answer;
            }

            cout << "Here are the rules of the game :\n"
                    "- The game is basically player versus player game but you can be alone and face a bot.\n"
                    "- Each player has a pile of 20 cards which they took from the same reserve.\n"
                    "- Each card has a name, an attack, a defense and a magic value.\n"
                    "- Your goal is to reduce the prestige poins of your enemy and to protect yours.\n"
                    "- Each player sorts his deck according to his strategy, then plays the card on top of his deck each turn.\n"
                 << endl;

            cout << "The winner will be the first to take down the enemy or the the one who has the most prestige "
                    "points when one of the two players has no more cards left !" << endl << endl;

            cout << "Choose your strategy and your cards wisely knowing that :\n"
                    "- The player having the biggest amount of attack (physical damages) will decrease the prestige of "
                    "his opponent by the difference between his attack value and the defense value of the other player\n"
                    "- If both of the players have the same amount of attack, no harm to any players prestige will be caused\n"
                    "- If the defender has more defense than the attack value of the other player, the defender does "
                    "not gain any prestige points\n"
                    "- The player having the biggest amount of magical power will reduce the prestige of his enemy by "
                    "the difference of the magical power of value of the two player " << endl << endl;

            if (answer == '1')
            {
                // Game for 1 player

                // Create the player 1
                cout << "Enter your name : ";
                cin.ignore(256, '\n');
                getline(cin, namePlayer1);
                Player Player1(namePlayer1, 25, {});
                Player1.init(); // We fill his deck, we will modify it later;

                // Create the player 2
                namePlayer2 = "Bonclay";
                if (namePlayer1 == namePlayer2) // the name of the AI shouldn't be the same as the player
                {
                    namePlayer2 = "Mr 2";
                }
                Player Player2(namePlayer2, 25, {});
                Player2.init(); // We fill his deck with numbers from à to 19, we will modify it later;

                // The player choose how he wants to fill his deck
                Player1.fillDeck(reserve);

                // The player choose how he wants to sort his deck
                Player1.chooseStrategy(reserve);

                // Choose difficulty of AI
                cout << "Choose the difficulty of the AI\n"
                        "1. Easy\n"
                        "2. Medium\n"
                        "3. Hard\n"
                        "Enter 1 2 or 3 :\n";
                cin >> answer;
                while (answer != '1' && answer != '2' && answer != '3')
                {
                    cout << "Please, enter a correct value (1, 2 or 3) :" << endl;
                    cin >> answer;
                }
                // We create the deck of the AI with the difficulty chosen
                Player2.setAIDeck(answer, reserve);

                // Create the game with the reserve and the two players
                Game game(reserve, Player1, Player2);

                // We start the game, and we continue as long as one of the two players has not lost
                int i = 1;
                while (!game.IsGameFinished())
                {
                    cout << "#################### Round " << i << " #####################" << endl;
                    // Here we use the display long because we print only two cards
                    cout << namePlayer1 << " has " << game.GetPlayerOne().GetPrestige()
                         << " prestiges left and plays the card : " << endl;
                    reserve[game.GetPlayerOne().getDeck()[game.GetPlayerOne().getDeck().size() - 1]].displayLong();

                    cout << namePlayer2 << " has " << game.GetPlayerTwo().GetPrestige()
                         << " prestiges left and plays the card : " << endl;
                    reserve[game.GetPlayerTwo().getDeck()[game.GetPlayerTwo().getDeck().size() - 1]].displayLong();
                    cout << endl;
                    ++game;
                    i++;
                }

                // Now, we print the name of the winner
                if (game.winner() == 1)
                {
                    cout << namePlayer1 << " is the winner. \nCongratulations!!!" << endl;
                }
                else
                {
                    if (game.winner() == -1)
                    {
                        cout << namePlayer2 << " is the winner. \nCongratulations!!!" << endl;
                    }
                    else
                    {
                        cout << "The game is a draw, good game!" << endl;
                    }
                }
            }
            else
            {
                // Game for 2 players

                // Create player 1
                cout << "Enter the name of the player 1 : ";
                cin.ignore(256, '\n');
                getline(cin, namePlayer1);
                Player Player1(namePlayer1, 25, {});
                Player1.init(); // We fill his deck, we will modify it later;

                // Create player 2
                cout << "Enter the name of the player 2 : ";
                cin.ignore(256, '\n');
                getline(cin, namePlayer2);
                if (namePlayer1 == namePlayer2) // the name of the two players should be different
                {
                    namePlayer2.push_back('(');
                    namePlayer2.push_back('2');
                    namePlayer2.push_back(')');
                }
                Player Player2(namePlayer2, 25, {});
                Player2.init(); // We fill his deck, we will modify it later;

                // Players choose how they want to fill their deck
                Player1.fillDeck(reserve);
                Player2.fillDeck(reserve);

                // Players choose how they want to sort their deck
                Player1.chooseStrategy(reserve);
                Player2.chooseStrategy(reserve);

                // Create the game with the reserve and the two players
                Game game(reserve, Player1, Player2);

                // We start the game, and we continue as long as one of the two players has not lost
                int i = 1;
                while (!game.IsGameFinished())
                {
                    cout << "#################### Round " << i << " #####################" << endl;
                    // Here we use the display long because we print only two cards
                    cout << namePlayer1 << " has " << game.GetPlayerOne().GetPrestige()
                         << " prestiges left and plays the card : " << endl;
                    reserve[game.GetPlayerOne().getDeck()[game.GetPlayerOne().getDeck().size() - 1]].displayLong();

                    cout << namePlayer2 << " has " << game.GetPlayerTwo().GetPrestige()
                         << " prestiges left and plays the card : " << endl;
                    reserve[game.GetPlayerTwo().getDeck()[game.GetPlayerTwo().getDeck().size() - 1]].displayLong();
                    cout << endl;
                    ++game;
                    i++;
                }
                // Now, we print the name of the winner
                if (game.winner() == 1)
                {
                    cout << namePlayer1 << " is the winner. \nCongratulations!!!" << endl;
                }
                else
                {
                    if (game.winner() == -1)
                    {
                        cout << namePlayer2 << " is the winner. \nCongratulations!!!" << endl;
                    }
                    else
                    {
                        cout << "The game is a draw, good game!" << endl;
                    }
                }
            }

            // Play another game or not
            cout << "Do you want to play again? (Y or N)" << endl;
            cin >> answer1;
            unsigned int sizeAns = answer1.size();
            for (int i = 0; i < sizeAns; ++i)
            {
                answer1[i] = tolower(answer1[i]);
            }
            while (answer1 != "y" && answer1 != "n" && answer1 != "easteregg")
            {
                cout << "Please, enter a correct value (Y or N) :" << endl;
                cin >> answer1;
                sizeAns = answer1.size();
                for (int i = 0; i < sizeAns; ++i)
                {
                    answer1[i] = tolower(answer1[i]);
                }
            }

        } while (answer1 == "y");
        if (answer1 == "easteregg")
        {
            cout << "######################################################################################\n"
                    "#                                                                                    # \n"
                    "#                            ,.--------._                                            #\n"
                    "#                           /            ''.                                         #\n"
                    "#                         ,'                \\     |\"\\                /\\          /\\  #\n"
                    "#                /\"|     /                   \\    |__\"              ( \\\\        // ) #\n"
                    "#               \"_\"|    /           z#####z   \\  //                  \\ \\\\      // /  #\n"
                    "#                 \\\\  #####        ##------\".  \\//                    \\_\\\\||||//_/   #\n"
                    "#                  \\\\/-----\\     /          \".  \\                      \\/ _  _ \\     #\n"
                    "#                   \\|      \\   |   ,,--..       \\                    \\/|(O)(O)|     #\n"
                    "#                   | ,.--._ \\  (  | ##   \\)      \\                  \\/ |      |     #\n"
                    "#                   |(  ##  )/   \\ `-....-//       |///////////////_\\/  \\      /     #\n"
                    "#                     '--'.\"      \\                \\              //     |____|      #\n"
                    "#                  /'    /         ) --.            \\            ||     /      \\     #\n"
                    "#               ,..|     \\.________/    `-..         \\   \\       \\|     \\ 0  0 /     #\n"
                    "#            _,##/ |   ,/   /   \\           \\         \\   \\       U    / \\_//_/      #\n"
                    "#          :###.-  |  ,/   /     \\        /' \"\"\\      .\\        (     /              #\n"
                    "#         /####|   |   (.___________,---',/    |       |\\=._____|  |_/               #\n"
                    "#        /#####|   |     \\__|__|__|__|_,/             |####\\    |  ||                #\n"
                    "#       /######\\   \\      \\__________/                /#####|   \\  ||                #\n"
                    "#      /|#######`. `\\                                /#######\\   | ||                #\n"
                    "#     /++\\#########\\  \\                      _,'    _/#########\\ | ||                #\n"
                    "#    /++++|#########|  \\      .---..       ,/      ,'##########.\\|_||                #\n"
                    "#   //++++|#########\\.  \\.              ,-/      ,'########,+++++\\\\_\\\\               #\n"
                    "#  /++++++|##########\\.   '._        _,/       ,'######,''++++++++\\                  #\n"
                    "# |+++++++|###########|       -----.\"        _'#######' +++++++++++\\                 #\n"
                    "# |+++++++|############\\.     \\\\     //      /#######/++++ S@yaN +++\\                #\n"
                    "#      ________________________\\\\___//______________________________________         #\n"
                    "#           _______ _                 _                 __                           #\n"
                    "#          |__   __| |               | |              / _|                           #\n"
                    "#             | |  | |__    __ _ _ __| | _____       | |_ ___  _ __                  #\n"
                    "#             | |  | '_ \\ / _` | '_ \\| |/ / __|      |  _/ _ \\| '__|                 #\n"
                    "#             | |  | | | | (_| | | | |   <\\__ \\      | || (_) | |                    #\n"
                    "#             |_|  |_| |_|\\__,_|_| |_|_|\\_\\___/      |_| \\___/|_|                    #\n"
                    "#                                                                                    #\n"
                    "#                   _____  _             _               _ _ _                       #\n"
                    "#                  |  __ \\| |           (_)             | | | |                      #\n"
                    "#                  | |__) | | __ _ _   _ _ _ __   __ _  | | | |                      #\n"
                    "#                  |  ___/| |/ _` | | | | | '_ \\ / _` | | | | |                      #\n"
                    "#                  | |    | | (_| | |_| | | | | | (_| | |_|_|_|                      #\n"
                    "#                  |_|    |_|\\__,_|\\__, |_|_| |_|\\__, | (_|_|_)                      #\n"
                    "#                                   __/ |         __/ |                              #\n"
                    "#                                  |___/         |___/                               #\n"
                    "######################################################################################" << endl;
        }
    }
    catch (out_of_range &e)
    {
        // We can have 3 different exception
        // 1) the file couldn't be opened
        // 2) there is less than 20 cards in the reserve
        // 3) a player doesn't have enough cards when he is supposed to play
        // The third exception was in the instructions, but we can't reach it
        // because the second exception always appear before
        cerr << "Out of range exception : " << e.what() << endl;
    }
    return 0;
}

#endif
