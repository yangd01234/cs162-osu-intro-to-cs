/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is Medusa header file which inherits from the
 * Character parent class.
*********************************************************************/

#ifndef FRAME_1_MEDUSA_HPP
#define FRAME_1_MEDUSA_HPP


#include "Character.hpp"

class Medusa : public Character{
private:
    Dice d1;
public:
    Medusa();
    Medusa(int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn,
           int armorIn, int strengthIn, std::string charIn, std::string specIn);
    virtual void specialAbility();
    virtual std::string getName();
    int attack();
};


#endif
