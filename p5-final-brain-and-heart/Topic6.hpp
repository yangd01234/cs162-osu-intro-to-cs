/*********************************************************************
** Program name: Final Project
** Author: Derek Yang
** Date:12/2/2017
** Description:This is the Topic6 header file.
*********************************************************************/

#ifndef TOPIC6_HPP
#define TOPIC6_HPP

#include "Space.hpp"

class Topic6 : public Space{
public:
    virtual int getItemTA();
private:
    Dice d1;

};


#endif
