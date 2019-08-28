/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the node class. This class holds the struct.
*********************************************************************/
#include "Node.hpp"


Node::Node() {
    n = new node;// creates a new node and makes n point to new node
}

void Node::createNode(Character* charInD) {
    n->charInD = charInD;//finds node referenced by n and sets val = valIn
    n->prev = NULL;//makes ure prev pointer is not pointing to anything
    head = n;
    tail = n;
}


Node::~Node() {

}