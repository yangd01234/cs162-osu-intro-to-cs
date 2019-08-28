/*********************************************************************
** Program name: Langston's Ant
** Author: Derek Yang
** Date: 9/26/2017
** Description: This is the header file for the board class. You'll
 * notice that there is a double pointer for newBoard.  This will
 * help us create the dynamic 2d array.
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "ant.hpp"
class Board {
private:

    //pointer to a pointer http://www.eskimo.com/~scs/cclass/int/sx8.html
    char **newBoard;
    int row, column;
    Ant antCurrent;
    int cAntX, cAntY;
    char cColor;
    CardinalDirection cDirection;


public:
    Board(int columnMax, int rowMax, int startRow, int startColumn);
    void squareColor();
    void printBoard();
    void moveAnt();
    void checkMax(int steps);
    void deleteBoard();
    void checkSides();

};

#endif //LANGSTONS_ANT_BOARD_HPP
