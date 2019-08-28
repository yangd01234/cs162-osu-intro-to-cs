/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the Character header file for the Character
 * parent class.
*********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "Dice.hpp"
class Character {
private:
    int attackDieSides;
    int attackDieTurns;
    int defenseDieSides;
    int defenseDieTurns;
    int armorP;
    int strengthP;
    std::string characteristicsStr;
    std::string specialAbilityStr;
    int attackP;
    int defenseP;
    std::string charName;

    Dice d1;


public:
    Character();
    Character(int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn,
              int armorIn, int strengthIn, std::string charIn, std::string specIn);
    virtual int attack();
    virtual int defense(int enemyAttackIn);
    virtual void specialAbility() = 0;
    bool dead();

    std::string getCharacteristicsStr();
    std::string getspecialAbilityStr();

    int getArmor();
    int getStrength();
    int getDefense();
    int getDefenseDie();
    void setDefenseDie(int newDie);
    void setStrength(int strIn);
    virtual std::string getName() = 0;
    std::string getCustomName();
    void setCustomName(std::string nameIn);
    void setAllP(int attackIn, int defenseIn, int armorIn, int strengthIn);
    void setAllD(std::string charIn, std::string specIn);
    void recovery();

    ~Character();

};


#endif
