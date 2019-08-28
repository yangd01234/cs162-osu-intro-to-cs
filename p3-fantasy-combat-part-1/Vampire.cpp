/*********************************************************************
** Program name: Game Character vs Character
** Author: Derek Yang
** Date:10/28/2017
** Description:This is Vampire child class.  This class will
 * override the defense fucntion and block 50% of all attacks.
*********************************************************************/

#include "Vampire.hpp"


//int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn, int armorIn, int strengthIn, str characteristics, str ability
Vampire::Vampire() : Character(12, 1, 6, 1, 1, 18, "Suave, debonair, but vicious and surprisingly risilient",
                               "Charm: Vampires can charm an opponent into not attacking. For a given attack there is a 50% chance that their opponent does not actually attack them."){
}

Vampire::Vampire(int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn, int armorIn, int strengthIn, std::string charIn, std::string specIn):
Character(attackSidesIn, attackTurnsIn, defenseSidesIn, defenseTurnsIn, armorIn, strengthIn, charIn, specIn){

}

void Vampire::specialAbility() {
    std::cout<<"spec ab"<<std::endl;
}

std::string Vampire::getName() {
    return "Vampire";
}

//overrides the defense function and has a 50% change to activate charm to block all attacks
int Vampire::defense(int enemyAttackIn) {
    int currentDefense = d1.rollMultiple(6, 1);
    int charm = rand() % 2 + 1;
    int newStr = getStrength();

    if(charm == 2){
        std::cout<<"Charm activated"<<std::endl;
        currentDefense = 0;
    }else{
        currentDefense = enemyAttackIn - currentDefense - getArmor();
        if (currentDefense > 0) {
            newStr = getStrength() - currentDefense;
        }
        setStrength(newStr);
    }
    return currentDefense;
}