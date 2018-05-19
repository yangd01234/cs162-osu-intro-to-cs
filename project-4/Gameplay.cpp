/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the gameplay class. This class will build the
 * menu and is a driver class to try out each of the characters in a
 * tournement.  The class will reference a doubly linked list and
 * a circular list to build a tournement.
*********************************************************************/

#include "Gameplay.hpp"


Gameplay::Gameplay(){
    numberFighters = 0;
}

//builds the menu
void Gameplay::buildMenu() {
    m1.appSelection("Please input the number of fighters per team");

    m1.appSelection("Please select the number of "); //0
    m1.appSelection("INPUT 1 for Vampire"); //1
    m1.appSelection("INPUT 2 for Barbarian"); //2
    m1.appSelection("INPUT 3 for Blue Men"); //3
    m1.appSelection("INPUT 4 for Medusa"); //4
    m1.appSelection("INPUT 5 for Harry Potter"); //5
    m1.appSelection("1.  Play again"); //6
    m1.appSelection("2.  Exit the game"); //7
}

//gest the initial input from the user to choose characters
void Gameplay::getInput() {

    //Asks for and inputs the number of fighters
    m1.printRange(0,0);
    v1.getValidInt("",numberFighters,2147483647,1);

    //choose type of character and enter name for fighter
    getPlayerSet("Player A");
}

//sets the characters of the users
void Gameplay::setCharacter(int inputIn, Queue &qIn,std::string nameIn) {
    //Character* characterIn;
    /*
    switch (inputIn){
        case 1:
            characterIn = new Vampire();
            characterIn->setCustomName(nameIn);
            qIn.addBack(characterIn);
            break;
        case 2:
            characterIn = new Barbarian();
            characterIn->setCustomName(nameIn);
            qIn.addBack(characterIn);
            break;
        case 3:
            characterIn = new Bluemen();
            characterIn->setCustomName(nameIn);
            qIn.addBack(characterIn);
            break;
        case 4:
            characterIn = new Medusa();
            characterIn->setCustomName(nameIn);
            qIn.addBack(characterIn);
            break;
        case 5:
            characterIn = new Harrypotter();
            characterIn->setCustomName(nameIn);
            qIn.addBack(characterIn);
            break;
    }
     */

    if(inputIn == 1){
        Character* characterIn = new Vampire();
        characterIn->setCustomName(nameIn);
        qIn.addBack(characterIn);
    } else if (inputIn == 2){
        Character* characterIn = new Barbarian();
        characterIn->setCustomName(nameIn);
        qIn.addBack(characterIn);
    } else if (inputIn == 3){
        Character* characterIn = new Bluemen();
        characterIn->setCustomName(nameIn);
        qIn.addBack(characterIn);
    } else if (inputIn == 4) {
        Character* characterIn = new Medusa();
        characterIn->setCustomName(nameIn);
        qIn.addBack(characterIn);
    } else {
        Character* characterIn = new Harrypotter();
        characterIn->setCustomName(nameIn);
        qIn.addBack(characterIn);
    }

}

//individual rounds
void Gameplay::subRound(Character*& characterInOne, std::string playerInOne, Character*& characterInTwo, std::string playerInTwo){

    //UNCOMMENT TO TEST INDIVIDUAL CHARACTERS
    //std::cout<<playerInOne<<" type:  "<<characterInOne->getName()<<std::endl;
    //std::cout<<playerInTwo<<":  "<<characterInTwo->getName()<<std::endl;
    //std::cout<<playerInTwo<<" Armor:  "<<characterInTwo->getArmor()<<std::endl;
    //std::cout<<playerInTwo<<" Strength:  "<<characterInTwo->getStrength()<<std::endl;
    //std::cout<<playerInOne<<" Attacks!"<<std::endl;
    int atk = attackTurn(characterInOne);
    //UNCOMMENT TO TEST INDIVIDUAL CHARACTERS
    //std::cout<<playerInOne<<" Attack:  "<<atk<<std::endl;
    //std::cout<<playerInTwo<<" Defends!"<<std::endl;
    int def = defenseTurn(characterInTwo, atk);
    if(def > 0){
        //std::cout<<"Actual damage:  "<<def<<std::endl;
    }else{
        //std::cout<<"Actual damage: 0"<<std::endl;
    }


    //std::cout<<playerInTwo<<" Strength:  "<<characterInTwo->getStrength()<<std::endl;
    //std::cout<<std::endl;
}


//asks the user to play again and deletes any old instances of the Character objects
void Gameplay::playAgain() {
    bool play = true;
    int playAgainIn = 1;
    buildMenu();
    getInput();
    //rounds();
    while(play){
        //delete pCharA;
        //delete pCharB;

        m1.printRange(6,7);
        v1.getValidInt("",playAgainIn,2,1);
        if(playAgainIn == 1){
            buildMenu();
            getInput();
            //rounds();
        } else{
            play = false;
        }

    }
}

//checks if the Character is dead returns true if a died, and false if b died
bool Gameplay::rounds(Character* pB, Character* pA){
    bool dead = false;
    while(!dead) {//while nothing is dead
        if (!dead) {
            subRound(pB, "Player B", pA, "Player A");

            if (pA->getStrength() <= 0) {
                std::cout << "Player A has died... Player B wins!" << std::endl;
                dead = true;
                return true;
            }
        }

        if (!dead) {
            subRound(pA, "Player A", pB, "Player B");
            if (pB->getStrength() <= 0) {
                std::cout << "Player B has died... Player A wins!" << std::endl;
                dead = true;
                return false;
            }
        }
    }
}

//attacks
int Gameplay::attackTurn(Character* charIn) {
    return charIn->attack();
}

//defends
int Gameplay::defenseTurn(Character* charIn, int atkIn) {
    return charIn->defense(atkIn);
}

//new functions
void Gameplay::getPlayerSet(std::string aorb){

    for(int i = 0; i<numberFighters; i++){
        //create a new dummy character
        int inputChar = 0;
        std::string fighterN;

        std::cout<<"Enter fighter name for A: "<<std::endl;
        v1.getValidStr("",fighterN);

        m1.printRange(1,6);
        v1.getValidInt("Select character for A: \n",inputChar,5,1);
        std::cout<<inputChar<<std::endl;
        setCharacter(inputChar,qA, fighterN);

        std::cout<<"Enter fighter name for B: "<<std::endl;
        v1.getValidStr("",fighterN);

        m1.printRange(1,6);
        v1.getValidInt("Select character for B: \n",inputChar,5,1);
        std::cout<<inputChar<<std::endl;
        setCharacter(inputChar,qB, fighterN);
    }
    std::cout<<"Player A lineup: ";
    qA.printQueue();
    std::cout<<"Player B lineup: ";
    qB.printQueue();
}

void Gameplay::traverseGame(){

    int aScore = 0;
    int bScore = 0;
    int roundCounter = 1;


    while(!qA.isEmpty() && !qB.isEmpty()) { //checks if it is not empty

        //removes the heads and keeps them
        QueueNode dummyA = qA.returnHead();
        QueueNode dummyB = qB.returnHead();


        //removes the front to re-assign later on
        qA.removeFront();
        qB.removeFront();

        if (rounds(dummyA.charIn, dummyB.charIn)) {
            //std::cout<<"test A"<<dummyA.charIn->getCustomName()<<std::endl;
            dummyB.charIn->recovery();
            qB.addBack(dummyB.charIn);
            addLoser(dummyA.charIn);

            bScore++;
            //std::cout << "Player A died" << std::endl;
            std::cout<<"Round "<<roundCounter<<": "<<"Team A - "<<dummyA.charIn->getCustomName()<<"| VS |"<<"Team B - "<<dummyB.charIn->getCustomName()<<" PLAYER B WON ROUND"<<std::endl;
        } else {
            //std::cout<<"test B"<<dummyB.charIn->getCustomName()<<std::endl;
            dummyA.charIn->recovery();
            qA.addBack(dummyA.charIn);
            addLoser(dummyB.charIn);
            aScore++;
            //std::cout << "Player B died" << std::endl;
            std::cout<<"Round "<<roundCounter<<": "<<"Team A - "<<dummyA.charIn->getCustomName()<<"| VS |"<<"Team B - "<<dummyB.charIn->getCustomName()<<" PLAYER A WON ROUND"<<std::endl;
        }
        roundCounter++;
    }


    std::cout<<"Player A score: "<<aScore<<std::endl;
    std::cout<<"Player B score: "<<bScore<<std::endl;

    if(bScore>aScore){
        std::cout<<"Player B Wins!"<<std::endl;
    } else if (aScore>bScore){
        std::cout<<"Player A Wins!"<<std::endl;
    } else {
        std::cout<<"Game ends in a tie"<<std::endl;
    }
    int loserInt = 0;
    std::cout<<"Print loser list? 1 for yes, 2 for no"<<std::endl;
    v1.getValidInt("",loserInt,2,1);

    if(loserInt == 1){
        losers.traverse();
    }

    //clear losers and team lists
    qA.removeAllChar();
    qB.removeAllChar();
    losers.deleteAll();

}

void Gameplay::removeAll(){

    while(!qA.isEmpty()){
        QueueNode dummyA = qA.returnHead();
    }
    while(!qB.isEmpty()){
        QueueNode dummyB = qB.returnHead();
        Character* testprt = dummyB.charIn;
        delete testprt;
        std::cout<<testprt->getCustomName()<<std::endl;
    }
}
void Gameplay::addLoser(Character *charIn) {
        losers.firstNode(charIn);
}

Gameplay::~Gameplay(){
}