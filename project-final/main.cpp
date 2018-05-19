/*********************************************************************
** Program name: Final Project
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the main file for the program.  This file will
 * create the room and call objects to play the game.
*********************************************************************/

#include <iostream>
#include "Menu.hpp"
#include "Validation.hpp"
#include "Course.hpp"


int main() {

    Menu m1;
    Validation v1;
    Course c1;
    int input = 0;
    bool play = true;


    m1.appSelection("=====================================================================================================");


    m1.appSelection("Welcome to the Brain and Heart game");
    m1.appSelection("In this game, you will guide our two main characters: Brain and Heart");
    m1.appSelection("Brain is the more logical fellow, but doesn't have much fun.");
    m1.appSelection("Heart follows his gut feeling and is the spontaneous of the two.");
    m1.appSelection("Your job is to guide Brain and Heart through the turmoils of a quarter of CS 162.");
    m1.appSelection("Each room in this game represents selected parts and topics of CS162");
    m1.appSelection("The player will need to go through the rooms and collect serotonin to play the game.");
    m1.appSelection("Each room has a TA, aka Temper Analyzer.");
    m1.appSelection("The TA will analyze heart's current temper and give serotonin to brain.");
    m1.appSelection("Brain uses serotonin to calm Heart down. If the user runs out of serotonin, Brain and Heart will explode.");
    m1.appSelection("The player then loses the game and does not continue.");
    m1.appSelection("TA's are hidden within topic rooms.  The player will need to navigate the room in order to find the TA");
    m1.appSelection("Once the player has found the TA, they will receive a random amount of serotonin.");
    m1.appSelection("The TA's will also assign a pass/fail for the topic room.  Think of this as an item to collect.");
    m1.appSelection("The TA and player will roll a dice and if the player rolls a higher number, they will receive a pass.");
    m1.appSelection("The player will need to collect MAX 5 out of 6 topic masteries.");
    m1.appSelection("When the player navigates past the major topics and reaches the end, they will win the game.");
    //19

    m1.appSelection("1. Start Game");
    m1.appSelection("2. Quit");




    m1.printRange(0,18);
    m1.printRange(19,19);
    m1.printRange(0,0);

    v1.getValidInt("",input,2,1);

    if(input == 2){
        play = false;
    }
    c1.linkRooms();

    while (play){
        c1.navigate(play);
    }
    return 0;
}