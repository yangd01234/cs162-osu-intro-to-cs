/*********************************************************************
** Program name: Final Project
** Author: Derek Yang
** Date:12/2/2017
** Description:This is the Topic5 header file.
*********************************************************************/

#ifndef TOPIC5_HPP
#define TOPIC5_HPP

#include "Space.hpp"

class Topic5 : public Space{
public:
    virtual int getItemTA();
private:
    Dice d1;

};


#endif
