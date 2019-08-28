/*********************************************************************
** Program name: Langston's Ant
** Author: Derek Yang
** Date: 9/26/2017
** Description: Header file for the validation class.
*********************************************************************/

#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <iostream>
#include <string>

class Validation {

private:

public:
    void getValidInt(std::string ques, int &inputVar, int max, int min);
    int startGame(std::string startOp, std::string miscOp, std::string quitOp);
};

#endif