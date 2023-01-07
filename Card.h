// Project Card Game
// by Pierre
// and Samuel

#ifndef PROJECT_CARD_GAME_CARD_H
#define PROJECT_CARD_GAME_CARD_H

#include <string>

using namespace std;

// Define here the path and the name of the file which contain the data for the reserve
const string PATH = R"(C:\Users\pierr\OneDrive\travail IUT\Project-Card-Game\)";
const string FILENAME = "cards_data.txt";

/**
 * The Tri enum type appears to be a list of different sorting orders that can
 * be applied to the cards. The acronym letters in the name of each enum value
 * indicate the sorting order of the attributes: A for attack, D for defense,
 * and M for magic. The Desc and Asc suffixes indicate whether the attribute
 * should be sorted in descending or ascending order, respectively.
 * The Score criteria is for the sum of the card's attack, magic,
 * and defense attributes, while ScoreWithCoef criteria is for a weighted sum that gives
 * more importance to the attack attribute and less importance to the
 * defense attribute.
 */
enum Tri
{
    AMDDesc, AMDAsc, ADMDesc, ADMAsc, MADDesc, MADAsc, MDADesc, MDAAsc, DAMDesc, DAMAsc, DMADesc, DMAAsc,
    ScoreDesc, ScoreAsc, ScoreWithCoefAMDDesc, ScoreWithCoefAMDAsc
};

//Declaration of the Card class
class Card
{
    string _name;
    int _attack;
    int _defense;
    int _magic;

public:
    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This constructor creates a new Card object with default values for its attributes:            *
    * "bare hands" with 1 attack, 1 defense, 0 magic                                                *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return A new Card object with default values for its attributes.                             *
    *                                                                                               *
    *************************************************************************************************
    */
    Card();

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This constructor creates a new Player object with the given values for its attributes.        *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param name The name of the Player object.                                                    *
    * @param prestige The prestige of the Player object.                                            *
    * @param deck The deck of the Player object.                                                    *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return A new Card object with given values for its attributes.                               *
    *                                                                                               *
    *************************************************************************************************
    */
    Card(const string &name, int attack, int defense, int magic);

    /**
   *************************************************************************************************
   *                                                                                               *
   * Description                                                                                   *
   * ===========                                                                                   *
   * This function displays the attributes of a Card object in a formatted manner,                 *
   * including its name, attack, defense, and magic values.                                        *
   *                                                                                               *
   * Input parameters                                                                              *
   * ====================                                                                          *
   * (none)                                                                                        *
   *                                                                                               *
   * Output parameters                                                                             *
   * ====================                                                                          *
   * (none)                                                                                        *
   *                                                                                               *
   *************************************************************************************************
   */
    void displayLong() const;

    /**
   *************************************************************************************************
   *                                                                                               *
   * Description                                                                                   *
   * ===========                                                                                   *
   * This function displays the attributes of a Card object in a formatted manner,                 *
   * including its name, attack, defense, and magic values.                                        *
   *                                                                                               *
   * Input parameters                                                                              *
   * ====================                                                                          *
   * (none)                                                                                        *
   *                                                                                               *
   * Output parameters                                                                             *
   * ====================                                                                          *
   * (none)                                                                                        *
   *                                                                                               *
   *************************************************************************************************
   */
    void displayShort() const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function calculates the physical damage that one Card object would do to another,        *
    * based on their attack and defense values. If the first Card object's attack value is greater  *
    * than the second Card object's attack value, the function returns the difference between the   *
    * two attack values. If the two attack values are equal, the function returns 0. If the second  *
    * Card object's attack value is greater than the first Card object's defense value, the         *
    * function returns the difference between the two attack values. Otherwise, the                 *
    * function returns 0.                                                                           *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param card The Card object to calculate physical damage against.                             *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return The physical damage that the first Card object would do to the second Card object.    *
    *                                                                                               *
    *************************************************************************************************
    */
    int physicalDamage(const Card &card) const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function calculates the magical damage that one Card object would do to another,         *
    * based on their magic values. It returns the difference between the second Card object's       *
    * magic value and the first Card object's magic value.                                          *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param card The Card object to calculate magical damage against.                              *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return The magical damage that the first Card object would take from the second Card object. *
    *                                                                                               *
    *************************************************************************************************
    */
    int magicalDamage(const Card &card) const;

    /**
      *************************************************************************************************
      *                                                                                               *
      * Description                                                                                   *
      * ===========                                                                                   *
      * This function overloads the '+' operator for use with two Card objects, allowing for          *
      * the calculation of physical damage between the two objects. It calls the `physicalDamage`     *
      * function to perform the calculation and returns the result.                                   *
      *                                                                                               *
      * Input parameters                                                                              *
      * ====================                                                                          *
      * @param card The Card object to calculate physical damage against.                             *
      *                                                                                               *
      * Output parameters                                                                             *
      * ====================                                                                          *
      * @return The physical damage that the first Card object would do to the second Card object.    *
      *                                                                                               *
      *************************************************************************************************
      */
    int operator+(const Card &card) const;

    /**
      *************************************************************************************************
      *                                                                                               *
      * Description                                                                                   *
      * ===========                                                                                   *
      *  This function overloads the '^' operator for use with two Card objects, allowing for the     *
      *  calculation of magical damage between the two objects. It calls the `magicalDamage` function *
      *  to perform the calculation and returns the result.                                           *
      *                                                                                               *
      * Input parameters                                                                              *
      * ====================                                                                          *
      * @param card The Card object to calculate magical damage against.                              *
      *                                                                                               *
      * Output parameters                                                                             *
      * ====================                                                                          *
      * @return The magical damage that the first Card object would take from the second Card object. *
      *                                                                                               *
      *************************************************************************************************
      */
    int operator^(const Card &card) const;

    /**
      *************************************************************************************************
      *                                                                                               *
      * Description                                                                                   *
      * ===========                                                                                   *
      * This function overloads the '==' operator for use with two Card objects, allowing for the     *
      * comparison of their attributes for equality. It returns true if all of the attributes         *
      * (name, attack, defense, and magic) are equal, and false otherwise.                            *
      *                                                                                               *
      * Input parameters                                                                              *
      * ====================                                                                          *
      * @param card The Card object to compare with.                                                  *
      *                                                                                               *
      * Output parameters                                                                             *
      * ====================                                                                          *
      * @return True if all of the attributes of the two Card objects are equal, false otherwise.     *
      *                                                                                               *
      *************************************************************************************************
      */
    bool operator==(const Card &card) const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Compare two Card objects based on the given sorting criteria                                  *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param card The Card object to compare with                                                   *
    * @param sortCriteria The sorting criteria to use for comparison                                *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return True if this Card object is correctly positioned with respect to the given Card       *
    * object based on the sorting criteria,                                                         *
    * False otherwise                                                                               *
    *                                                                                               *
    *************************************************************************************************
    */
    bool compareCard(const Card &card, Tri sortCriteria) const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function calculates the score of a Card object by adding its attack, magic, and defense  *
    * values.                                                                                       *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return The score of the Card object.                                                         *
    *                                                                                               *
    *************************************************************************************************
    */
    int getScore() const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function calculates the score of a Card object by applying a coefficient of 3 to the     *
    * attack value, a coefficient of 2 to the magic value, and a coefficient of 1 to the defense    *
    * value, and then adding the resulting values.                                                  *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return The score of the Card object with the coefficients applied.                           *
    *                                                                                               *
    *************************************************************************************************
    */
    int getScoreAMD() const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function reads a string containing the name, attack, defense, and magic values for a     *
    * Card object, and uses the values to set the corresponding attributes of the Card object.      *
    * The values are expected to be separated by commas.                                            *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param line The string containing the values to be used to fill the Card object.              *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * None. The Card object is filled with the values read from the string.                         *
    *                                                                                               *
    *************************************************************************************************
    */
    void fill(const string &line);

    // The following methods are not in the instructions, but we had them because they are useful many times.

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Get the name of the Card object                                                               *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    *  @return The name of the Card object                                                          *
    *                                                                                               *
    *************************************************************************************************
    */
    string getName() const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Get the attack value of the Card object                                                       *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return The attack value of the Card object                                                   *
    *                                                                                               *
    *************************************************************************************************
    */
    int getAttack() const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Get the defense value of the Card object                                                      *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return The defense value of the Card object                                                  *
    *                                                                                               *
    *************************************************************************************************
    */
    int getDefense() const;

    /**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * Get the magic value of the Card object                                                        *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * (none)                                                                                        *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return The magic value of the Card object                                                    *
    *                                                                                               *
    *************************************************************************************************
    */
    int getMagic() const;

};

/**
    *************************************************************************************************
    *                                                                                               *
    * Description                                                                                   *
    * ===========                                                                                   *
    * This function overloads the '<<' operator for use with a Card object and an output stream,    *
    * allowing for the display of a short version of the Card object. It calls the `displayShort`   *
    * function to perform the display.                                                              *
    *                                                                                               *
    * Input parameters                                                                              *
    * ====================                                                                          *
    * @param os The output stream to display the Card object to.                                    *
    * @param card The Card object to display.                                                       *
    *                                                                                               *
    * Output parameters                                                                             *
    * ====================                                                                          *
    * @return The output stream with the short version of the Card object displayed to it.          *
    *                                                                                               *
    *************************************************************************************************
    */
void operator<<(ostream &os, const Card &card);

#endif //PROJECT_CARD_GAME_CARD_H
