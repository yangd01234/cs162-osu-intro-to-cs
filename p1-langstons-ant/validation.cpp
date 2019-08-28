/*********************************************************************
** Program name: Langston's Ant
** Author: Derek Yang
** Date: 9/26/2017
** Description: This is the validation class for langston's ant.
 * This will check the range of inputs and create a menu for the
 * program.
*********************************************************************/

#include "validation.hpp"


//checks the input to make sure it is an int and checks the min and max
void Validation::getValidInt(std::string ques, int &inputVar, int max, int min){
    std::cout<<ques;
    std::cin >> inputVar;

    //check size and if it is an int
    while((std::cin.fail()) || (inputVar < min) || (inputVar > max)) {
        if (std::cin.fail()){
            std::cout<<"Invalid, enter an int"<<std::endl;
        } else if(inputVar < min){
            std::cout<<"Invalid, min is "<<min<<".  Enter a larger number."<<std::endl;
        } else if(inputVar > max){
            std::cout<<"Invalid, max is "<<max<<".  Enter a smaller number."<<std::endl;
        } else {
            std::cout<<"Invalid re-enter number"<<std::endl;
        }

        /*to clear the buffer
        source: https://stackoverflow.com/questions/25475384/when-and-why-do-i-need-to-use-cin-ignore-in-c
         */
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> inputVar;
    }
}

//gives the menu options
int Validation::startGame(std::string startOp, std::string miscOp, std::string quitOp){
    int choice = 1;

    std::cout<<"Enter 1,2 or 3 for the following menu options:"<<std::endl;
    std::cout<<"1. "<<startOp<<std::endl;
    std::cout<<"2. "<<miscOp<<std::endl;
    std::cout<<"3. "<<quitOp<<std::endl;
    getValidInt(" ",choice,3,1);
    return choice;

}


