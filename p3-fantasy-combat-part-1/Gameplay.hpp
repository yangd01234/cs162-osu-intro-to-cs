/*********************************************************************
** Program name: Game Character vs Character
** Author: Derek Yang
** Date:10/28/2017
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


#include <vector>

class Gameplay {
public:
    Gameplay();
    ~Gameplay();
    void getInput();
    void buildMenu();
    void setCharacter(Character*&,int inputIn);//add *& for a reference to a pointer
    void rounds();
    void playAgain();
    void subRound(Character* characterInOne, std::string playerInOne, Character* characterInTwo, std::string playerInTwo);
    int attackTurn(Character* charIn);
    int defenseTurn(Character* charIn, int atkIn);

private:

    Menu m1;
    Validation v1;




    int input;

    Character* pCharA;
    Character* pCharB;
};


#endif
