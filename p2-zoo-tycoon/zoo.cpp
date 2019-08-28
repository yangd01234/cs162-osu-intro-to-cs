/*********************************************************************
** Program name: Zoo Tycoon
** Author: Derek Yang
** Date:10/21/2017
** Description:This is zoo class for the zoo tycoon program.  This
 * class will set three arrays of different animal types and then
 * have helper functions to play the game.
*********************************************************************/

#include "zoo.hpp"

//default constructor for zoo
Zoo::Zoo(){
    //create a dynamic array of size
    tiger_arr_size = 10;
    turtle_arr_size = 10;
    penguin_arr_size = 10;

    //these are used to check the size of the arr
    tiger_babies_check = 0;
    turtle_babies_check = 0;
    penguin_babies_check = 0;

    //create new dynamic array
    tigerArr = new Tiger[10];
    turtleArr = new Turtle[10];
    penguinArr = new Penguin[10];

    //daily profit and base food cost
    daily_profit = 0;
    base_food_cost = 10;
}

//Deletes all the animal arrays
void Zoo::deleteArr() {
    delete[] tigerArr;
    delete[] turtleArr;
    delete[] penguinArr;
}

//inserts the animal into the array position
void Zoo::insertAnimal(int arrPos, A_Type typeIn) {
    //creates a new animal of type in the array position, sets it, and adds to baby checker
    if (typeIn == TigerE){
        tigerArr[arrPos] = Tiger();
        tigerArr[arrPos].set_tiger();
        tiger_babies_check += 1;

    } else if (typeIn == PenguinE){
        penguinArr[arrPos] = Penguin();
        penguinArr[arrPos].set_penguin();
        penguin_babies_check += 1;

    } else {
        //turtle
        turtleArr[arrPos] = Turtle();
        turtleArr[arrPos].set_turtle();
        turtle_babies_check += 1;

    }
}


//copies and resizes the array by 2x for each type
void Zoo::resizeArr(A_Type typeIn) {

    if (typeIn == TigerE){
        //resize tiger array
        Tiger *dummyArr; //temporary array
        dummyArr = new Tiger[tiger_arr_size*2]; //doubles capacity for dummy arr
        for(int i = 0; i<tiger_arr_size; i++){//copies current arr into dummy
            dummyArr[i] = tigerArr[i];
        }
        delete[] tigerArr;//deletes tiger arr

        tiger_arr_size *=2; //doubles arr size
        tigerArr = new Tiger[tiger_arr_size];
        for(int i = 0; i<tiger_arr_size; i++){
            tigerArr[i] = dummyArr[i];
        }
        delete[] dummyArr;
        std::cout<<"resizing tiger array"<<std::endl;

    } else if (typeIn == PenguinE){
        //resize penguin array
        Penguin *dummyArr; //temporary array
        dummyArr = new Penguin[penguin_arr_size*2]; //doubles capacity for dummy arr
        for(int i = 0; i<penguin_arr_size; i++){//copies current arr into dummy
            dummyArr[i] = penguinArr[i];
        }
        delete[] penguinArr;//deletes tiger arr

        penguin_arr_size *=2; //doubles arr size
        penguinArr = new Penguin[penguin_arr_size];
        for(int i = 0; i<penguin_arr_size; i++){
            penguinArr[i] = dummyArr[i];
        }
        delete[] dummyArr;
        std::cout<<"resizing penguin array"<<std::endl;

    } else {
        //resize turtle array
        Turtle *dummyArr; //temporary array
        dummyArr = new Turtle[turtle_arr_size*2]; //doubles capacity for dummy arr
        for(int i = 0; i<turtle_arr_size; i++){//copies current arr into dummy
            dummyArr[i] = turtleArr[i];
        }
        delete[] turtleArr;//deletes tiger arr

        turtle_arr_size *=2; //doubles arr size
        turtleArr = new Turtle[turtle_arr_size];
        for(int i = 0; i<turtle_arr_size; i++){
            turtleArr[i] = dummyArr[i];
        }
        delete[] dummyArr;
        std::cout<<"resizing turtle array"<<std::endl;
    }
}

//kills animal of type and returns true if killed
bool Zoo::kill_animal(A_Type typeIn) {
    bool killed = false;
    switch (typeIn) {
        case TigerE:
            //kill tiger
            for (int i = 0; i < tiger_arr_size; i++) {
                //if tiger in array pos is not dead and if  not killed
                if ((!tigerArr[i].dead_status()) && (!killed)) {
                    tigerArr[i].kill_animal();
                    killed = true;
                    std::cout<<"Tiger was killed"<<std::endl;
                }
            }
            if(killed == false){
                std::cout<<"No Tigers can be killed"<<std::endl;
            }
            break;
        case TurtleE:
            //kill turtle
            for (int i = 0; i < turtle_arr_size; i++) {
                //if turtle in array pos is not dead and if  not killed
                if ((!turtleArr[i].dead_status()) && (!killed)) {
                    turtleArr[i].kill_animal();
                    killed = true;
                    std::cout<<"Turtle was killed"<<std::endl;
                }
            }
            if(killed == false){
                std::cout<<"No Turtles can be killed"<<std::endl;
            }
            break;
        case PenguinE:
            //kill penguin
            for (int i = 0; i < penguin_arr_size; i++) {
                //if penguin in array pos is not dead and if  not killed
                if ((!penguinArr[i].dead_status()) && (!killed)) {
                    penguinArr[i].kill_animal();
                    killed = true;
                    std::cout<<"Penguin was killed"<<std::endl;
                }
            }
            if(killed == false){
                std::cout<<"No Penguins can be killed"<<std::endl;
            }
            break;
    }
    //returns that true if killed
return killed;
}
//checks if all types are killable and loops until something is killed
void Zoo::kill_all_check(){
    bool somethingKilled = false;

    bool triggerOne = true;
    bool triggerTwo = true;
    bool triggerThree = true;

    //if all three have been triggered, then do not execute
    while(triggerOne || triggerTwo || triggerThree){
        int randomKillType = rand() % 3 + 1;//chooses rand from range 1 to 3 to kill
        switch (randomKillType){
            case 1:
                if(triggerOne) {
                    if (!somethingKilled) {//if something was killed then do not execute
                        somethingKilled = kill_animal(TigerE);
                    } else {
                        somethingKilled = true;
                    }
                }
                triggerOne = false;
                break;
            case 2:
                if(triggerTwo) {
                    if (!somethingKilled) {
                        somethingKilled = kill_animal(TurtleE);
                    } else {
                        somethingKilled = true;
                    }
                }
                triggerTwo = false;
                break;
            case 3:
                if(triggerThree) {
                    if (!somethingKilled) {
                        somethingKilled = kill_animal(PenguinE);
                    } else {
                        somethingKilled = true;
                    }
                }
                triggerThree = false;
                break;
        }
    }

    if(!somethingKilled){
        std::cout<<"No animals were killed"<<std::endl;
    }

}

//increases age by 1 to all if not dead
void Zoo::inc_age() {
    //loops through the current tiger array
    for(int i = 0; i<tiger_arr_size; i++){
        //if the tiger arr is not dead or not existing add 1 to age
        if(!tigerArr[i].dead_status()){
            int ageNew = tigerArr[i].get_age()+1;
            tigerArr[i].set_age(ageNew);
        }

    }

    for(int i = 0; i<turtle_arr_size; i++){
        //if the turtle arr is not dead or not existing add 1 to age
        if(!turtleArr[i].dead_status()){
            int ageNew = turtleArr[i].get_age()+1;
            turtleArr[i].set_age(ageNew);
        }

    }
    for(int i = 0; i<penguin_arr_size; i++){
        //if the penguin arr is not dead or not existing add 1 to age
        if(!penguinArr[i].dead_status()){
            int ageNew = penguinArr[i].get_age()+1;
            penguinArr[i].set_age(ageNew);
        }

    }

}

//returns the total random bonus for all tigers
double Zoo::bonus() {
    double randomBonus = rand() % 250 + 250;
    double totalBonus = 0;

    for(int i = 0; i<tiger_arr_size; i++){
        //if the animal is not dead and is a tiger, then add to total random bonus
        if (!tigerArr[i].dead_status()){
            totalBonus += randomBonus;
        }
    }
    daily_profit += totalBonus;
    return totalBonus;
}

//checks if animal type is adult and creates baby if possible
bool Zoo::checkBaby(A_Type typeIn) {

    bool born = false;
    switch (typeIn) {
        case TigerE:
            //create tiger
            for (int i = 0; i < tiger_arr_size; i++) {
                //if tiger in array pos is not dead and if  not killed
                if ((tigerArr[i].get_age() > 2) && (!born)){
                    tigerBaby();
                    born= true;
                    std::cout<<"Tiger was born"<<std::endl;
                }
            }
            if(born == false){
                std::cout<<"No Tigers can be born"<<std::endl;
            }
            break;
        case TurtleE:
            //create turtle
            for (int i = 0; i < turtle_arr_size; i++) {
                //if turtle in array pos is not dead and if  not killed
                if ((turtleArr[i].get_age()>2) && (!born)) {
                    turtleBaby();
                    born = true;
                    std::cout<<"Turtles were born"<<std::endl;
                }
            }
            if(born == false){
                std::cout<<"No Turtles can be born"<<std::endl;
            }
            break;
        case PenguinE:
            //create penguin
            for (int i = 0; i < penguin_arr_size; i++) {
                //if penguin in array pos is not dead and if  not killed
                if ((penguinArr[i].get_age()>2) && (!born)) {
                    penguinBaby();
                    born = true;
                    std::cout<<"Penguins were born"<<std::endl;
                }
            }
            if(born == false){
                std::cout<<"No Penguins can be born"<<std::endl;
            }
            break;
    }
    //returns that true if born
    return born;
}


//creates babies by random, will loop until baby is created
void Zoo::create_all_babies(){
    bool somethingBorn = false;

    bool triggerOne = true;
    bool triggerTwo = true;
    bool triggerThree = true;

    //if all three have been triggered, then do not execute
    while(triggerOne || triggerTwo || triggerThree){
        int randomBornType = rand() % 3 + 1;//chooses rand from range 1 to 3 to kill
        switch (randomBornType){
            case 1:
                if(triggerOne) {
                    if (!somethingBorn) {//if something was born then do not execute
                        somethingBorn = checkBaby(TigerE);
                    } else {
                        somethingBorn = true;
                    }
                }

                triggerOne = false;
                break;
            case 2:
                if(triggerTwo) {
                    if (!somethingBorn) {
                        somethingBorn = checkBaby(TurtleE);
                    } else {
                        somethingBorn = true;
                    }
                }
                triggerTwo = false;
                break;
            case 3:
                if(triggerThree) {
                    if (!somethingBorn) {
                        somethingBorn = checkBaby(PenguinE);
                    } else {
                        somethingBorn = true;
                    }
                }
                triggerThree = false;
                break;
        }
    }

    if(!somethingBorn){
        std::cout<<"No animals were born"<<std::endl;
    }

}



//creates tiger babies with age 0
void Zoo::tigerBaby() {
    if(tiger_babies_check+1 > tiger_arr_size){ //if the current array size cant handle, double size
        resizeArr(TigerE);
    }
    insertAnimal(tiger_babies_check, TigerE);
    tigerArr[tiger_babies_check].set_age(0);
}

//creates turtle babies with age 0
void Zoo::turtleBaby() {
    if(turtle_babies_check+10 > turtle_arr_size){ //if the current array size cant handle, double size
        resizeArr(TurtleE);
    }
    insertAnimal(turtle_babies_check, TurtleE);
    turtleArr[turtle_babies_check].set_age(0);
}

//creates penguin babies with age 0
void Zoo::penguinBaby() {
    if(penguin_babies_check+5 > penguin_arr_size){ //if the current array size cant handle, double size
        resizeArr(PenguinE);
    }
    insertAnimal(penguin_babies_check, PenguinE);
    penguinArr[penguin_babies_check].set_age(0);
}

//returns the daily profit
void Zoo::profit(double &bankIn){
    //calculates tiger profit
    for(int i = 0; i<tiger_arr_size; i++){
        daily_profit += tigerArr[i].get_payoff()*10000;
    }

    //calculates turtle profit
    for(int i = 0; i<turtle_arr_size; i++){
        daily_profit += turtleArr[i].get_payoff()*100;
    }

    //calculates penguin profit
    for(int i = 0; i<penguin_arr_size; i++){
        daily_profit += penguinArr[i].get_payoff()*1000;
    }

    std::cout<<"Today's daily profit is : "<<daily_profit<<std::endl;

    bankIn +=daily_profit;
    daily_profit = 0;
}

//add adult animal
void Zoo::add_adult(double &bankIn) {
    int input = 0;
    bool inputVal = true;

    while(inputVal){
        v1.getValidInt("Would you like to add an animal? \n1: Add Tiger, \n2: add Turtle \n3: add penguin \n4:Do not buy\n",
                       input, 4, 1);
        switch (input){
            case 1://tiger
                if(bankIn<10000){
                    std::cout<<"Not enough money to buy a tiger, try again."<<std::endl;
                } else {
                    inputVal = false;
                }
                break;
            case 2://turtle
                if(bankIn<100){
                    std::cout<<"Not enough money to buy a turtle, try again."<<std::endl;
                } else {
                    inputVal = false;
                }
                break;
            case 3://penguin
                if(bankIn<1000){
                    std::cout<<"Not enough money to buy a penguin, try again."<<std::endl;
                } else {
                    inputVal = false;
                }
                break;
            case 4:
                //nothing happens
                inputVal = false;
                break;
        }
    }

    switch (input){
        case 1:
            if(tiger_babies_check+2 > tiger_arr_size){ //if the current array size cant handle, double size
                resizeArr(TigerE);
            }
            insertAnimal(tiger_babies_check,TigerE);
            tigerArr[tiger_babies_check].set_age(3);
        std::cout<<"added adult tiger"<<std::endl;
            break;
        case 2:
            if(turtle_babies_check+2 > turtle_arr_size){ //if the current array size cant handle, double size
                resizeArr(TurtleE);
            }
            insertAnimal(turtle_babies_check,TurtleE);
            turtleArr[turtle_babies_check].set_age(3);
            std::cout<<"added adult turtle"<<std::endl;
            break;
        case 3:
            if(penguin_babies_check+2 > penguin_arr_size){ //if the current array size cant handle, double size
                resizeArr(PenguinE);
            }
            insertAnimal(penguin_babies_check,PenguinE);
            penguinArr[penguin_babies_check].set_age(3);
            std::cout<<"added adult penguin"<<std::endl;
            break;
        case 4:
        std::cout<<"No animals bought"<<std::endl;
            break;
    }
}

//calculates the feed cost and returns game over if user can not pay
bool Zoo::gameOver(double &bankIn) {
    //calculate total feed cost
    double totalFeed = 0;
    bool game = true;

    //calculates the tiger food cost
    for(int i = 0; i<tiger_arr_size; i++){
        totalFeed += tigerArr[i].get_base_food_cost()*base_food_cost;
    }

    //calculates turtle food cost
    for(int i = 0; i<turtle_arr_size; i++){
        totalFeed += turtleArr[i].get_base_food_cost()*base_food_cost;
    }

    //calculates penguin food cost
    for(int i = 0; i<penguin_arr_size; i++){
        totalFeed += penguinArr[i].get_base_food_cost()*base_food_cost;
    }

    std::cout<<"Today's daily food cost is : "<<totalFeed<<std::endl;

    if(bankIn<totalFeed){//if total feed cost is more than bank
        //game over
        std::cout<<"GAME OVER"<<std::endl;
        game = false;
    } else{
        //game continues
        bankIn -= totalFeed;
    }



    return game;
}

//subtracts amount from bank
void Zoo::subtractBank(double &bankIn, int quantIn, A_Type typeIn){
    switch(typeIn){
        case TigerE:
            bankIn -= (10000*quantIn);
            break;
        case TurtleE:
            bankIn -= (100*quantIn);
            break;
        case PenguinE:
            bankIn -= (1000*quantIn);
            break;

    }
}