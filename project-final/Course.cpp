/*********************************************************************
** Program name: Final Project
** Author: Derek Yang
** Date:12/2/2017
** Description: Course class for the final project.  This class links
 * each room together and sets the stats for the rooms.  The class
 * will also allow the user to traverse the game, print the map, and
 * delete any initialized rooms.
*********************************************************************/

#include "Course.hpp"

Course::Course() {

    current = t1;
    serotonin = 20;
}

void Course::linkRooms() {
    t1->setName("Pointers Pointers Pointers..");
    t1->setDescription("This room is full of pointers and memory leaks..."
                               "\nroll an easy die to show the TA that you can patch these up.");
    t1->setDifficulty(20);
    t1->setRight(t2);
    t1->setLeft(t6);
    t1->setTop(t4);
    t1->setSeratoninDec(1);


    t2->setName("Langston's Ant and MORE Pointers");
    t2->setDescription("This room is full of Ants! Langston's ants to be exact."
                               " Heart feels a lot of anxiety in this room."
                               "\nroll a hard die to show the TA that you can defeat the ants.");
    t2->setDifficulty(10);
    t2->setLeft(t1);
    t2->setTop(t3);
    t2->setSeratoninDec(7);

    t3->setName("Ferocious Files");
    t3->setDescription("This room is full of random files. Clean up the files with a simple sort and write new notes."
                               " Brain is looking forward to organizing this room."
                               "\nroll an easy die to show the TA that you can navigate the files.");
    t3->setDifficulty(20);
    t3->setLeft(t4);
    t3->setBottom(t2);
    t3->setSeratoninDec(3);

    t4->setName("Inheritance and Polymorphism-isms");
    t4->setDescription("This room is full of weird polymorphisms and classes. "
                               "Associate the parents with childs.  "
                               "\nroll a hard die to show the TA that you can use polymorphism.");
    t4->setDifficulty(10);
    t4->setLeft(t5);
    t4->setRight(t3);
    t4->setBottom(t1);
    t4->setTop(tFinal);
    t4->setSeratoninDec(5);

    t5->setName("Not losing your links over linked structures");
    t5->setDescription("This room is full of different data structure types and unlinked nodes. "
                               "Show the TA that you can link nodes together. "
                               "\nroll a medium die to show the TA that you can link nodes.");
    t5->setDifficulty(15);
    t5->setBottom(t6);
    t5->setRight(t4);
    t5->setSeratoninDec(5);

    t6->setName("Stacks and Queues, not pancakes nor waiting lines");
    t6->setDescription("This room is filled with stacks and queues. "
                               "Show the TA that you can delete the data structures to free room. "
                               "\nroll an easy die to show the TA that you can delete stacks and queues.");
    t6->setDifficulty(15);
    t6->setRight(t1);
    t6->setTop(t5);
    t6->setSeratoninDec(5);

    tFinal->setName("Final FINALLY!");
    tFinal->setDescription("This is the final room. "
                                   "The instructor in the room will inspect your topics and pass you if you have enough masteries.");
    tFinal->setBottom(t4);
    tFinal->setSeratoninDec(1);
}

//navigates the rooms
bool Course::navigate(bool &playIn) {

    //while the player hasn't collected all the topics
    while(!collectedAll && (serotonin > 0 )){

        std::cout<<"Where would you like to go?"<<std::endl;
        //print map
        printMap();
        v1.getValidInt("",input,locations.size()-1,0);

        int serGain = rand() % 3 +1;
        serotonin += serGain;
        std::cout<<"Gained "<<serGain<<" serotonin from the brisk walk to another topic."<<std::endl;

        //calculates new seratonin
        serotonin -= current->getSeratoninDec();
        std::cout<<"Removed: "<<current->getSeratoninDec()<<" serotonin"<<std::endl;
        std::cout<<"Serotonin level: "<<serotonin<<std::endl;

        if(serotonin<=0){
            std::cout<<"Brain didn't get enough serotonin and Heart exploded from the stress! you lose...."<<std::endl;
            playIn = false;
        } else {

            current = locations.at(input);
            locations.clear();
            directions.clear();

            //room description
            std::cout << "Welcome to: " << current->getName() << std::endl;
            std::cout << current->getDesc() << std::endl;

            //check if final room
            if (current->getName() == "Final FINALLY!") {
                //print current masteries
                for (int i = 0; i < masteries.size(); i++) {
                    std::cout << i + 1 << " Mastery: " << masteries.at(i) << std::endl;
                }
                //check if have enough masteries
                if (5 == masteries.size()) {
                    std::cout << "The instructor has evaluated your masteries.  Congrats! You passed the course."
                              << std::endl;
                    std::cout << "Brain and heart are now free to pursue what they want the most!" << std::endl;
                    std::cout << "You now have a huge supply of serotonin to get you through the next few weeks"
                              << std::endl;
                    collectedAll = true;
                    playIn = false;
                } else {
                    std::cout << "You do not have enough to pass the course. Go and collect some more" << std::endl;
                }
            } else {
                //room function
                if (!current->getCleared()) {
                    std::cout << "The TA is checking your mastery." << std::endl;
                    if (current->getItemTA() < current->getDifficulty()) { //if TA output is less than difficulty
                        addMastery();
                        current->setCleared();
                    } else {
                        std::cout << "You didn't pass the test...try other topics and then come back to this one."
                                  << std::endl;
                    }
                } else {
                    std::cout << "You've already cleared this mastery." << std::endl;
                }

            }
        }
    }
}

//adds mastery to vector as string.  Max 5 masteries
void Course::addMastery() {
    if(masteries.size()<5){
        masteries.push_back(current->getName());
        std::cout<<"You've aquired the "<<current->getName()<<" Mastery!"<<std::endl;
    } else {
        std::cout<<"Too many masteries..you can't collect any more.  Navigate to the room final FINALLY!"<<std::endl;
    }
}

//prints the map IF locations are not NULL.
void Course::printMap() {
    std::cout<<"Current map:"<<std::endl;
    if(current->getLeft() != NULL) locations.push_back(current->getLeft());
    if(current->getRight() != NULL) locations.push_back(current->getRight());
    if(current->getTop() != NULL) locations.push_back(current->getTop());
    if(current->getBottom() != NULL) locations.push_back(current->getBottom());

    if(current->getLeft() != NULL) directions.push_back("Left - ");
    if(current->getRight() != NULL) directions.push_back("Right - ");
    if(current->getTop() != NULL) directions.push_back("Top - ");
    if(current->getBottom() != NULL) directions.push_back("Bottom - ");

    for(int i = 0; i<locations.size(); i++){
        std::cout<<i<<". "<<directions.at(i)<<" "<<locations.at(i)->getName()<<std::endl;
    }
}

Course::~Course() {
    delete t1;
    delete t2;
    delete t3;
    delete t4;
    delete t5;
    delete t6;
    delete tFinal;
}