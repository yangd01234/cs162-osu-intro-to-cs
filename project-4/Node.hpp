/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the node class header file.  This header
 * file contians the struct.
*********************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include "QueueNode.hpp"
#include "Character.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Harrypotter.hpp"
#include "Vampire.hpp"
#include "Bluemen.hpp"

#include <iostream>
struct node {
    Character* charInD; //integer value specific node contains
    node* next;  //pointer to the next node object
    node* prev; //pointer to the previous node object
};
class Node {
private:
    node* head;
    node* tail;
    node* n; //helps us build the double-linked list
public:
    Node();
    void createNode(Character* charInD);
    ~Node();

};


#endif
