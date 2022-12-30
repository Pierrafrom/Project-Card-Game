// Project Card Game
// by Pierre
// and Samuel

#ifndef PROJECT_CARD_GAME_TESTS_H
#define PROJECT_CARD_GAME_TESTS_H

void testAll();
//################# Card ####################################################
void testCardConstructors();
void testDisplayLongMethod();
void testDisplayShortMethod();
void testPhysicalDamageMethod();
void testMagicalDamage();
void testCardEqualityOperator();
void test_fill();
//################# Player ##################################################
void testConstructorsPlayer();
void testGettersMethods();
void testDisplayMethod();
void testInitMethod();
void testShuffleMethod();
void testEnoughCardsMethod();
void testEnoughPrestigeMethod();
void testNextCardMethod();
void testPlaysACardMethod();
void testletChooseMethod();
//################ Game  ###################################################
void testEndedMethod();
void testConstructorsGame();
void testIsGameFinishedMethod();
void testIncrementOperator();

#endif //PROJECT_CARD_GAME_TESTS_H
