/*********************************************************************
** Program name: Final Project
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the Finals header file.
*********************************************************************/


#ifndef Finals_HPP
#define Finals_HPP

#include "Space.hpp"

class Finals : public Space{
public:
    virtual int getItemTA();

private:
    Dice d1;

};


#endif
