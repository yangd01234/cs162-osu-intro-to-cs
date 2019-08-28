/*********************************************************************
** Program name: Game Character vs Character
** Author: Derek Yang
** Date:10/28/2017
** Description:This is the gameplay class. This class will build the
 * menu and is a driver class to try out each of the characters.
*********************************************************************/

#include "Gameplay.hpp"


Gameplay::Gameplay(){

}

//builds the menu
void Gameplay::buildMenu() {
    m1.appSelection("Please select two characters to fight each other"); //0
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
    m1.printRange(0,5);
    v1.getValidInt("Select character A: \n",input,5,1);
    std::cout<<input<<std::endl;
    setCharacter(pCharA, input);
    v1.getValidInt("Select character B: \n",input,5,1);
    setCharacter(pCharB, input);

    std::cout<<"Character A Selected: "<<pCharA->getName()<<std::endl;
    std::cout<<"Character B Selected: "<<pCharB->getName()<<std::endl;
}

//sets the characters of the users
void Gameplay::setCharacter(Character*& characterIn,int inputIn) {

    switch (inputIn){
        case 1:
            characterIn = new Vampire();
            break;
        case 2:
            characterIn = new Barbarian();
            break;
        case 3:
            characterIn = new Bluemen();
            break;
        case 4:
            characterIn = new Medusa();
            break;
        case 5:
            characterIn = new Harrypotter();
            break;
    }
}

//individual rounds
void Gameplay::subRound(Character* characterInOne, std::string playerInOne, Character* characterInTwo, std::string playerInTwo){
    std::cout<<playerInOne<<" type:  "<<characterInOne->getName()<<std::endl;
    std::cout<<playerInTwo<<":  "<<characterInTwo->getName()<<std::endl;
    std::cout<<playerInTwo<<" Armor:  "<<characterInTwo->getArmor()<<std::endl;
    std::cout<<playerInTwo<<" Strength:  "<<characterInTwo->getStrength()<<std::endl;

    std::cout<<playerInOne<<" Attacks!"<<std::endl;
    int atk = attackTurn(characterInOne);

    std::cout<<playerInOne<<" Attack:  "<<atk<<std::endl;

    std::cout<<playerInTwo<<" Defends!"<<std::endl;
    int def = defenseTurn(characterInTwo, atk);


    if(def > 0){
        std::cout<<"Actual damage:  "<<def<<std::endl;
    }else{
        std::cout<<"Actual damage: 0"<<std::endl;
    }


    std::cout<<playerInTwo<<" Strength:  "<<characterInTwo->getStrength()<<std::endl;
    std::cout<<std::endl;
}


//asks the user to play again and deletes any old instances of the Character objects
void Gameplay::playAgain() {
    bool play = true;
    int playAgainIn = 1;
    buildMenu();
    getInput();
    rounds();
    while(play){
        delete pCharA;
        delete pCharB;

        m1.printRange(6,7);
        v1.getValidInt("",playAgainIn,2,1);
        if(playAgainIn == 1){
            buildMenu();
            getInput();
            rounds();
        } else{
            play = false;
        }

    }
}

//checks if the Character is dead
void Gameplay::rounds(){
    bool dead = false;
    while(!dead) {//while nothing is dead
        if (!dead) {
            subRound(pCharB, "Player B", pCharA, "Player A");

            if (pCharA->getStrength() <= 0) {
                std::cout << "Player A has died... Player B wins!" << std::endl;
                dead = true;
            }
        }

        if (!dead) {
            subRound(pCharA, "Player A", pCharB, "Player B");
            if (pCharB->getStrength() <= 0) {
                std::cout << "Player B has died... Player A wins!" << std::endl;
                dead = true;
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


Gameplay::~Gameplay(){

}