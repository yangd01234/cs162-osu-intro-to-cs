/*********************************************************************
** Program name: Game Character vs Character
** Author: Derek Yang
** Date:10/28/2017
** Description:This is Medusa Child Class.  This class will override
 * the attack function and activate glare which kills the opponent.
*********************************************************************/

#include "Medusa.hpp"
//int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn, int armorIn, int strengthIn, str characteristics, str ability
Medusa::Medusa() : Character(6, 2, 6, 1, 3, 8,"Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!",
"Glare: If a Medusa rolls 12 when attacking, then the target instantly gets turned into a stone, and Medusa wins! If Medusa uses Glare on Harry Potter on his first life, then Harry Potter get back to life"){
}

Medusa::Medusa(int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn, int armorIn, int strengthIn, std::string charIn, std::string specIn):
        Character(attackSidesIn, attackTurnsIn, defenseSidesIn, defenseTurnsIn, armorIn, strengthIn, charIn, specIn){

}

void Medusa::specialAbility() {


    std::cout<<"Glare Activated! Target turned to stone..."<<std::endl;

}

std::string Medusa::getName() {
    return "Medusa";
}

//overrides the attack function and activates Glare if roll is 12.  Enemy instantly dies unless harry potter with hogwarts
int Medusa::attack() {
    int roll1 = d1.roll(6);
    std::cout<<"\nDie #: 1 Roll: "<<roll1<<std::endl;
    int roll2 = d1.roll(6);
    std::cout<<"Die #: 2 Roll: "<<roll2<<std::endl;

    if((roll1+roll2) == 12){
        std::cout<<"Medusa's glare activated"<<std::endl;
        return 99;
    } else {
        return roll1+roll2;
    }
}