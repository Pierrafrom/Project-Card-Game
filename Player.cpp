// Project Card Game
// by Pierre
// and Samuel

#include "Player.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <cstdlib>  // for rand and srand
#include <ctime>    // for time
#include <string>

using namespace std;

// Default constructor
Player::Player()
{
    _name = "Yugi";
    _prestige = 25;
    /*
    Card righthand("RightHand", 1, 0, 0);
    Card lefthand("LeftHand", 0, 1, 0);
    Card head("Head", 1, -2, 0);
    Card mouth("Mouth", 1, -1, 2);
    Card knee("Knee", 2, 0, 0);
     */
    _deck = {0, 1, 2, 3, 4};
}

// Full constructor
Player::Player(const string &name, int prestige, const vector<int> &deck)
{
    _name = name;
    _prestige = prestige;
    _deck = deck;
}

// Get the name of targeted player
string Player::GetName() const
{
    return _name;
}

// Get the number prestige points of targeted player
int Player::GetPrestige() const
{
    return _prestige;
}

// Displaying the information of the targeted player
void Player::display() const
{
    cout << "The player " << _name << " has " << _prestige << " prestige points, only " << _deck.size()
         << " left in his pile " << endl;
}

// Initialise the deck of a player from a card reserve
void Player::init()
{
    for (int i = 0; i < 20; i++)
    {
        _deck.push_back(i);
    }
}

// True if the player has enough cards to play
bool Player::enoughCards() const
{
    return (!_deck.empty());
}

// True if the player has enough cards to play
bool Player::enoughPrestige() const
{
    return (_prestige > 0);
}

// Get the next card of the player and remove it from his deck
void Player::nextCard(int &card)
{
    int size = _deck.size();
    if (size > 0)
    {
        card = _deck[size - 1];
        _deck.pop_back();
    }
    else
    {
        throw out_of_range("no more cards left !");
    }
}

// Update prestige after a play
void Player::playsACard(Player &player, const vector<Card> &reserve)
{
    int c, c1;
    this->nextCard(c);
    player.nextCard(c1);
    int resPhysicalMatch = reserve[c] + reserve[c1];
    int resMagicalMatch = reserve[c] ^ reserve[c1];
    if (resPhysicalMatch > 0)
    {
        _prestige -= resPhysicalMatch;
    }
    else
    {
        player._prestige += resPhysicalMatch;
    }
    if (resMagicalMatch > 0)
    {
        _prestige -= resMagicalMatch;
    }
    else
    {
        player._prestige += resMagicalMatch;
    }
}

// The following methods are not in the instructions, but we had them because they are useful for tests

// Modify the prestige number of a player
void Player::modifyPrestige(int num)
{
    _prestige = num;
}

// Clear the deck of the player
void Player::clearDeck()
{
    _deck.clear();
}

// Compare the player's deck with a given deck
bool Player::compareDeck(const vector<int> &vector)
{
    bool ok = true;
    int size = _deck.size();
    if (vector.size() != size)
    {
        ok = false;
    }
    if (ok)
    {
        int i = 0;
        while (ok && i < size)
        {
            if (_deck[i] != vector[i])
            {
                ok = false;
            }
            i++;
        }
    }
    return ok;
}

// Get the deck of a player
vector<int> Player::getDeck()
{
    return _deck;
}

// modify the deck of a player
void Player::modifyDeck(const vector<int> &deck)
{
    _deck = deck;
}

//operator for equality
bool Player::operator==(const Player &player)
{
    return (_name==player._name && _prestige==player._prestige && this->compareDeck(player._deck));
}

//shuffles the targeted player's deck
void Player::shuffle() {
    srand(time(nullptr));
    for(int & i : _deck){
        int j = rand() % _deck.size();
        swap(i, _deck[j]);
    }
}

void Player::letChoose(const vector<Card> &reserve) {
    string cardName;
    int cpt = 0;
    while ((cpt <= 20) and (cardName != "STOP")) {
        cout<<"Enter in order every cards from the reserve you wish to add to your deck  ----- enter STOP to end the method if you want to add less than 20 cards -----  : "<< endl;
        getline(cin, cardName);
        cout << cardName << endl;
        for (int i = 0; i < reserve.size(); i++) {
            if (cardName == reserve[i].getName()) {
                cout << "card found at index " << i << endl;
                _deck.push_back(i);
                cpt++;
                break;
            }
        }
    }
}



void Player::letChooseDicho(const vector<Card> &reserve) {
    string cardName;//searched cardName
    int start = 0;
    int end = reserve.size()-1;
    int middle;
    int i = 0;
    while ((i <= 20) and (cardName != "STOP")) {
        cout<<"Enter in order every cards from the reserve you wish to add to your deck  ----- type STOP to end the method before adding 20 cards -----  : "<< endl;
        getline(cin, cardName);
        cout << cardName << endl;
        while (start <= end) {  // Dichotomic search loop
            middle = (start + end) / 2;
            if (cardName == reserve[middle].getName()) {
                cout << "card found at index " << middle << endl;
                _deck.push_back(middle);
                i++;
                break;
            }
            else if (cardName < reserve[middle].getName()) {
                end = middle - 1;
            }
            else {
                start = middle + 1;
            }
        }
    }
}
