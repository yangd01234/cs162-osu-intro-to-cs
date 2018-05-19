/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the doubleLink class header file.
*********************************************************************/

#ifndef DOUBLELINK_HPP
#define DOUBLELINK_HPP

#include "Node.hpp"
class doubleLink {
private:
    node* head;
    node* tail;
    node* n; //helps us build the double-linked list

public:
    doubleLink();
    void firstNode(Character* charInD);
    void traverse();
    void deleteFirstNode();
    void deleteLastNode();
    void deleteAll();
    ~doubleLink();
};


#endif //FRAME_1_DOUBLELINK_HPP
