// Project Card Game
// by Pierre
// and Samuel

#include "Tests.h"
#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Game.h"
#include <vector>
#include <sstream>
#include <string>


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
    // Player
    cout << "----------------- Player --------------------------------" << endl;
    testConstructorsPlayer();
    testGettersMethods();
    testDisplayMethod();
    testInitMethod();
    testEnoughCardsMethod();
    testEnoughPrestigeMethod();
    testNextCardMethod();
    testPlaysACardMethod();
    testShuffleMethod();
    // Game
    cout << "----------------- Game ----------------------------------" << endl;
    testConstructorsGame();
    testEndedMethod();
    testIsGameFinishedMethod();
    testPlaysARoundMethod();
    testWinnerMethod();
    testFillReserve();
    cout << "----------------- Function ------------------------------" << endl;
    testSortVectorOfCard();
    testVectorOfRanks();
    testFillDeckWithCriteria();
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

    // Test the displayLong method by capturing its output
    stringstream output;
    streambuf *old = cout.rdbuf(output.rdbuf());
    cout << card;
    cout.rdbuf(old);

    // Check that the output is as expected
    string expectedOutput = "Gol d Roger [ 10 ; 8 ; 10 ] \n";
    if (output.str() != expectedOutput)
    {
        ok = false;
        cout << "Error: The output of the displayLong method is incorrect" << endl;
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
    Card C4("Joz", 4, 15, 1);

    // Test for a win
    if ((C1 ^ C4) != -9)
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

    // Create a player with a name and prestige
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

void testShuffleMethod()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create a player with a deck
    Player player("player", 25, {0, 1, 2, 3, 4, 5});

    // Shuffle the deck
    player.shuffle();

    // Verify that the shuffled deck is different from the initial one
    if (player.getDeck() == vector<int>({0, 1, 2, 3, 4, 5}))
    {
        cout << "Error: The shuffled deck is the same as the initial one." << endl;
        ok = false;
    }

    // Result of the test
    if (ok)
    {
        cout << "Shuffle method: OK" << endl;
    }
}

// ################ Game ###############################################
void testConstructorsGame()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Test data variables
    vector<Card> reserve = {Card("Card 1", 10, 5, 3),
                            Card("Card 2", 6, 7, 2)};
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
        cout << "IsGameFinished method : OK" << endl;
    }
}

void testPlaysARoundMethod()
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
             << "and it should be equal to 25, the player2's number of prestige is "
             << game.GetPlayerTwo().GetPrestige() <<
             "and it should be equal to 15" << endl;
    }

    // Test for a physical and magical lose
    ++game;
    if (game.GetPlayerOne().GetPrestige() != 8 && game.GetPlayerTwo().GetPrestige() != 15)
    {
        ok = false;
        cout << "Error: The player1's number of prestige is " << game.GetPlayerOne().GetPrestige()
             << "and it should be equal to 8, the player2's number of prestige is " << game.GetPlayerTwo().GetPrestige()
             <<
             "and it should be equal to 15" << endl;
    }

    // Test for a physical and magical draw
    ++game;
    if (game.GetPlayerOne().GetPrestige() != 8 && game.GetPlayerTwo().GetPrestige() != 15)
    {
        ok = false;
        cout << "Error: The player1's number of prestige is " << game.GetPlayerOne().GetPrestige()
             << "and it should be equal to 8, the player2's number of prestige is " << game.GetPlayerTwo().GetPrestige()
             <<
             "and it should be equal to 15" << endl;
    }

    // Result of the test
    if (ok)
    {
        cout << "PlaysARound method : OK" << endl;
    }
}

void testWinnerMethod()
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

    // It shouldn't exist a winner now
    if (game.winner() != 0)
    {
        cout << "Error: We shouldn't have a winner" << endl;
        ok = false;
    }

    game.modifyPlayerTwoPrestige(0);

    // Player 1 is the winner
    if (game.winner() != 1)
    {
        cout << "Error: The winner should be player 1" << endl;
        ok = false;
    }

    game.modifyPlayerTwoPrestige(10);
    game.modifyPlayerOnePrestige(0);

    // Player 2 is the winner
    if (game.winner() != -1)
    {
        cout << "Error: The winner should be player 2" << endl;
        ok = false;
    }

    game.modifyPlayerTwoPrestige(0);

    // It's a draw
    if (game.winner() != 0)
    {
        cout << "Error: there is no winner because the game is a draw" << endl;
        ok = false;
    }

    // Result of the test
    if (ok)
    {
        cout << "Winner method : OK" << endl;
    }
}

void testFillReserve()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create two players with different deck
    Player player1("player1", 25, {2, 1, 0});
    Player player2("player2", 25, {2, 4, 3});

    // Create the reserve of cards
    vector<Card> reserve = {};

    // Create a Game
    Game game(reserve, player1, player2);

    //starting the tests
    game.fillReserve("C:/Users/pierr/OneDrive/travail IUT/Project-Card-Game/cards_data.txt");
    game.getReserve();
    ok = game.getSizeReserve() > 0;
    if (ok)
    {
        cout << "fillReserve : OK" << endl;
    }
    else
    {
        cout << "fillReserve : ERROR" << endl;
    }
}

// ################ Function ###############################################

void testSortVectorOfCard()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create the reserve of cards
    vector<Card> reserve = {{"Gol d Roger", 9,  15, 13},
                            {"Chopper",     3,  6,  2},
                            {"Usopp",       3,  2,  2},
                            {"Ace",         9,  9,  12},
                            {"Shanks",      10, 9,  15},};

    // Create a vector of integers
    vector<int> deck = {3, 2, 4, 1, 0};

    // We don't test with every possible's sort criteria, but we regrouped every possibility in this 5 cases

    // Sort the vector order by magic then by attack then by defense in descending order
    sortVectorOfCard(deck, MADDesc, reserve);

    // Check if the vector is correctly sorted
    if (deck != vector<int>{4, 0, 3, 1, 2})
    {
        cout << "Error: the vector is not correctly sorted" << endl;
        ok = false;
    }

    // Sort the vector order by attack, then by magic, then by defense in descending order
    sortVectorOfCard(deck, AMDDesc, reserve);

    // Check if the vector is correctly sorted
    if (deck != vector<int>{4, 0, 3, 1, 2})
    {
        cout << "Error: the vector is not correctly sorted" << endl;
        ok = false;
    }

    // Sort the vector order by defense, then by attack, then by magic in descending order
    sortVectorOfCard(deck, DAMDesc, reserve);

    // Check if the vector is correctly sorted
    if (deck != vector<int>{0, 4, 3, 1, 2})
    {
        cout << "Error: the vector is not correctly sorted" << endl;
        ok = false;
    }

    // Sort the vector in ascending order by score
    sortVectorOfCard(deck, ScoreAsc, reserve);

    // Check if the vector is correctly sorted
    if (deck != vector<int>{2, 1, 3, 4, 0})
    {
        cout << "Error: the vector is not correctly sorted" << endl;
        ok = false;
    }

    // Sort the vector in ascending order by score with coefficients
    sortVectorOfCard(deck, ScoreWithCoefAMDAsc, reserve);

    // Check if the vector is correctly sorted
    if (deck != vector<int>{2, 1, 3, 0, 4})
    {
        cout << "Error: the vector is not correctly sorted" << endl;
        ok = false;
    }

    // Result of the test
    if (ok)
    {
        cout << "SortVectorOfCard function : OK" << endl;
    }
}

void testVectorOfRanks()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create the reserve of cards
    vector<Card> reserve = {{"Gol d Roger", 9,  15, 13},
                            {"Chopper",     3,  6,  2},
                            {"Usopp",       3,  2,  2},
                            {"Ace",         9,  9,  12},
                            {"Shanks",      10, 9,  15},};

    // We don't test with every possible's sort criteria, but we regrouped every possibility in this 4 cases

    // Test with sort by attack, then magic, then defense in descending order
    vector<int> ranks = vectorOfRanks(reserve, AMDDesc);
    if (ranks != vector<int>({1, 3, 4, 2, 0}))
    {
        cout << "Error: vectorOfRanks with sort by attack, then magic, then defense in descending order is incorrect"
             << endl;
        ok = false;
    }

    // Test with sort by attack, then magic, then defense in ascending order
    ranks = vectorOfRanks(reserve, AMDAsc);
    if (ranks != vector<int>({3, 1, 0, 2, 4}))
    {
        cout << "Error: vectorOfRanks with sort by attack, then magic, then defense in ascending order is incorrect"
             << endl;
        ok = false;
    }

    // Test with sort by magic, then by attack, then by defense in descending order
    ranks = vectorOfRanks(reserve, MADDesc);
    if (ranks != vector<int>({1, 3, 4, 2, 0}))
    {
        cout
                << "Error: vectorOfRanks with sort by magic, then by attack, then by defense in descending order is incorrect"
                << endl;
        ok = false;
    }

    // Test with sort by defense, then by attack, then by magic in descending order
    ranks = vectorOfRanks(reserve, DAMDesc);
    if (ranks != vector<int>({0, 3, 4, 2, 1}))
    {
        cout
                << "Error: vectorOfRanks with sort by defense, then by attack, then by magic in descending order is incorrect"
                << endl;
        ok = false;
    }

    // Result of the test
    if (ok)
    {
        cout << "VectorOfRanks function : OK" << endl;
    }
}

void testFillDeckWithCriteria()
{
    // Create the boolean for the result of the test
    bool ok = true;

    // Create a player with a non-empty deck
    Player player("player", 25, {0, 1, 2, 3, 4});

    // Create the reserve of cards
    vector<Card> reserve = {{"Gol d Roger", 15, 13, 15},
                            {"Chopper",     3,  6,  2},
                            {"Usopp",       3,  2,  0},
                            {"Ace",         8,  8,  12},
                            {"Shanks",      10, 10, 15},};

    // This function calls the VectorOfRanks function so if this one is correct, FillDeckWithCriteria
    // will be correct for every sort criteria. So, it is sufficient to test with one sort criteria.

    // Fill the deck with cards which have the highest attack, then magic, then defense in descending order
    player.fillDeckWithCriteria(reserve, AMDDesc);

    // Check if the deck is filled with cards with the highest attack
    unsigned int size = player.getDeck().size();
    for (int i = 0; i < size; i++)
    {
        if (player.getDeck() != vector<int>({0, 4, 3, 1, 2}))
        {
            cout << "Error: The deck is not correctly filled " << endl;
            ok = false;
        }
    }

    // Result of the test
    if (ok)
    {
        cout << "FillDeckWithCriteria function: OK" << endl;
    }
}
