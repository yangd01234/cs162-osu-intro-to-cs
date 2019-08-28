/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is Bluemen header file which inherits from the
 * Character parent class.
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP


#include "Character.hpp"

class Bluemen : public Character{
private:
    Dice d1;
public:
    Bluemen();
    Bluemen(int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn,
            int armorIn, int strengthIn, std::string charIn, std::string specIn) ;
    virtual void specialAbility();
    virtual std::string getName();
    virtual int defense(int enemyAttackIn);
};


#endif //FRAME_1_BLUEMEN_HPP
