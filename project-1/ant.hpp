/*********************************************************************
** Program name: Langston's Ant
** Author: Derek Yang
** Date: 9/26/2017
** Description: Header file for the ant class
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

//declares enum for directions
enum CardinalDirection{North, East, West, South};
enum RL{Right, Left};
class Ant {
private:
    int antX, antY;
    char currentColor;
    RL rl;



public:
    Ant();
    int getAntX();
    int getAntY();
    void setX(int x);
    void setY(int y);
    void setXY(int x, int y);
    void setDirection(CardinalDirection d);
    void setCurrentColor(char c);
    void setRL(RL r_l);
    char getCurrentColor();
    RL getRL();
    CardinalDirection direction;
    CardinalDirection getDirection();


};

#endif