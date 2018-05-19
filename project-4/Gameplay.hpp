/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the gameplay header file.
*********************************************************************/

#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "Menu.hpp"
#include "Validation.hpp"
#include "Character.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Harrypotter.hpp"
#include "Vampire.hpp"
#include "Bluemen.hpp"
#include "Queue.hpp"
#include "Node.hpp"
#include "doubleLink.hpp"
#include <iostream>

#include <vector>

class Gameplay {
public:
    Gameplay();
    ~Gameplay();
    void getInput();
    void buildMenu();
    void setCharacter(int inputIn, Queue &qIn, std::string nameIn);//add *& for a reference to a pointer
    bool rounds(Character* pB, Character* pA);
    void playAgain();
    void subRound(Character*& characterInOne, std::string playerInOne, Character*& characterInTwo, std::string playerInTwo);
    int attackTurn(Character* charIn);
    int defenseTurn(Character* charIn, int atkIn);
    void addLoser(Character* charIn);
    void traverseGame();
    void getPlayerSet(std::string aorb);
    void removeAll();

private:
    bool flag1 = true;
    int numberFighters;
    Menu m1;
    Validation v1;
    Queue qA;
    Queue qB;
    doubleLink losers;




    int input;

    //Character* pCharA;
    //Character* pCharB;
};


#endif
