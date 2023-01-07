// Project Card Game
// by Pierre
// and Samuel

#include "Player.h"
#include "Card.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include "Game.h"
#include <string>

using namespace std;

// Default constructor
Player::Player()
{
    _name = "Yugi";
    _prestige = 25;
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

// Initialise the deck of a player
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
    unsigned int size = _deck.size();
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
    // We'll have an exception if one player has no more cards left
    // The exception is defined in the nextCard method
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

// Shuffles the targeted player's deck
void Player::shuffle()
{
    srand(time(nullptr));
    for (int &i: _deck)
    {
        int j = rand() % _deck.size();
        swap(i, _deck[j]);
    }
}

// Fiel the deck with cards which have the best chosen stat
void Player::fillDeckWithCriteria(const vector<Card> &reserve, Tri sortCriteria)
{
    unsigned int size = _deck.size();
    unsigned int sizeReserve = reserve.size();
    _deck.clear();
    int i = 0;
    int j;
    while (_deck.size() < size)
    {
        j = 0;
        while (j < sizeReserve && _deck.size() != size)
        {
            if (i == vectorOfRanks(reserve, sortCriteria)[j])
            {
                _deck.push_back(j);
            }
            j++;
        }
        i++;
    }
}

bool isInVector(const string &name, const vector<string> &nameChosen, bool sort)
{
    if (sort)
    {
        if (nameChosen.empty())
        {
            return false;
        }

        // dichotomy search
        int start = 0;
        unsigned int end = nameChosen.size() - 1;
        bool found = false;

        while (start <= end && !found)
        {
            int mid = (start + end) / 2;
            if (nameChosen[mid] == name)
            {
                found = true;
            }
            else if (nameChosen[mid] < name)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return found;
    }
    else
    {
        // sequential search
        unsigned int size = nameChosen.size();
        bool found = false;
        int i = 0;
        while (i < size && !found)
        {
            if (name == nameChosen[i])
            {
                found = true;
            }
            i++;
        }
        return found;
    }
}

bool isInReserve(const string &name, const vector<Card> &reserve, bool sort)
{
    if (sort)
    {
        // dichotomy search
        int start = 0;
        unsigned int end = reserve.size() - 1;
        bool found = false;

        while (start <= end && !found)
        {
            int mid = (start + end) / 2;
            if (reserve[mid].getName() == name)
            {
                found = true;
            }
            else if (reserve[mid].getName() < name)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return found;
    }
    else
    {
        // sequential search
        unsigned int size = reserve.size();
        bool found = false;
        int i = 0;
        while (i < size && !found)
        {
            if (name == reserve[i].getName())
            {
                found = true;
            }
            i++;
        }
        return found;
    }
}

void enterName(const vector<Card> &reserve, vector<string> &nameChosen, string &name, int ind, bool sort)
{
    bool ok1 = false, ok2 = false;
    cout << "Enter the name of your Card number " << ind << endl;
    cin >> name;

    // check if the card have already been entered
    ok1 = !isInVector(name, nameChosen, sort);
    ok2 = isInReserve(name, reserve, sort);

    while (!ok1 || !ok2)
    {
        cout << "The name id incorrect : ";
        if (!ok1)
        {
            cout << "this card have already been added, ";
        }
        if (!ok2)
        {
            cout << "this card is not in the reserve.";
        }
        cout << endl;
        cin >> name;
        ok1 = !isInVector(name, nameChosen, sort);
        ok2 = isInReserve(name, reserve, sort);
    }
    nameChosen.push_back(name);
}

// Fill the deck manually
void Player::fillDeckManually(const vector<Card> &reserve, bool sort)
{
    _deck.clear();
    vector<string> nameChosen{};
    string name;
    int rank;
    unsigned int size = reserve.size();

    int j;
    bool found;
    for (int i = 0; i < 20; ++i)
    {
        enterName(reserve, nameChosen, name, i, sort);
        j = 0;
        found = false;
        if (sort)
        {
            // dichotomy search
            int start = 0;
            unsigned int end = reserve.size() - 1;

            while (start <= end && !found)
            {
                int mid = (start + end) / 2;
                if (reserve[mid].getName() == name)
                {
                    found = true;
                    rank = mid;
                }
                else if (reserve[mid].getName() < name)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        else
        {
            // sequential search
            while (j < size && !found)
            {
                if (name == reserve[j].getName())
                {
                    rank = j;
                    found = true;
                }
                j++;
            }
        }
        _deck.push_back(rank);
    }

    cout << "Your deck is completed, your deck is :" << endl;
    unsigned int deckSize = _deck.size();
    for (int i = 0; i < deckSize; ++i)
    {
        cout << reserve[_deck[i]];
    }
}

// Fill the deck with random cards
void Player::fillDeckRandom(const vector<Card> &reserve)
{
    // Clear the current deck
    _deck.clear();

    // Create a random number generator
    random_device rd;
    mt19937 gen(rd());

    // Set up a distribution to generate numbers in the range [0, reserve.size()-1]
    uniform_int_distribution<> dis(0, reserve.size() - 1);

    // Generate numbers until the deck has 20 cards
    while (_deck.size() < 20)
    {
        // Generate a random number
        int num = dis(gen);

        // Check if the number is already in the deck
        if (find(_deck.begin(), _deck.end(), num) == _deck.end())
        {
            // If the number is not in the deck, add the corresponding card to the deck
            _deck.push_back(num);
        }
    }
}

// Fill deck
void Player::fillDeck(const vector<Card> &reserve)
{
    cout << "Here is the reserve of Card :" << endl;
    unsigned int size = reserve.size();
    for (int i = 0; i < size; ++i)
    {
        cout << reserve[i];
    }

    cout << endl << this->GetName() << ", How do you want to fill your deck? " << endl;
    cout << "Enter the number of the chosen filling :" << endl;
    cout << "1. Take 20 randoms cards from the reserve\n"
            "2. Fill your deck manually\n"
            "3. Take the 20 cards with the best score (Att + Def + Mag)\n"
            "4. Take the 20 cards with the lowest score (Att + Def + Mag)\n"
            "5. Take the 20 cards with the best score with coefficient (3*Att + Def + 2*Mag)\n"
            "6. Take the 20 cards with the lowest score with coefficient (3*Att + Def + 2*Mag)\n"
            "7. Take the 20 cards with the best Attack (if equality : magic, then defense) in descending order\n"
            "8. Take the 20 cards with the best Attack (if equality : magic, then defense) in ascending order\n"
            "9. Take the 20 cards with the best Attack (if equality : defense, then magic) in descending order\n"
            "10. Take the 20 cards with the best Attack (if equality : defense, then magic) in ascending order\n"
            "11. Take the 20 cards with the best Defense (if equality : attack, then magic) in descending order\n"
            "12. Take the 20 cards with the best Defense (if equality : attack, then magic) in ascending order\n"
            "13. Take the 20 cards with the best Defense (if equality : magic, then attack) in descending order\n"
            "14. Take the 20 cards with the best Defense (if equality : magic, then attack) in ascending order\n"
            "15. Take the 20 cards with the best Magic (if equality : attack, then defense) in descending order\n"
            "16. Take the 20 cards with the best Magic (if equality : attack, then defense) in ascending order\n"
            "17. Take the 20 cards with the best Magic (if equality : defense, then attack) in descending order\n"
            "18. Take the 20 cards with the best Magic (if equality : defense, then attack) in ascending order\n"
         << endl;
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 18)
    {
        cout << "Incorrect value, please enter a number between 1 and 18" << endl;
        cin >> choice;
    }

    switch (choice)
    {
        case 2:
            this->fillDeckManually(reserve, true);
            break;
        case 3:
            this->fillDeckWithCriteria(reserve, ScoreDesc);
            break;
        case 4:
            this->fillDeckWithCriteria(reserve, ScoreAsc);
            break;
        case 5:
            this->fillDeckWithCriteria(reserve, ScoreWithCoefAMDDesc);
            break;
        case 6:
            this->fillDeckWithCriteria(reserve, ScoreWithCoefAMDAsc);
            break;
        case 7:
            this->fillDeckWithCriteria(reserve, AMDDesc);
            break;
        case 8:
            this->fillDeckWithCriteria(reserve, AMDAsc);
            break;
        case 9:
            this->fillDeckWithCriteria(reserve, ADMDesc);
            break;
        case 10:
            this->fillDeckWithCriteria(reserve, ADMAsc);
            break;
        case 11:
            this->fillDeckWithCriteria(reserve, DAMDesc);
            break;
        case 12:
            this->fillDeckWithCriteria(reserve, DAMAsc);
            break;
        case 13:
            this->fillDeckWithCriteria(reserve, DMADesc);
            break;
        case 14:
            this->fillDeckWithCriteria(reserve, DMAAsc);
            break;
        case 15:
            this->fillDeckWithCriteria(reserve, MADDesc);
            break;
        case 16:
            this->fillDeckWithCriteria(reserve, MADAsc);
            break;
        case 17:
            this->fillDeckWithCriteria(reserve, MDADesc);
            break;
        case 18:
            this->fillDeckWithCriteria(reserve, MDAAsc);
            break;
        default:
            this->fillDeckRandom(reserve);
            break;
    }
}

// Sort deck manually
void Player::sortDeckManually(const vector<Card> &reserve)
{
    int a, b;
    do
    {
        cout << this->GetName() << ", Here is your deck :" << endl;
        unsigned int size = _deck.size();
        for (int i = 0; i < size; i++)
        {
            cout << i << " ";
            cout << reserve[_deck[i]];
        }
        cout << endl << "Choose the indexes of cards you want to swap" << endl;
        cout << "Enter -1, -1 to if you have finished" << endl;
        cin >> a >> b;
        while (a < -1 || a > 19 || b < -1 || b > 19)
        {
            cout << "Incorrect values, please enter values between 0 and 19 (or -1 if you have finished)";
            cin >> a >> b;
        }
        swap(_deck[a], _deck[b]);
    } while (a != -1 && b != -1);
}

// Choose a strategy for human player
void Player::chooseStrategy(const vector<Card> &reserve)
{
    // Displays the actual player's deck
    cout << this->GetName() << ", Here is your deck :" << endl;
    unsigned int size = _deck.size();
    for (int i = 0; i < size; i++)
    {
        cout << reserve[_deck[i]];
    }

    // Ask him if he wants to modify it
    cout << endl << this->GetName() << "Choose how you want to sort your deck :" << endl;
    cout << "Enter the number of the chosen strategy :" << endl;
    cout << "1. Keep the deck like this\n"
            "2. Sort the deck manually\n"
            "3. Shuffle the deck randomly\n"
            "4. Sort the deck with the best score (Att + Def + Mag)\n"
            "5. Sort the deck with the lowest score (Att + Def + Mag)\n"
            "6. Sort the deck with the best score with coefficient (3*Att + Def + 2*Mag)\n"
            "7. Sort the deck with the lowest score with coefficient (3*Att + Def + 2*Mag)\n"
            "8. Sort the deck with the best Attack (if equality : magic, then defense) in descending order\n"
            "9. Sort the deck with the best Attack (if equality : magic, then defense) in ascending order\n"
            "10. Sort the deck with the best Attack (if equality : defense, then magic) in descending order\n"
            "11. Sort the deck with the best Attack (if equality : defense, then magic) in ascending order\n"
            "12. Sort the deck with the best Defense (if equality : attack, then magic) in descending order\n"
            "13. Sort the deck with the best Defense (if equality : attack, then magic) in ascending order\n"
            "14. Sort the deck with the best Defense (if equality : magic, then attack) in descending order\n"
            "15. Sort the deck with the best Defense (if equality : magic, then attack) in ascending order\n"
            "16. Sort the deck with the best Magic (if equality : attack, then defense) in descending order\n"
            "17. Sort the deck with the best Magic (if equality : attack, then defense) in ascending order\n"
            "18. Sort the deck with the best Magic (if equality : defense, then attack) in descending order\n"
            "19. Sort the deck with the best Magic (if equality : defense, then attack) in ascending order\n"
         << endl;
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 18)
    {
        cout << "Incorrect value, please enter a number between 1 and 18" << endl;
        cin >> choice;
    }

    switch (choice)
    {
        case 2:
            this->sortDeckManually(reserve);
            break;
        case 3:
            this->shuffle();
            break;
        case 4:
            sortVectorOfCard(_deck, ScoreDesc, reserve);
            break;
        case 5:
            sortVectorOfCard(_deck, ScoreAsc, reserve);
            break;
        case 6:
            sortVectorOfCard(_deck, ScoreWithCoefAMDDesc, reserve);
            break;
        case 7:
            sortVectorOfCard(_deck, ScoreWithCoefAMDAsc, reserve);
            break;
        case 8:
            sortVectorOfCard(_deck, AMDDesc, reserve);
            break;
        case 9:
            sortVectorOfCard(_deck, AMDAsc, reserve);
            break;
        case 10:
            sortVectorOfCard(_deck, ADMDesc, reserve);
            break;
        case 11:
            sortVectorOfCard(_deck, ADMAsc, reserve);
            break;
        case 12:
            sortVectorOfCard(_deck, DAMDesc, reserve);
            break;
        case 13:
            sortVectorOfCard(_deck, DAMAsc, reserve);
            break;
        case 14:
            sortVectorOfCard(_deck, DMADesc, reserve);
            break;
        case 15:
            sortVectorOfCard(_deck, DMAAsc, reserve);
            break;
        case 16:
            sortVectorOfCard(_deck, MADDesc, reserve);
            break;
        case 17:
            sortVectorOfCard(_deck, MADAsc, reserve);
            break;
        case 18:
            sortVectorOfCard(_deck, MDADesc, reserve);
            break;
        case 19:
            sortVectorOfCard(_deck, MDAAsc, reserve);
            break;
        default:;
    }
    // During the game the first card called is the card at the top of the deck (in the last position)
    // So we reverse the vector to respect the strategy established earlier
    unsigned int n = _deck.size();
    for (int i = 0; i < n / 2; i++)
    {
        int temp = _deck[i];
        _deck[i] = _deck[n - i - 1];
        _deck[n - i - 1] = temp;
    }
}


// Set the AI deck with the correct difficulty
void Player::setAIDeck(char difficulty, const vector<Card> &reserve)
{
    // In this function for each difficulty we have 3 possible strategy
    // We start by generate a random number between 1 and 3
    // This number will be used to choose the strategy randomly

    // Create a random number generator
    random_device rd;
    mt19937 gen(rd());
    // Set up a distribution to generate numbers in the range [1, 3]
    uniform_int_distribution<> dis(1, 3);
    // Generate a random number
    int strategy = dis(gen);

    // Set the deck for an easy AI
    if (difficulty == '1')
    {
        switch (strategy)
        {
            case 1:
                this->fillDeckWithCriteria(reserve, ScoreAsc);
                this->shuffle();
                break;
            case 2:
                this->fillDeckWithCriteria(reserve, DMADesc);
                break;
            default:
                this->fillDeckWithCriteria(reserve, ScoreWithCoefAMDAsc);
                sortVectorOfCard(_deck, MDADesc, reserve);
        }
    }
    else
    {
        // Set the difficulty for a medium AI
        if (difficulty == '2')
        {
            switch (strategy)
            {
                case 1:
                    this->fillDeckWithCriteria(reserve, MADDesc);
                    break;
                case 2:
                    this->fillDeckWithCriteria(reserve, ADMDesc);
                    sortVectorOfCard(_deck, DAMDesc, reserve);
                    break;
                default:
                    this->fillDeckWithCriteria(reserve, MDADesc);
            }
        }
            // Set the difficulty for a hard AI
        else
        {
            switch (strategy)
            {
                case 1:
                    this->fillDeckWithCriteria(reserve, AMDDesc);
                    sortVectorOfCard(_deck, ScoreWithCoefAMDDesc, reserve);
                    break;
                case 2:
                    this->fillDeckWithCriteria(reserve, ScoreWithCoefAMDDesc);
                    break;
                default:
                    this->fillDeckWithCriteria(reserve, AMDDesc);
                    sortVectorOfCard(_deck, MADDesc, reserve);
                    break;
            }
        }
    }
    // During the game the first card called is the card at the top of the deck (in the last position)
    // So we reverse the vector to respect the strategy established earlier
    unsigned int n = _deck.size();
    for (int i = 0; i < n / 2; i++)
    {
        int temp = _deck[i];
        _deck[i] = _deck[n - i - 1];
        _deck[n - i - 1] = temp;
    }
}

// The following methods are not in the instructions, but we had them because they are useful many times

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
    unsigned int size = _deck.size();
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

// Operator for equality
bool Player::operator==(const Player &player)
{
    return (_name == player._name && _prestige == player._prestige && this->compareDeck(player._deck));
}
