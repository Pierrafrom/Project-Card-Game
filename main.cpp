// Project Card Game
// by Pierre
// and Samuel

#include <iostream>
#include "Card.h"

using namespace std;

int main()
{
    // Declaration of variables
    Card C1("Gol d Roger", 10, 8, 10);
    Card C2("nami", 5, 5, 15);
    Card C3("Edward Newgate", 10, 8, 10);
    Card C4("Joz", 4, 15, 0);

    // Tests
    cout << "############################ Start Testing ###################################################" << endl;

    cout << "------------------test for Display-----------------------------------------------------" << endl;
    cout << "Long display: " << endl;
    C1.displayLong();
    cout << endl << "Short display: " << endl;
    cout << C2;
    cout << endl;

    cout << "------------------test for physicalDamage-----------------------------------------------------" << endl;
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

    cout << "------------------test for physicalDamage-----------------------------------------------------" << endl;
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
    if ((C1 ^ C3) ==0)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "ERR" << endl;
    }
    cout << endl;

    cout << "############################ End Testing ###################################################" << endl;

    return 0;
}
