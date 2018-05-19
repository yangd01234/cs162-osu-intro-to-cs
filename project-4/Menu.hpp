/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the menu header file.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP


#include <vector>
#include <string>
#include <iostream>

class Menu {
public:
    Menu();
    void appSelection(std::string selectionIn);
    void printSelection(int loc);
    void printRange(int start, int end);

    ~Menu();

private:
    std::vector <std::string> options;
};


#endif
