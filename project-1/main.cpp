/*********************************************************************
** Program name: Langston's Ant
** Author: Derek Yang
** Date: 9/26/2017
** Description: This is an implementation of the Langston's Ant
 * algorithm.  The ant will travel a grid where the size is defined
 * by the user.  There will be blank spaces to start.  If an ant
 * lands on a blank square, it will turn 90 degrees to the right
 * and turn the square black.  If the ant lands on a black square,
 * it will turn 90 degrees to the left and turn the square white.
 * If the ant hits the wall, it will turn around.
*********************************************************************/

#include <iostream>
#include "board.hpp"
#include "validation.hpp"

//menu function to run langston's ant.
void menu(){
    int width, height, steps, startRow, startColumn;
    bool play = true;
    //strings for menu
    std::string start = "Start Langston's Ant Simulation";
    std::string random = "Start Random Langston's Ant Simulation";
    std::string quit = "Quit";



//loops and asks the user to play until they quit
    while (play) {
        //creates validation obj
        Validation v1;
        int choice = v1.startGame(start, random, quit);

        //menu option 1 asks for all variables
        if (choice == 1) {
            //change input variables with new menu
            v1.getValidInt("Enter grid width: ", width, 2147483647, 1);
            v1.getValidInt("Enter grid height: ", height, 2147483647, 1);
            v1.getValidInt("Enter the number of steps: ", steps, 2147483647, 1);
            v1.getValidInt("Enter the starting row: ", startRow, height - 1, 0);
            v1.getValidInt("Enter the starting column: ", startColumn, width - 1, 0);

            //put option 1 items below this line
            Board b1(width, height, startRow, startColumn);
            b1.checkMax(steps);
            b1.deleteBoard();

            //menu option 2 gives random starting location
        } else if (choice == 2) {
            v1.getValidInt("Enter grid width: ", width, 2147483647, -2147483647);
            v1.getValidInt("Enter grid height: ", height, 2147483647, -2147483647);
            v1.getValidInt("Enter the number of steps: ", steps, 2147483647, -2147483647);
            startRow = rand() % height;
            startColumn = rand() % width;
            std::cout << startRow << "   " << startColumn << std::endl;
            Board b1(width, height, startRow, startColumn);
            b1.checkMax(steps);
            b1.deleteBoard();
            //execute game
        } else{
            play = false;
        }
    }

}
int main() {

    //menu function
    menu();
    //variables to store for menu input


    return 0;
}