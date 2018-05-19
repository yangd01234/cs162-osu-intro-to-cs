/*********************************************************************
** Program name: Final Project
** Author: Derek Yang
** Date:12/2/2017
** Description:This is the space header file.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include "Space.hpp"
#include "Dice.hpp"
#include <string>
class Space {
private:
    Space *left;
    Space *right;
    Space *bottom;
    Space *top;
    std::string name;
    std::string description;

    int difficulty;
    int seratoninDec;
    bool cleared = false;


public:
    Space();
    void setLeft(Space* spaceIn);
    void setRight(Space* spaceIn);
    void setBottom(Space* spaceIn);
    void setTop(Space* spaceIn);
    void setName(std::string nameIn);
    void setDescription(std::string descIn);
    void setDifficulty(int difIn);
    void setCleared();
    void setSeratoninDec(int decIn);
    //function to return the item amount
    virtual int getItemTA() = 0;

    Space* getLeft();
    Space* getRight();
    Space* getTop();
    Space* getBottom();

    std::string getName();
    std::string getDesc();
    int getDifficulty();
    int getSeratoninDec();
    bool getCleared();


    ~Space();

};


#endif
