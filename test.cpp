// Project Card Game
// by Pierre
// and Samuel

#include "test.h"
#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Game.h"
#include <vector>
#include <sstream>

using namespace std;

void testAll()
{
    cout << "############################ Start Testing ###################################################" << endl;
    // Card
    cout << "----------------- Card ----------------------------------" << endl;
    testCardConstructors();
    testDisplayLongMethod();
    testDisplayShortMethod();
    testPhysicalDamageMethod();
    testMagicalDamage();
    testCardEqualityOperator();
    test_fill();
    // Player
    cout << "----------------- Player --------------------------------" << endl;
    testConstructorsPlayer();
    testGettersMethods();
    testDisplayMethod();
    testInitMethod();
    testShuffleMethod();
    testEnoughCardsMethod();
    testEnoughPrestigeMethod();
    testNextCardMethod();
    testPlaysACardMethod();
    //testletChooseMethod();
    // Game
    cout << "----------------- Game ----------------------------------" << endl;
    testConstructorsGame();
    testEndedMethod();
    testIsGameFinishedMethod();
    testIncrementOperator();
    testFillReserve();
    cout << "############################ End Testing #####################################################" << endl;
}

// ################### Card ############################################
void testCardConstructors()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Test the default constructor
    Card card1;
    if (card1.getName() != "bare hands" || card1.getAttack() != 1 || card1.getDefense() != 1 || card1.getMagic() != 0)
    {
        ok = false;
        cout << "Error: The default constructor is not working correctly" << endl;
    }

    // Test the full constructor
    Card card2("Card 2", 1, 2, 3);
    if (card2.getName() != "Card 2" || card2.getAttack() != 1 || card2.getDefense() != 2 || card2.getMagic() != 3)
    {
        ok = false;
        cout << "Error: The full constructor is not working correctly" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "Constructors : OK" << endl;
    }
}

void testDisplayLongMethod()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create a card with a name, attack, defense, and magic
    Card card("Gol d Roger", 10, 8, 10);

    // Test the displayLong method by capturing its output
    stringstream output;
    streambuf *old = cout.rdbuf(output.rdbuf());
    card.displayLong();
    cout.rdbuf(old);

    // Check that the output is as expected
    string expectedOutput = "****************************\nname: Gol d Roger\nattack: 10\ndefense: 8\nmagic: 10\n****************************\n";
    if (output.str() != expectedOutput)
    {
        ok = false;
        cout << "Error: The output of the displayLong method is incorrect" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "DisplayLong method : OK" << endl;
    }
}

void testDisplayShortMethod()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create a card with a name, attack, defense, and magic
    Card card("Gol d Roger", 10, 8, 10);

    // Test the displayShort method by capturing its output
    stringstream output;
    streambuf *old = cout.rdbuf(output.rdbuf());
    cout << card;
    cout.rdbuf(old);

    // Check that the output is as expected
    string expectedOutput = "Gol d Roger [ 10 ; 8 ; 10 ] \n";
    if (output.str() != expectedOutput)
    {
        ok = false;
        cout << "Error: The output of the displayShort method is incorrect" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "DisplayShort method : OK" << endl;
    }
}

void testPhysicalDamageMethod()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create some cards
    Card C1("Gol d Roger", 10, 8, 10);
    Card C2("nami", 5, 5, 15);
    Card C3("Edward Newgate", 10, 8, 10);
    Card C4("Joz", 4, 15, 0);

    // Test for a win (low defense)
    if (C1 + C2 != -5)
    {
        ok = false;
        cout << "Error : Result for a win with a low defense incorrect" << endl;
    }

    // Test for a win (high defense)
    if (C1 + C4 != 0)
    {
        ok = false;
        cout << "Error : Result for a win with a high defense incorrect" << endl;
    }

    // Test for a loss (low defense)
    if (C2 + C1 != 5)
    {
        ok = false;
        cout << "Error : Result for a loss with a low defense incorrect" << endl;
    }

    // Test for a loss (high defense)
    if (C4 + C2 != 0)
    {
        ok = false;
        cout << "Error : Result for a loss with a high defense incorrect" << endl;
    }

    // Test for a draw
    if (C1 + C3 != 0)
    {
        ok = false;
        cout << "Error : Result for a draw incorrect" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "PhysicalDamage method : OK" << endl;
    }
}

void testMagicalDamage()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create some cards
    Card C1("Gol d Roger", 10, 8, 10);
    Card C2("nami", 5, 5, 15);
    Card C3("Edward Newgate", 10, 8, 10);
    Card C4("Joz", 4, 15, 0);

    // Test for a win
    if ((C1 ^ C4) != -10)
    {
        ok = false;
        cout << "Error : Result for a win incorrect" << endl;
    }

    // Test for a loss
    if ((C1 ^ C2) != 5)
    {
        ok = false;
        cout << "Error : Result for a loss incorrect" << endl;
    }

    // Test for a draw
    if ((C1 ^ C3) != 0)
    {
        ok = false;
        cout << "Error : Result for a draw incorrect" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "MagicalDamage method : OK" << endl;
    }
}


void testCardEqualityOperator()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create two cards with the same values
    Card card1("Card 1", 1, 2, 3);
    Card card2("Card 1", 1, 2, 3);

    // Test the equality operator
    if (!(card1 == card2))
    {
        ok = false;
        cout << "Error: The equality operator is not working correctly" << endl;
    }

    // Create two cards with different values
    Card card3("Card 3", 3, 4, 5);
    Card card4("Card 4", 3, 4, 5);

    // Test the equality operator again
    if (card3 == card4)
    {
        ok = false;
        cout << "Error: The equality operator is not working correctly" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "Equality operator : OK" << endl;
    }
}

void test_fill(){
    string test_data = "Lightning Bolt,8,0,18";
    Card card1;
    card1.fill(test_data);
    if (card1.getName() != "Lightning Bolt") {
        cout << "Error: incorrect name" << endl;
    }
    if (card1.getAttack() != 8) {
        cout << "Error: incorrect attack" << endl;
    }
    if (card1.getDefense() != 0) {
        cout << "Error: incorrect defense" << endl;
    }
    if (card1.getMagic() != 18) {
        cout << "Error: incorrect magic" << endl;
    }
    else{
        cout<<"Fill method : OK"<<endl;
    }

}


// ################### Player ##########################################
void testConstructorsPlayer()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create two players with different constructors
    Player player1;
    Player player2("Player 2", 5, {4, 5, 6, 7});

    // test player 1
    if (player1.GetName() != "Yugi" || player1.GetPrestige() != 25 || !player1.compareDeck({0, 1, 2, 3, 4}))
    {
        ok = false;
        cout << "Error: The object 'player1' is not built with the correct values" << endl;
    }

    // test player 2
    if (player2.GetName() != "Player 2" || player2.GetPrestige() != 5 || !player2.compareDeck({4, 5, 6, 7}))
    {
        ok = false;
        cout << "Error: The object 'player2' is not built with the correct values" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "Constructors : OK" << endl;
    }
}

void testGettersMethods()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create a player with a name and prestige
    Player player("Player 1", 3, {});

    // Test the GetName method
    if (player.GetName() != "Player 1")
    {
        ok = false;
        cout << "Error: The name returned by GetName is incorrect" << endl;
    }

    // Test the GetPrestige method
    if (player.GetPrestige() != 3)
    {
        ok = false;
        cout << "Error: The prestige returned by GetPrestige is incorrect" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "Getters : OK" << endl;
    }
}

void testDisplayMethod()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create a player with a name, prestige, and deck
    Player player("Player 1", 3, {1, 2, 3});

    // Test the display method by capturing its output
    stringstream output;
    streambuf *old = cout.rdbuf(output.rdbuf());
    player.display();
    cout.rdbuf(old);

    // Check that the output is as expected
    string expectedOutput = "The player Player 1 has 3 prestige points, only 3 left in his pile \n";
    if (output.str() != expectedOutput)
    {
        ok = false;
        cout << "Error: The output of the display method is incorrect" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "Display method : OK" << endl;
    }
}

void testInitMethod()
{
    // Create the boolean for the result of the test
    bool ok = true;

    Player player("Player 1", 3, {});
    // Test the init method
    player.init();

    // Check that the player's deck contains the numbers 0 through 19
    for (int i = 0; i < 20; i++)
    {
        if (player.getDeck()[i] != i)
        {
            ok = false;
            cout << "Error: The number " << i << " is not in the player's deck" << endl;
        }
    }

    // Result of the test
    if (ok)
    {
        cout << "Init method : OK" << endl;
    }

}

void testShuffleMethod(){
    cout<<"testing the method shuffle :"<<endl;
    // Create a player with a name and prestige
    Player player("Player 1", 3, {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19});
    player.shuffle();
    vector<int> deck;
    deck=player.getDeck();
    cout<<endl;
    for(int i : deck){
        cout<<deck[i]<<", ";
    }

    cout<<endl;
}

void testEnoughCardsMethod()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create a player with a non-empty deck
    Player player("Player 1", 3, {1, 2, 3});

    // The player should have enough cards
    if (!player.enoughCards())
    {
        ok = false;
        cout << "Error: The player should have enough cards" << endl;
    }

    // Clear the player's deck
    player.modifyDeck({});

    // The player should not have enough cards
    if (player.enoughCards())
    {
        ok = false;
        cout << "Error: The player should not have enough cards" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "EnoughCards method : OK" << endl;
    }
}

void testEnoughPrestigeMethod()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create a player with non-zero prestige
    Player player("Player 1", 3, {});

    // The player should have enough prestige
    if (!player.enoughPrestige())
    {
        ok = false;
        cout << "Error: The player should have enough prestige" << endl;
    }

    // Set the player's prestige to 0
    player.modifyPrestige(0);

    // The player should not have enough prestige
    if (player.enoughPrestige())
    {
        ok = false;
        cout << "Error: The player should not have enough prestige" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "EnoughPrestige method : OK" << endl;
    }
}

void testNextCardMethod()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create a player with a non-empty deck
    Player player("Player 1", 3, {1, 2, 3});

    // Test the nextCard method
    try
    {
        int card;
        player.nextCard(card);
        if (card != 3)
        {
            ok = false;
            cout << "Error: The returned card is incorrect" << endl;
        }
        if (player.getDeck().size() != 2)
        {
            ok = false;
            cout << "Error: The size of the deck is incorrect" << endl;
        }
    }
    catch (const out_of_range &e)
    {
        ok = false;
        cout << "Error: Unexpected out-of-range exception" << endl;
    }

    // Clear the player's deck
    player.clearDeck();

    // Test the nextCard method again
    try
    {
        int card;
        player.nextCard(card);
        ok = false;
        cout << "Error: Expected out-of-range exception" << endl;
    }
    catch (const out_of_range &e)
    {
        // Check the exception message
        if (e.what() != string("no more cards left !"))
        {
            ok = false;
            cout << "Error: The out-of-range exception message is incorrect" << endl;
        }
    }

    // Result of the test
    if (ok)
    {
        cout << "NextCard method : OK" << endl;
    }
}

void testPlaysACardMethod()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create two players with different deck
    Player player1("player1", 25, {2, 1, 0});
    Player player2("player2", 25, {2, 4, 3});

    // Create the reserve of cards
    vector<Card> reserve = {{"Gol d Roger", 15, 13, 15},
                            {"Chopper",     3,  6,  2},
                            {"Usopp",       3,  2,  0},
                            {"Ace",         8,  8,  12},
                            {"Shanks",      10, 10, 15},};

    // Test for a physical and magical win
    player1.playsACard(player2, reserve);
    if (player1.GetPrestige() != 25 && player2.GetPrestige() != 15)
    {
        ok = false;
        cout << "Error: The player1's number of prestige is " << player1.GetPrestige()
             << "and it should be equal to 25, the player2's number of prestige is " << player2.GetPrestige() <<
             "and it should be equal to 15" << endl;
    }

    // Test for a physical and magical lose
    player1.playsACard(player2, reserve);
    if (player1.GetPrestige() != 8 && player2.GetPrestige() != 15)
    {
        ok = false;
        cout << "Error: The player1's number of prestige is " << player1.GetPrestige()
             << "and it should be equal to 8, the player2's number of prestige is " << player2.GetPrestige() <<
             "and it should be equal to 15" << endl;
    }

    // Test for a physical and magical draw
    player1.playsACard(player2, reserve);
    if (player1.GetPrestige() != 8 && player2.GetPrestige() != 15)
    {
        ok = false;
        cout << "Error: The player1's number of prestige is " << player1.GetPrestige()
             << "and it should be equal to 8, the player2's number of prestige is " << player2.GetPrestige() <<
             "and it should be equal to 15" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "PLaysACard method : OK" << endl;
    }
}

void testletChooseMethod() {
    // Create two players with empty decks
    Player player1("player1", 25, {});
    Player player2("player2", 25, {});

    // Create the reserve of cards
    Card C1("Sword",10,5,0);
    Card C2("Shield",0,10,0);
    Card C3("Staff",5,0,11);
    Card C4("Dagger",5,0,5);
    Card C5("Mace",10,0,0);
    Card C6("Armor",0,15,0);
    Card C7("Helmet",0,5,0);
    Card C8("Bow",5,0,0);
    Card C9("Arrows",7,0,0);
    Card C10("Fireball",5,0,13);
    Card C11("Lightning Bolt",8,0,18);
    Card C12("Healing Potions",0,0,10);
    Card C13("Mana Potions",0,0,15);
    Card C14("Poisoned Dagger",8,0,0);
    Card C15("Explosive Arrows",10,0,0);
    Card C16("Giant Hammer",15,5,0);
    Card C17("Wand of Telekinesis",5,0,16);
    Card C18("Ring of Invisibility",0,1,35);
    Card C19("Amulet of Regeneration",0,0,12);
    Card C20("Tsurugi", 35, 5, 0);

    vector<Card> reserve = {C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11,C12,C13,C14,C15,C16,C17,C18,C19,C20};
    cout<<"LetChoose method : ";
        player1.letChoose(reserve);
        player1.display();
    cout<<endl;

    cout<<"LetChooseDicho method : ";
        player2.letChooseDicho(reserve);
        player2.display();
    cout<<endl;
}

// ################ Game ###############################################
void testConstructorsGame()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Test data variables
    vector<Card> reserve = {Card("Card 1", 10, 5, 3),
                            Card("Card 2", 6, 7, 2),
                            Card("Card 3",11,2,0),
                            Card("Card 4",0,2,14),
                            Card("Card 5",3,7,6)};
    Player player1 = Player("Player 1", 10, {1, 2, 3});
    Player player2 = Player("Player 2", 5, {4, 5});
    Player expectedPlayer("Yugi", 25, {0, 1, 2, 3, 4});

    // Create two games with different constructors
    Game game1;
    Game game2(reserve, player1, player2);

    // Test game1
    if (!game1.compareGame({{}, expectedPlayer, expectedPlayer}))
    {
        ok = false;
        cout << "Error: The object 'game1' is not built with the correct values" << endl;
    }

    // test player 2
    if (!game2.compareGame({reserve, player1, player2}))
    {
        ok = false;
        cout << "Error: The object 'game2' is not built with the correct values" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "Constructors : OK" << endl;
    }

}

void testEndedMethod()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create two players with different prestige and deck sizes
    Player player1("Player 1", 5, {1, 2, 3});
    Player player2("Player 2", 3, {4, 5, 6, 7});

    // Create a reserve with some cards
    vector<Card> reserve = {{"Card 1", 1, 2, 3},
                            {"Card 2", 4, 5, 6}};

    // Create a game with the players and reserve
    Game game(reserve, player1, player2);

    // The game should not be ended at this point
    Player winner;
    if (game.ended(winner))
    {
        ok = false;
        cout << "Error: The game should not be ended yet" << endl;
    }

    // Reduce player 2's prestige to 0
    game.modifyPlayerTwoPrestige(0);

    // The game should be ended now, with player 1 as the winner
    if (!(game.ended(winner)))
    {
        ok = false;
        cout << "Error: The game should be ended now" << endl;
    }
    else if (winner.GetName() != "Player 1")
    {
        ok = false;
        cout << "Error: The winner should be Player 1" << endl;
    }

    // Reset player 2's prestige and clear their deck
    game.modifyPlayerTwoPrestige(3);
    game.clearPlayerTwoDeck();

    // The game should be ended now, with player 1 as the winner
    if (!(game.ended(winner)))
    {
        ok = false;
        cout << "Error: The game should be ended now" << endl;
    }
    else if (winner.GetName() != "Player 1")
    {
        ok = false;
        cout << "Error: The winner should be Player 1" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "Ended method : OK" << endl;
    }
}

void testIsGameFinishedMethod()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create two players with different prestige and deck sizes
    Player player1("Player 1", 5, {1, 2, 3});
    Player player2("Player 2", 3, {4, 5, 6});

    // Create a reserve
    vector<Card> reserve = {};

    // Create a game with the players and reserve
    Game game(reserve, player1, player2);

    // The game should not be finished
    if (game.IsGameFinished())
    {
        ok = false;
        cout << "Error: The game should not be finished" << endl;
    }

    // Clear the deck of player 2
    game.clearPlayerTwoDeck();

    // The game should be finished
    if (!game.IsGameFinished())
    {
        ok = false;
        cout << "Error: The game should be finished" << endl;
    }

    // Create a game with a non-empty deck for player 1 and zero prestige for player 2
    Player player3("Player 3", 5, {1, 2, 3});
    Player player4("Player 4", 0, {4, 5, 6});
    Game game1(reserve, player3, player4);

    // The game should be finished
    if (!game.IsGameFinished())
    {
        ok = false;
        cout << "Error: The game should be finished" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "IsGameFinishedMethod : OK" << endl;
    }
}

void testIncrementOperator()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create two players with different deck
    Player player1("player1", 25, {2, 1, 0});
    Player player2("player2", 25, {2, 4, 3});

    // Create the reserve of cards
    vector<Card> reserve = {{"Gol d Roger", 15, 13, 15},
                            {"Chopper",     3,  6,  2},
                            {"Usopp",       3,  2,  0},
                            {"Ace",         8,  8,  12},
                            {"Shanks",      10, 10, 15},};

    // Create a Game
    Game game(reserve, player1, player2);

    // Test for a physical and magical win
    ++game;
    if (game.GetPlayerOne().GetPrestige() != 25 && game.GetPlayerTwo().GetPrestige() != 15)
    {
        ok = false;
        cout << "Error: The player1's number of prestige is " << game.GetPlayerOne().GetPrestige()
             << "and it should be equal to 25, the player2's number of prestige is " << game.GetPlayerTwo().GetPrestige() <<
             "and it should be equal to 15" << endl;
    }

    // Test for a physical and magical lose
    ++game;
    if (game.GetPlayerOne().GetPrestige() != 8 && game.GetPlayerTwo().GetPrestige() != 15)
    {
        ok = false;
        cout << "Error: The player1's number of prestige is " << game.GetPlayerOne().GetPrestige()
             << "and it should be equal to 8, the player2's number of prestige is " << game.GetPlayerTwo().GetPrestige() <<
             "and it should be equal to 15" << endl;
    }

    // Test for a physical and magical draw
    ++game;
    if (game.GetPlayerOne().GetPrestige() != 8 && game.GetPlayerTwo().GetPrestige() != 15)
    {
        ok = false;
        cout << "Error: The player1's number of prestige is " << game.GetPlayerOne().GetPrestige()
             << "and it should be equal to 8, the player2's number of prestige is " << game.GetPlayerTwo().GetPrestige() <<
             "and it should be equal to 15" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "IncrementOperator : OK" << endl;
    }


}

void testFillReserve() {
    // Create the boolean for the result of the test
    bool ok = true;

    // Create two players with different deck
    Player player1("player1", 25, {2, 1, 0});
    Player player2("player2", 25, {2, 4, 3});

    // Create the reserve of cards
    vector<Card> reserve = {{"Gol d Roger", 15, 13, 15},
                            {"Chopper",     3,  6,  2},
                            {"Usopp",       3,  2,  0},
                            {"Ace",         8,  8,  12},
                            {"Shanks",      10, 10, 15},
                            {"Gol d Roger", 15, 13, 15},
                            {"Chopper",     3,  6,  2},
                            {"Usopp",       3,  2,  0},
                            {"Ace",         8,  8,  12},
                            {"Shanks",      10, 10, 15},
                            {"Gol d Roger", 15, 13, 15},
                            {"Chopper",     3,  6,  2},
                            {"Usopp",       3,  2,  0},
                            {"Ace",         8,  8,  12},
                            {"Shanks",      10, 10, 15}
                            };

    // Create a Game
    Game game(reserve, player1, player2);

    //starting the tests
    game.fillReserve("C:/Users/samue/Project-Card-Game-main/cards_data.txt");
    cout<<"fillReserve method : OK "<<endl;

}


