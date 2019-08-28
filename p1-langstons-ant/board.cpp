/*********************************************************************
** Program name: Langston's Ant
** Author: Derek Yang
** Date: 9/26/2017
** Description: This is the grid class for langstons ant.  Here the
 * ant will be moved and the class will call upon the ant class
 * to get and set the ant location and grid orientation.
*********************************************************************/

#include "board.hpp"
#include <iostream>

Board::Board(int columnMax, int rowMax, int startRow, int startColumn) {
    row = rowMax;
    column = columnMax;
    antCurrent.setX(startRow);
    antCurrent.setY(startColumn);

    //a 2d dynamic array aka an array of pointers to arrays
    newBoard = new char*[rowMax];

    //creates a loop to create column arrays
    for (int i = 0; i<rowMax; i++){
        newBoard[i] = new char[columnMax];
    }

    //inserts the * char to newly made 2d array
    for (int i = 0; i<rowMax; i++){
        for(int j=0; j<columnMax; j++) {
            newBoard[i][j] = ' ';
        }
    }
    //gets the current color the ant is on
    cColor = antCurrent.getCurrentColor();

    //gets the ant's direction
    cDirection = antCurrent.getDirection();

    cAntX = antCurrent.getAntX();
    cAntY = antCurrent.getAntY();

    //create an ant object at the current ant location
    newBoard[cAntX][cAntY] = '*';
}

//prints board
void Board::printBoard(){
    for (int i = 0; i<row; i++){
        for (int j = 0; j<column; j++){
            std::cout<<newBoard[i][j];
        }
        std::cout<<std::endl;
    }
}

//sets the square color to the opposite color and saves the orientation
void Board::squareColor(){
    if(antCurrent.getCurrentColor() == '#'){
        newBoard[cAntX][cAntY] = ' ';
        antCurrent.setCurrentColor(' ');
        antCurrent.setRL(Left);

    }
    else if(antCurrent.getCurrentColor() == ' '){
        newBoard[cAntX][cAntY] = '#';
        antCurrent.setCurrentColor('#');
        antCurrent.setRL(Right);
    }
}


/*this will change the current ant x and y.  For sake of readability, I used cAntX and cAntY
instead of antCurrent.setX and antCurrent.setY.  */
void Board::moveAnt(){

    if(((antCurrent.getRL()==Right) && (antCurrent.getDirection() == North))||
       ((antCurrent.getRL() == Left) && (antCurrent.getDirection() == South))){
        antCurrent.setDirection(East);
        cAntX+=1;
    }

    else if(((antCurrent.getRL()==Right) && (antCurrent.getDirection() == East))||
            ((antCurrent.getRL() == Left) && (antCurrent.getDirection() == West))){
        antCurrent.setDirection(South);
        cAntY+=-1;
    }

    else if(((antCurrent.getRL()==Right) && (antCurrent.getDirection() == West))||
            ((antCurrent.getRL() == Left) && (antCurrent.getDirection() == East))){
        antCurrent.setDirection(North);
        cAntY +=1;
    }

    else if(((antCurrent.getRL()==Right) && (antCurrent.getDirection() == South))||
            ((antCurrent.getRL() == Left) && (antCurrent.getDirection() == North))){
        antCurrent.setDirection(West);
        cAntX+=-1;
    }

}

/*this will check the max number of steps and executes the langston's ant protocol
using the classes and objects listed above.*/
void Board::checkMax(int steps) {
    printBoard();
    int iCount = 0;
    //checks to make sure the ant is within the number of steps
    while(iCount<steps) {

        squareColor();
        moveAnt();
        //checks if the ant is still within bounds
        if (cAntX < row && cAntY < column && cAntX >= 0 && cAntY >= 0){
            antCurrent.setCurrentColor(newBoard[cAntX][cAntY]);
            newBoard[cAntX][cAntY] = '*';
            printBoard();
            iCount++;

        } else {
            //this will check the max and if so, turn around the ant
            checkSides();
            printBoard();
            iCount++;
        }
    }


}

//deletes the dynamically allocated 2d array to prevent memory leaks
void Board::deleteBoard(){
    //first delete the sub-arrays
    for (int i = 0; i<column;i++){
        delete[] newBoard[i];
    }
    //next delete the array of pointers
    delete[] newBoard;
}

/*reverse ant and checks if the ant is out of bounds.
IF the ant is out of bounds, it will be turned around*/
void Board::checkSides(){
    if(cAntX < 0){
        cAntX = 0;
        antCurrent.setDirection(South);
    } else if(cAntY < 0){
        cAntY = 0;
        antCurrent.setDirection(West);
    } else if (cAntX>=row){
        cAntX = row-1;
        antCurrent.setDirection(North);
    } else if (cAntY >= column){
        cAntY = column-1;
        antCurrent.setDirection(East);
    }
}
