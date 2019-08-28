/*********************************************************************
** Program name: Final Project
** Author: Derek Yang
** Date:12/2/2017
** Description:This is the Topic1 header file.
*********************************************************************/

#ifndef TOPIC1_HPP
#define TOPIC1_HPP

#include "Space.hpp"

class Topic1 : public Space{
public:
    virtual int getItemTA();
private:
    Dice d1;

};


#endif
