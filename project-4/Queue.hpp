/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the queue header file.
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "QueueNode.hpp"
#include "Character.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Harrypotter.hpp"
#include "Vampire.hpp"
#include "Bluemen.hpp"



#include <iostream>
#include <string>

class Queue {
private:
    QueueNode* head;
    QueueNode* n;
public:
    Queue();
    void addBack(Character* charInD);
    QueueNode returnHead();
    void removeFront();
    void removeFrontFinal();
    void printQueue();
    void removeAllChar();
    bool isEmpty();
    int getFront();

    ~Queue();

};


#endif //FRAME_1_QUEUE_HPP
