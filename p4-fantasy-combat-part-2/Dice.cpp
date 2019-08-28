/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the dice class.  This class will either roll
 * multiple or single.  The sides are dictated by roll().
*********************************************************************/

#include "Dice.hpp"

Dice::Dice() {
}

//rolls multiple dice
int Dice::rollMultiple(int sidesIn, int timesIn) {
    int total = 0;
    for(int i = 0; i <timesIn; i++){
        //std::cout<<total<<std::endl;
        int temp = roll(sidesIn);
        //UNCOMMENT THIS TO SEE ROLL
        //std::cout<<"Die #:"<<std::to_string(i+1)<<" Roll: "<<std::to_string(temp)<<std::endl;
        total += temp;
    }

    return total;
}

//rolls a single dice
int Dice::roll(int sidesIn) {
    //note rand() % max + min;
    return rand() % sidesIn +1;
}

Dice::~Dice() {

}