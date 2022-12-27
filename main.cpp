// Project Card Game
// by Pierre
// and Samuel

#include "Tests.h"
#include <iostream>

#define TEST ON

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
    cout << "Version without tests" << endl;
    return 0;
}
#endif
