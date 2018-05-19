/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the validation header file.
*********************************************************************/

#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <iostream>
#include <string>

class Validation {

private:

public:
    void getValidInt(std::string ques, int &inputVar, int max, int min);
    void getValidStr(std::string ques, std::string &inputStr);
    int startGame(std::string startOp, std::string miscOp, std::string quitOp);
};

#endif