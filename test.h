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
//################# Player ##################################################
void testConstructorsPlayer();
void testGettersMethods();
void testDisplayMethod();
void testInitMethod();
void testEnoughCardsMethod();
void testEnoughPrestigeMethod();
void testNextCardMethod();
void testPlaysACardMethod();
void testShuffleMethod();
//################ Game ###################################################
void testEndedMethod();
void testConstructorsGame();
void testIsGameFinishedMethod();
void testPlaysARoundMethod();
void testWinnerMethod();
void testFillReserve();
// ################ Function ##############################################
void testSortVectorOfCard();
void testVectorOfRanks();
void testFillDeckWithCriteria();

#endif //PROJECT_CARD_GAME_TESTS_H
