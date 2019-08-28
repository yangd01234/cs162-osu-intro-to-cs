/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is Harrypotter Child Class.  This class will
 * override the defense function and activate Hogwarts once if
 * the character's health reaches 0 the first time.
*********************************************************************/

#include "Harrypotter.hpp"

//int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn, int armorIn, int strengthIn, str characteristics, str ability
Harrypotter::Harrypotter() : Character(6, 2, 6, 2, 0, 10,"Harry Potter is a wizard"
        ,"Hogwarts: If Harry Potter strength reaches 0 or below, he immediately recovers and his total strength becomes 20. If he were to die again, then he’s dead."){

}

Harrypotter::Harrypotter(int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn, int armorIn, int strengthIn, std::string charIn, std::string specIn):
        Character(attackSidesIn, attackTurnsIn, defenseSidesIn, defenseTurnsIn, armorIn, strengthIn, charIn, specIn){

}

void Harrypotter::specialAbility() {
    std::cout<<"spec ab"<<std::endl;
}

//activates Hogwards if hp drops to 0 and sets it to 20.  Only once
int Harrypotter::defense(int enemyAttackIn) {

    int currentDefense = d1.rollMultiple(6, 2);
    int newStr = getStrength();

        currentDefense = enemyAttackIn - currentDefense - getArmor();

        if(hogwardsFlag && currentDefense >0 && (getStrength()-currentDefense < 0) ){
            //UNCOMMENT to see hogwards
            //std::cout<<"Hogwards Activated!"<<std::endl;
            hogwardsFlag = false;
            newStr = 20;
        } else if (currentDefense > 0){
            newStr = getStrength() - currentDefense;
        }
    setStrength(newStr);
    return currentDefense;
}


std::string Harrypotter::getName() {
    return "Harry Potter";
}