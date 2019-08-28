/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the doubleLink class.  This will contain all
 * the functions needed to run the program.
*********************************************************************/

#include "doubleLink.hpp"

//constructor to set the head and tail to NULL
doubleLink::doubleLink() {

    //think of these variables as placeholders which will be used to point later
    head = NULL; // keeps track of the head
    tail = NULL; // keeps track of the tail
}

//adds the first node to the list
void doubleLink::firstNode(Character* charInD) {


    node *n = new node;  //need to create a pointer to a new node in order to create the first node
    n->charInD = charInD;//sets the value of the first node

if(tail == NULL){ //if there is no next item then...
    head = tail = n;//sets all to n
    n->prev = NULL;
    n->next = NULL;
    } else {//otherwise  if there is  a tail node
    n->next = head;
    n->prev = NULL;
    head->prev = n;
    head = n;//points to the new node


}
    //traverse through
}


//deletes the first node in the list
void doubleLink::deleteFirstNode() {
if(head == NULL) {
    std::cout << "List is empty because the head is NULL" << std::endl;
}
    else if (head->next == NULL) {
    //new
    delete head->charInD;
    delete head;
    head = NULL;
        tail = NULL;

    }
    else { //checks if the head exists
        node *dummy = head;
        delete head->charInD;
        head->next->prev = NULL; //head's next's previous is NULL
        head = head->next;

        delete dummy;
    }
}


//deletes the last node in the list
void doubleLink::deleteLastNode() {

    if(tail == NULL){
        std::cout<<"List is empty because tail empty"<<std::endl;
    } else if (tail->prev != NULL){//if tail is not NULL meaning that there exists a tail..
        node *dummy = tail; //dummy is a pointer to tail
        tail->prev->next = NULL; //next is now NULL
        tail = tail->prev; //tail now points to the previous node
        tail->next = NULL;

        delete dummy;
    } else if (head == tail){
        delete head;
        head = NULL;
        tail = NULL;
    }


}

//https://www.youtube.com/watch?v=5s0x8bc9DvQ reference to traverse
void doubleLink::traverse(){
    std::cout<<"The loser list is:"<<std::endl;
    node *dummy = tail;
    if(dummy == NULL){
        std::cout<<"The list is empty"<<std::endl;
    }

    while(dummy != NULL){
        std::cout<<dummy->charInD->getCustomName()<<" ";
        dummy = dummy->prev; //loops and points to previous node
    }
    std::cout<<std::endl;
}


//destructor
doubleLink::~doubleLink() {
    deleteAll();
}

//deletes all nodes and frees the memory
void doubleLink::deleteAll(){
    while(head != NULL){
        deleteFirstNode();
    }
}
