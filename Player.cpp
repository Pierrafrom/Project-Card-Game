#include "Player.h"
#include "Card.h"
#include <iostream>

using namespace std;

///default constructor
Player::Player(){
    _name = "Yugi";
    _prestige = 25;
    Card righthand("RightHand",1,0,0);
    Card lefthand("LeftHand",0,1,0);
    Card head("Head",1,-2,0);
    Card mouth("Mouth",1,-1,2);
    Card knee("Knee",2,0,0);
    _cards = {righthand,lefthand,head,mouth,knee};
}


///constructor
Player::Player(string name, int prestige, vector<Card> cards){
    _name = name;
    _prestige = prestige;
    _cards = cards;
}


///get the name of targeted player
string Player::GetName() const{
    return _name;
}


///get the number prestige points of targeted player
int Player::GetPrestige() const {
    return _prestige;
}

///Displaying the information of the targeted player
void Player::display(){
    cout<<"The player "<<_name<<" has "<<_prestige<<" prestige points, only "<<_cards.size()<<" left in his pile ⚡"<<endl;
}

void Player::init(vector<Card> &reserve)
{
    cout << "initialisation of the player's deck" << endl;
    int size = reserve.size();
    if (size >= 20) // est ce que les cartes piochés sont encore dans le reserve
    {
        for (int i = 0; i <= 20; i++)
        {
            _deck.push_back(reserve[i]);
        }
    }
}

bool Player::enough_deck(){
    return (_prestige<=0);
}

void Player::next_card(Card& actual_card) {
    for (int i = 0; i < _deck.size(); i++) {
        if (_deck[i] == actual_card){
            cout << _deck[i + 1] << endl;
            break;
        }
    }
    throw out_of_range("no more cards next !");

}


