/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the main for the tournement program.
*********************************************************************/

#include <iostream>
#include "Gameplay.hpp"

int main() {
    int inputPlay = 0;
    bool playAgain = true;
    Gameplay g1;
    Validation v1;


    while(playAgain){

        std::cout<<"1. Play"<<std::endl;
        std::cout<<"2. Exit"<<std::endl;
        v1.getValidInt("",inputPlay,2,1);
        if(inputPlay == 1){
            g1.buildMenu();
            g1.getInput();
            g1.traverseGame();
        } else {
            playAgain = false;
        }

    }
    return 0;
}