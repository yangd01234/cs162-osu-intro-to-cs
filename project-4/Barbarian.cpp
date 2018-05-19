/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Date:10/28/2017
** Description:This is Barbarian Child Class
*********************************************************************/
#include "Barbarian.hpp"


//int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn, int armorIn, int strengthIn, str characteristics, str ability
Barbarian::Barbarian() : Character(6, 2, 6, 2, 0, 12, "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.",
"No special ability"){
}

Barbarian::Barbarian(int attackSidesIn, int attackTurnsIn,int defenseSidesIn, int defenseTurnsIn, int armorIn, int strengthIn, std::string charIn, std::string specIn):
        Character(attackSidesIn, attackTurnsIn, defenseSidesIn, defenseTurnsIn, armorIn, strengthIn, charIn, specIn){

}

void Barbarian::specialAbility() {
    std::cout<<"spec ab"<<std::endl;
}

std::string Barbarian::getName() {
    return "Barbarian";
}