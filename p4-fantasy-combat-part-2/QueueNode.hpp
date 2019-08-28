/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the QueueNode header file, this creates the
 * struct class to be used in the circular linked list
*********************************************************************/


#ifndef QUEUENODE_HPP
#define QUEUENODE_HPP

#include "Character.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Harrypotter.hpp"
#include "Vampire.hpp"
#include "Bluemen.hpp"
#include <iostream>
#include <string>

struct QueueNode {
    int val;
    std::string name;
    Character* charIn;
    QueueNode* next;
    QueueNode* prev;
};


#endif
