// Project Card Game
// by Pierre
// and Samuel

#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Game.h"
#include <vector>

using namespace std;

int main()
{
    // Declaration of variables/objects
    vector<Card> deck1 = {};
    vector<Card> deck2 = {};
    vector<Card> resserve ={};

    Card C1("Gol d Roger", 10, 8, 10);
    Card C2("nami", 5, 5, 15);
    Card C3("Edward Newgate", 10, 8, 10);
    Card C4("Joz", 4, 15, 0);
    Player P0;
    Player P1("Echiro Oda", 25, deck1);
    Player P2("Akira Toriyama", 25, deck2);

    // Tests
    cout << "############################ Start Testing ###################################################" << endl;

    cout << "------------------ test for Display -----------------------------------------------------" << endl;
    cout << "Long display: " << endl;
    C1.displayLong();
    cout << endl << "Short display: " << endl;
    cout << C2;
    cout << endl;

    cout << "------------------ test for physicalDamage -----------------------------------------------------" << endl;
    cout << "test for a win (low defense): ";
    if (C1 + C2 == -5)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" << endl;
    }
    cout << "test for a win (high defense): ";
    if (C1 + C4 == 0)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" << endl;
    }
    cout << "test for a lose (low defense): ";
    if (C2 + C1 == 5)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" << endl;
    }
    cout << "test for a lose (high defense): ";
    if (C4 + C2 == 0)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" << endl;
    }
    cout << "test for a draw: ";
    if (C1 + C3 == 0)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" << endl;
    }
    cout << endl;

    cout << "------------------ test for physicalDamage -----------------------------------------------------" << endl;
    cout << "test for a win : ";
    if ((C1 ^ C4) == -10)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" << endl;
    }
    cout << "test for a lose : ";
    if ((C1 ^ C2) == 5)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" << endl;
    }
    cout << "test for a draw: ";
    if ((C1 ^ C3) == 0)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" << endl;
    }
    cout << endl;

    cout << "------------------ test for GetName (Player) --------------------------------------------------" << endl;
    cout << "Regular case: ";
    if (P1.GetName() == "Echiro Oda")
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" << endl;
    }
    cout << endl;

    cout << "------------------ test for GetPrestige --------------------------------------------------" << endl;
    cout << "Regular case: ";
    if (P1.GetPrestige() == 20)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" << endl;
    }
    cout << endl;

    cout << "------------------ test for display (Player) --------------------------------------------------" << endl;
    P0.display();
    cout << endl;

    //Tests à réaliser quand on aura fait la lecture des fichiers
    cout << "------------------ test for init --------------------------------------------------" << endl;
    cout << "------------------ test for enoughCards --------------------------------------------------" << endl;
    cout << "------------------ test for nextCard --------------------------------------------------" << endl;
    cout << "------------------ test for PlaysACard --------------------------------------------------" << endl;
    cout << "------------------ test for ended (Game) --------------------------------------------------" << endl;



    cout << "############################ End Testing ###################################################" << endl;

    return 0;
}
