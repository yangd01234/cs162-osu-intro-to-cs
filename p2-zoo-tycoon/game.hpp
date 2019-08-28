/*********************************************************************
** Program name: Zoo Tycoon
** Author: Derek Yang
** Date:10/21/2017
** Description:This is the game header file.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "tiger.hpp"
#include "turtle.hpp"
#include "penguin.hpp"
#include "animal.hpp"
#include "menu.hpp"
#include <iostream>
#include <string>
#include "zoo.hpp"
#include "validation.hpp"

class Game {

private:
    double bank;
    int arryPos;
    int input;
    int days;
    Menu m1;
    Zoo z1;
    Validation v1;

public:
    Game();
    void playGame();
    void initialInput(A_Type type);
    void turns();
    void randomEvent();
    bool continuePlaying();


};


#endif
