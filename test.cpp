//
// Created by samue on 23/12/2022.
//

#include "test.h"
#include "Player.h"
#include "Card.h"


#include <cassert>
#include <sstream>
#include <string>

using namespace std;

    // Declaration of variables/objects for the tests
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


    void testdisplayLong() {
        cout << "------------------ test for Display Long -----------------------------------------------" << endl;

        // creating of a stream in order to verify the proper display of a card
        ostringstream out;
        streambuf* cout_buf = cout.rdbuf();
        cout.rdbuf(out.rdbuf());

        // calling the long display function
        C1.displayLong();

        // restoration of the original stream
        cout.rdbuf(cout_buf);

        // result verification
        assert(out.str() == "****************************\nname: Gol d Roger\nattack: 10\ndefense: 8\nmagic: 10\n****************************\n");
        cout<<"test passed !"<<endl;
    }

    void testdisplayShort() {
        cout << "------------------ test for Display Short --------------------------------------------------" << endl;

        // creating of a stream in order to verify the proper display of a card
        ostringstream out;
        streambuf* cout_buf = cout.rdbuf();
        cout.rdbuf(out.rdbuf());

        // calling the short display function
        cout<<C1;

        // Restoration of the original output flow
        cout.rdbuf(cout_buf);

        // Verification of the result obtained
        assert(out.str() == "Gol d Roger [ 10 ; 8 ; 10 ] \n");
        cout<<"test passed !"<<endl;
    }
    
    
    
    
    void testphysicalDamage(){      ///testing if the method + which stands for physicalDamage() is working
    
    
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
    
    }
    
    void testmagicalDamage(){
        cout << "------------------ test for magicalDamage -----------------------------------------------------" << endl;
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
    }


