/*********************************************************************
** Program name: Final Project
** Author: Derek Yang
** Date:12/2/2017
** Description:This is the Topic3 header file.
*********************************************************************/

#ifndef TOPIC3_HPP
#define TOPIC3_HPP

#include "Space.hpp"

class Topic3 : public Space{
public:
    virtual int getItemTA();
private:
    Dice d1;

};


#endif
