/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the Character class which is the parent class.
 * In this class, a recovery function is implemented.
*********************************************************************/

#include "Character.hpp"

Character::Character() {
}

Character::Character(int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn,
                     int armorIn, int strengthIn, std::string charIn, std::string specIn) {
    attackDieSides = attackSidesIn;
    attackDieTurns = attackTurnsIn;
    defenseDieSides = defenseSidesIn;
    defenseDieTurns = defenseTurnsIn;
    armorP = armorIn;
    strengthP = strengthIn;
    characteristicsStr = charIn;
    specialAbilityStr = specIn;
}

//returns the result of attack
int Character::attack() {
    return d1.rollMultiple(attackDieSides,attackDieTurns);
}

//returns the result of defense and sets new str.  Will return 0 if defense is negative
int Character::defense(int enemyAttackIn) {
    int currentDefense = d1.rollMultiple(defenseDieSides, defenseDieTurns);
    currentDefense = enemyAttackIn - currentDefense - armorP;
    //only subtract str if the current defense is actually dealing dmg
    if (currentDefense > 0) {
        strengthP -= currentDefense;
    }

    return currentDefense;
}

//gets the characteristics of the character
std::string Character::getCharacteristicsStr(){
    return characteristicsStr;
}

//gets the special ability description of the character
std::string Character::getspecialAbilityStr(){
    return specialAbilityStr;
}

//gest the number of defense turns
int Character::getDefenseDie() {
    return defenseDieTurns;
}

//sets the number of defense turns
void Character::setDefenseDie(int newDie) {
    defenseDieTurns = newDie;
}

//sets the strength of the character
void Character::setStrength(int strIn) {
    strengthP = strIn;
}

//returns true if character is dead
bool Character::dead() {
    if(strengthP <= 0){
        return true;
    } else{
        return false;
    }
}

void Character::recovery() {
    strengthP = strengthP*1.2;
}
//gets the defense of the character
int Character::getDefense() {
    return defenseP;
}

//sets all points for the character.  Do not need only for testing
void Character::setAllP(int attackIn, int defenseIn, int armorIn, int strengthIn) {
    attackP = attackIn;
    defenseP = defenseIn;
    armorP = armorIn;
    strengthP = strengthIn;
}


//sets all description for character.  Do not need only for testing
void Character::setAllD(std::string charIn, std::string specIn) {
    characteristicsStr = charIn;
    specialAbilityStr = specIn;
}

//gest the armor of the character
int Character::getArmor() {
    return armorP;
}

//sets the strength of the character
int Character::getStrength() {
    return strengthP;
}

//sets the custom name
void Character::setCustomName(std::string nameIn) {
    charName = nameIn;
}

//gets the custom name
std::string Character::getCustomName() {
    return charName;
}

//destructor
Character::~Character() {

}