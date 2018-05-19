/*********************************************************************
** Program name: Game Character vs Character
** Author: Derek Yang
** Date:10/28/2017
** Description:This is Harrypotter header file which inherits from the
 * Character parent class.
*********************************************************************/

#ifndef FRAME_1_HARRYPOTTER_HPP
#define FRAME_1_HARRYPOTTER_HPP


#include "Character.hpp"

class Harrypotter : public Character{
private:
    bool hogwardsFlag = true;
    Dice d1;
public:
    Harrypotter();
    Harrypotter(int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn,
                int armorIn, int strengthIn, std::string charIn, std::string specIn);
    virtual void specialAbility();
    virtual std::string getName();
    virtual int defense(int enemyAttackIn);

};


#endif
