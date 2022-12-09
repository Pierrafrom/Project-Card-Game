#include "Player.h"
#include "Card.h"
#include <iostream>

using namespace std;

///default constructor
Player::Player()
{
    _name = "Yugi";
    _prestige = 25;
    Card righthand("RightHand", 1, 0, 0);
    Card lefthand("LeftHand", 0, 1, 0);
    Card head("Head", 1, -2, 0);
    Card mouth("Mouth", 1, -1, 2);
    Card knee("Knee", 2, 0, 0);
    _deck = {righthand, lefthand, head, mouth, knee};
}


///constructor
Player::Player(string name, int prestige, vector<Card> cards)
{
    _name = name;
    _prestige = prestige;
    _deck = cards;
}


///get the name of targeted player
string Player::GetName() const
{
    return _name;
}


///get the number prestige points of targeted player
int Player::GetPrestige() const
{
    return _prestige;
}

///Displaying the information of the targeted player
void Player::display()
{
    cout << "The player " << _name << " has " << _prestige << " prestige points, only " << _deck.size()
         << " left in his pile ⚡" << endl;
}

void Player::init(vector<Card> &reserve)
{
    cout << "initialisation of the player's deck" << endl;
    int size = reserve.size();
    if (size >= 20)
    {
        for (int i = 0; i <= 20; i++)
        {
            _deck.push_back(reserve[i]);
        }
    }
}

bool Player::enoughCards()
{
    return (_prestige >= 0);
}

void Player::nextCard(Card &card)
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

// update prestige after a play
void Player::playsACard(Player &player)
{
    Card c, c1;
    this->nextCard(c);
    player.nextCard(c1);
    int resPhysicalMatch = c + c1;
    int resMagicalMatch = c ^ c1;
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


