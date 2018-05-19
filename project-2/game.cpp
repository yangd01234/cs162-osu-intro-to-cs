/*********************************************************************
** Program name: Zoo Tycoon
** Author: Derek Yang
** Date:10/21/2017
** Description:This is the game class which will play the game
 * until the user loses or wishes to quit.
*********************************************************************/

#include "game.hpp"

//default constructor
Game::Game(){
    //user starts with 100,000
    bank = 100000;
    arryPos = 0;
    input = 0;
    days = 0;
}


//sets the initial variables for the game
void Game::playGame() {

    m1.appSelection("Play Zoo Tycoon"); //0
    m1.appSelection("Quit");//1

    m1.appSelection("Would you like to add 1 or 2 tigers?");//2
    m1.appSelection("Would you like to add 1 or 2 penguins?");//3
    m1.appSelection("Would you like to add 1 or 2 turtles?");//4

    m1.printSelection(2);
    v1.getValidInt("",input,2,1);
    initialInput(TigerE);


    m1.printSelection(3);
    v1.getValidInt("",input,2,1);
    initialInput(PenguinE);

    m1.printSelection(4);
    v1.getValidInt("",input,2,1);
    initialInput(TurtleE);

    std::cout<<std::endl;
    std::cout<<"Your current balance is:  "<<bank<<std::endl;

//z1.testPrint(5);
}

//goes through the turns and tells the user game over if they lose
void Game::turns(){
    bool turns = true;

    while(turns){
        z1.inc_age();
        turns = z1.gameOver(bank);
        //prints out the days and adds at the end
        std::cout<<"Today is day "<<days<<std::endl;
        if(turns){
            //random event
            randomEvent();
            //profit
            z1.profit(bank);
            z1.add_adult(bank);
            turns = continuePlaying();
            std::cout<<"Your current balance is: "<<bank<<std::endl;
        }else{
            turns = false;
        }

        days++;
    }
    z1.deleteArr();

}

//used for initial input
void Game::initialInput(A_Type type){
    for(int i = arryPos; i<arryPos+input; i++){
        z1.insertAnimal(i,type);

        std::cout<<std::endl;
        z1.subtractBank(bank,input,type);
    }
    arryPos += input;

}

//creates a random event
void Game::randomEvent() {
    int randomEvent = rand() % 4 + 1;//chooses a random event if 1-4
    std::cout<<"Random Event: "<<std::endl;
    switch (randomEvent){
        case 1:
            z1.kill_all_check();
            //sickness occurs and an animal of random type dies
            break;
        case 2:
        std::cout<<"Today's tiger bonus is: "<<z1.bonus()<<std::endl;
            //generate random bonus for tigers

            break;
        case 3:
            z1.create_all_babies();
            //baby animal is born
            break;
        case 4:
            //nothing happens
        std::cout<<"Nothing happens for the day"<<std::endl;
            break;
    }

}

//checks if the user would like to continue at the end of the day
bool Game::continuePlaying() {
    int input2 = 0;
    v1.getValidInt("Would you like to continue playing? enter 1 for yes or 2 for no\n",input2,2,1);
    if(input2 == 2){
        return false;
    } else{
        return true;
    }
}