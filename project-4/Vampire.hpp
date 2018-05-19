/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is Vampire header file which inherits from the
 * Character parent class.
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP


#include "Character.hpp"

class Vampire : public Character{
private:
    Dice d1;
public:
    Vampire();
    Vampire(int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn,
            int armorIn, int strengthIn, std::string charIn, std::string specIn);
    virtual void specialAbility();
    virtual std::string getName();
    virtual int defense(int enemyAttackIn);
};


#endif
