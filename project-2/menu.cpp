/*********************************************************************
** Program name:Zoo Tycoon
** Author: Derek Yang
** Date:10/14/2017
** Description:This is the reusable menu class.  This creates a vector
for the menu and allows the user to input as many menu options as they
want.
*********************************************************************/

#include "menu.hpp"


Menu::Menu() {

}

//mutator to add a menu item
void Menu::appSelection(std::string selectionIn){
    options.push_back(selectionIn);
}


//print menu item
void Menu::printSelection(int loc){
    std::cout<<options[loc]<<std::endl;
}

void Menu::printRange(int start, int end) {
    for (int i = start; i<=end; i++){
        std::cout<<options[i]<<std::endl;
    }
}

//destructor
Menu::~Menu() {

}