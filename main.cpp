// Project Card Game
// by Pierre
// and Samuel

#include <iostream>
#include "Card.h"
#include "Player.h"
#include "Game.h"
#include "test.h"
#include "main_test.h"
#include <vector>

using namespace std;

int main()
{
    // Declaration of variables/objects
    Card C1("Gol d Roger", 10, 8, 10);
    Card C2("nami", 5, 5, 15);
    Card C3("Edward Newgate", 10, 8, 10);
    Card C4("Joz", 4, 15, 0);
    Card C5("ener", 12, 2, 5);
    vector<Card> resserve ={C1,C2,C3,C4,C5};
    Player P0;
    vector<int> deck1={0, 3, 2};
    vector<int> deck2={1, 3, 4};
    Player P1("Eiichiro Oda", 25, deck1);
    Player P2("Akira Toriyama", 25, deck2);

    // Tests
    cout << "############################ Start Testing ###################################################" << endl;

    main_test();

    cout << "------------------ test for GetName (Player) --------------------------------------------------" << endl;
    cout << "Regular case: ";
    if (P1.GetName() == "Eiichiro Oda")
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
    if (P1.GetPrestige() == 25)
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
