/*********************************************************************
** Program name: Final Project
** Author: Derek Yang
** Date:12/2/2017
** Description:This is the header file for the dice class.
*********************************************************************/

#ifndef DICE_HPP
#define DICE_HPP

#include <iostream>
#include <string>
#include <vector>
class Dice {
private:

public:

    Dice();
    int rollMultiple(int sidesIn, int timesIn);
    int roll(int sidesIn);
    ~Dice();

};


#endif
