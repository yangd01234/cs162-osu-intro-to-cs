/*********************************************************************
** Program name: Game Character vs Character
** Author: Derek Yang
** Date:10/28/2017
** Description:This is Barbarian header file which inherits from the
 * Character parent class.
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP


#include "Character.hpp"

class Barbarian : public Character{
private:
public:
    Barbarian();
    Barbarian(int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn,
              int armorIn, int strengthIn, std::string charIn, std::string specIn) ;
    virtual void specialAbility();
    virtual std::string getName();
};


#endif //FRAME_1_BARBARIAN_HPP
