/*********************************************************************
** Program name: Final Project
** Author: Derek Yang
** Date:12/2/2017
** Description:This is the Space class. This is class is the parent
 * class for all the spaces in the game.
*********************************************************************/

#include "Space.hpp"

Space::Space() {
    //creates a new space
    left = NULL;
    right = NULL;
    bottom = NULL;
    top = NULL;
}


void Space::setLeft(Space* spaceIn) {
    left = spaceIn;
}

void Space::setRight(Space* spaceIn) {
    right = spaceIn;
}
void Space::setBottom(Space* spaceIn) {
    bottom = spaceIn;
}

void Space::setTop(Space* spaceIn) {
    top = spaceIn;
}

void Space::setName(std::string nameIn){
    name = nameIn;
}
void Space::setDescription(std::string descIn){
    description = descIn;
}

void Space::setDifficulty(int difIn) {
    difficulty = difIn;
}

void Space::setCleared() {
    cleared = true;
}

void Space::setSeratoninDec(int decIn) {
    seratoninDec = decIn;
}
Space* Space::getRight() {
    return right;
}

Space* Space::getLeft() {
    return left;
}

Space* Space::getTop() {
    return top;
}

Space* Space::getBottom() {
    return bottom;
}
std::string Space::getName() {
    return name;
}

std::string Space::getDesc() {
    return description;
}

int Space::getDifficulty() {
    return difficulty;
}

bool Space::getCleared(){
    return cleared;
}

int Space::getSeratoninDec() {
    return seratoninDec;
}

Space::~Space() {

}