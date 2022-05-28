#include "Faculty.h"

Faculty::Faculty(){
    adviseeIDs = new DoublyLinkedList<int>;
}

Faculty::~Faculty(){
    delete adviseeIDs;
}

void Faculty::setAdviseeIDs(DoublyLinkedList<int> *input){
    adviseeIDs = input;
}

DoublyLinkedList<int>* Faculty::getAdviseeIDs(){
    return adviseeIDs;
}

void Faculty::addID(int input){
    adviseeIDs->insertBack(input);
}

void Faculty::deleteID(int input){
    adviseeIDs->removeNode(input);
}

ostream& operator<<(ostream& os, Faculty *f){
    // prints out faculty data/information
    long sleep = 50000;
    usleep(sleep);
    os << "Faculty ID: " << f->ID << endl;
    usleep(sleep);
    os << "Name: " << f->name << endl;
    usleep(sleep);
    os << "Job Title: " << f->level << endl;
    usleep(sleep);
    os << "Department: " << f->field << endl;
    usleep(sleep);
    os << "Student IDs: ";
    f->adviseeIDs->sort();
    Node<int> *front = f->adviseeIDs->getHead();
    if(front == NULL){
        os << "None";
    }
    while(front != NULL){
        os << front->data;
        if(front->next != NULL){
            os << ", ";
        }
        front = front->next;
    }
    os << endl;
    return os;
}