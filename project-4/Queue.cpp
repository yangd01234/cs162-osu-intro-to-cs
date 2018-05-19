/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Derek Yang
** Date:11/17/2017
** Description:This is the queue class, this class will use functions
 * to modify the circular linked list.  NOTE circular linked list means
 * that the last node points to head.  In this case, I used a while
 * loop to find the last node for any modifications or printing.
*********************************************************************/
#include "Queue.hpp"

Queue::Queue() {
    head = NULL;

}

QueueNode Queue::returnHead() {
    return* head;
}

//adds to the back of the queue
void Queue::addBack(Character* charInD) {
    QueueNode *n = new QueueNode;
    n->charIn = charInD;

    //do a case if the head is null
    if(head == NULL){

        head = n;
        n->next = head;
        n->prev = head;
    } else if (head->next == head && head->prev == head) { //if next head is also head, indicating one in the list
        head->next = n;
        head->prev = n;

        n->next = head;
        n->prev = head;
    } else { //else if there is a second and first node traverse until find end of list
        //while loop to go through and add to the end
        QueueNode *dummy = head;//creates a dummy node
        while(dummy->next != head) { //while dummy.next is not equal to head
            //std::cout<<dummy->val<<std::endl;
            dummy = dummy->next;//set dummy to dummy.next
        }
        //assigns the head prev to node
        head->prev = n;
        //assigns previous next to current
        dummy->next = n;
        //assign n next to head and n prev to dummy
        n->next = head;
        n->prev = dummy;
    }
}

//removes the front node and frees the memory
void Queue::removeFront() {
    if(!isEmpty()){//if head is not empty
        QueueNode *dummy = head;
        QueueNode *dummy2 = head;

        //check if head is not equal to itself if it is, set to null
        if(head->next == head){
            //delete head->charIn;
            head = NULL;
            delete dummy;
        } else {//if the head is not single
            //you have to re-assign the last node to the new head
            while(dummy->next != head) { //while dummy.next is not equal to head
                dummy = dummy->next;//set dummy to dummy.next
            }
            //set the new head
            head = dummy2->next;
            dummy->next = head;
            delete dummy2;
        }
    } else {
        std::cout<<"head is empty cannot remove first node"<<std::endl;
    }
}

void Queue::removeFrontFinal() {
    if(!isEmpty()){//if head is not empty
        QueueNode *dummy = head;
        QueueNode *dummy2 = head;

        //check if head is not equal to itself if it is, set to null
        if(head->next == head){
            delete head->charIn;
            head = NULL;
            delete dummy;
        } else {//if the head is not single
            //you have to re-assign the last node to the new head
            while(dummy->next != head) { //while dummy.next is not equal to head
                //std::cout<<dummy->val<<std::endl;
                dummy = dummy->next;//set dummy to dummy.next
            }
            delete head->charIn;
            head = dummy2->next; //sets the next head line line
            dummy->next = head; //sets the last one next to head
            delete dummy2; //delete head
        }
    } else {
        std::cout<<"head is empty cannot remove first node"<<std::endl;
    }
}

//checks if the queue if empty by checkin if head is empty
bool Queue::isEmpty() {
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

//returns the value of the node at the front
int Queue::getFront() {
    if(head == NULL){
        std::cout<<"head is empty";
        return 0;
    } else {
        return head->val;
    }

}

//prints the queue from head to end
void Queue::printQueue() {
if(isEmpty()){
    std::cout<<"List is empty, can not print"<<std::endl;
} else {
    QueueNode *dummy = head;
    while(dummy->next != head) { //while dummy.next is not equal to head
        std::cout<<dummy->charIn->getCustomName()<<"  ";
        dummy = dummy->next;//set dummy to dummy.next
    }
    std::cout<<dummy->charIn->getCustomName();
    std::cout<<std::endl;
}

}

void Queue::removeAllChar() {
    int count = 0;
    while(head != NULL){
        removeFrontFinal();
        count++;
    }
}

Queue::~Queue() {
    //removeAllChar();
    int count = 0;
    while(head != NULL){
        removeFrontFinal();
        count++;
    }
}