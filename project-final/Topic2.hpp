/*********************************************************************
** Program name: Final Project
** Author: Derek Yang
** Date:12/2/2017
** Description:This is the Topic2 header file.
*********************************************************************/

#ifndef TOPIC2_HPP
#define TOPIC2_HPP

#include "Space.hpp"

class Topic2 : public Space{
private:
    Dice d1;
public:
    virtual int getItemTA();
};


#endif
