/*********************************************************************
** Program name: Langston's Ant
** Author: Derek Yang
** Date: 9/26/2017
** Description: Ant class.  This class will contain all the information
 * for the board, ant location, and ant orientation.  Included are a
 * set of get and set methods which will help keep track of
 * and pull variables.
*********************************************************************/

#include "ant.hpp"

//creates the ant object
//later include either random or input
Ant::Ant(){
    antX = 0;
    antY = 0;
    direction = East;
    currentColor = ' ';
    rl = Right;
}

//gets the ant's current x coord
int Ant::getAntX(){
    return antX;
}


//gets the ant's current y coord
int Ant::getAntY(){
    return antY;
}

//gest the direction as enum
CardinalDirection Ant::getDirection() {
    return direction;
}

//returns right left as enum
RL Ant::getRL(){
    return rl;
}

//returns current square color
char Ant::getCurrentColor(){
    return currentColor;
}

//sets the ant current x value
void Ant::setX(int x){
    antX = x;
}

//sets the ant current y value
void Ant::setY(int y){
    antY = y;
}

//sets x and y of ant
void Ant::setXY(int x, int y){
    antX = x;
    antY = y;
}

//sets the direction of the ant
void Ant::setDirection(CardinalDirection d){
    direction = d;
}

//sets the r/l of the ant
void Ant::setRL(RL r_l){
    rl = r_l;
}

//sets current color of the grid
void Ant::setCurrentColor(char c){
    currentColor = c;
}
