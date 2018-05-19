/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is Bluemen Child Class.   This class will override
 * the defense function and remove one die for every 4 dmg.
*********************************************************************/
#include "Bluemen.hpp"


//int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn, int armorIn, int strengthIn, str characteristics, str ability
Bluemen::Bluemen() : Character(10, 2, 3, 6, 3, 12,"They are small, 6 inch tall, but fast and tough. They are hard to hit so they can take some damage. They can also do a LOT of damage when they crawl inside enemies’ armor or clothing.",
                               "Mob: Blue Men are actually a swarm of small individuals. For every 4 points of damage, they lose one defense die. For example, if they have a strength of 8, they would have 2d6 for defense."){
}

Bluemen::Bluemen(int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn, int armorIn, int strengthIn, std::string charIn, std::string specIn):
        Character(attackSidesIn, attackTurnsIn, defenseSidesIn, defenseTurnsIn, armorIn, strengthIn, charIn, specIn){

}

void Bluemen::specialAbility() {
    std::cout<<"spec ab"<<std::endl;
}

//this function will remove one die for every 4 pts of dmg
int Bluemen::defense(int enemyAttackIn) {
    int currentDefense = d1.rollMultiple(2, getDefenseDie());

    int newStr = getStrength();

    currentDefense = enemyAttackIn - currentDefense - getArmor();
        if (currentDefense > 0) {
            newStr = getStrength() - currentDefense;
        }

    if(currentDefense >= 4){
        int divider = (getStrength())/4;
        //UNCOMMENT FOR MOB
        //std::cout<<"Mob activated!"<<std::endl;
        setDefenseDie(divider);
    }

    setStrength(newStr);
    return currentDefense;
}


std::string Bluemen::getName() {
    return "Blue Men";
}