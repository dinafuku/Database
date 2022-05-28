#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <exception>
using namespace std;

template <typename T>
class Node{
    public:
        Node();         // default constructor
        Node(T d);      // overloaded
        ~Node();        // destructor
        T data;         // data stored in node
        Node *next;     // point to next node
        Node *prev;     // point to prev node
};

template <typename T>
Node<T>::Node(){}

template <typename T>
Node<T>::Node(T d){
    data = d;
    next = NULL;
    prev = NULL;
}

template <typename T>
Node<T>::~Node(){
    delete next;
    delete prev;
}

template <typename T>
class DoublyLinkedList{
    public:
        DoublyLinkedList();                 // default constructor
        ~DoublyLinkedList();                // destructor
        void insertFront(T d);              // insert node at front of list
        void insertBack(T d);               // insert node at back of list
        void insertAfter(T w, T d);         // insert after node
        T removeFront();                    // remove front node
        T removeBack();                     // remove back node
        unsigned int removeNode(T nodeData);           // remove specific node
        Node<T>* find(T nodeData);          // find location of node
        bool isEmpty();                     // check if list is empty
        unsigned int getSize();             // get size of node
        void sort();                        // sorts list in ascending order
        void printList(string direction);   // prints list forward/backward based on direction
        Node<T>* const getHead();
        
    private:
        Node<T> *front;             // node to track front of list
        Node<T> *back;              // node for back of list
        unsigned int size;          // keeps track of size of list
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    // Node<T> *node = front;
    // Node<T> *deleteNode = front;
    // while(node != NULL){
    //     deleteNode = node->next;
    //     delete node;
    //     node = deleteNode;
    // }

    // use removeBack function to delete all nodes in list
    while(!isEmpty()){
        removeBack();
    }
}

template <typename T>
void DoublyLinkedList<T>::insertFront(T d){
    Node<T> *node = new Node<T>(d);
    // if empty update back
    if(isEmpty()){
        back = node;
    }
    // update front 
    else{
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}

template <typename T>
void DoublyLinkedList<T>::insertBack(T d){
    Node<T> *node = new Node<T>(d);
    // if empty update front
    if(isEmpty()){
        front = node;
    }
    // else update back
    else{
        node->prev = back;
        back->next = node;
    }
    back = node;
    ++size;
}

template <typename T>
void DoublyLinkedList<T>::insertAfter(T w, T d){
    Node<T> *foundNode = find(w);
    Node<T> *foundAfter;
    Node<T> *newNode = new Node<T>(d);
    // if found
    if(foundNode != NULL){
        // store node after found node, update pointer to new node, update next pointer of new node
        foundAfter = foundNode->next;
        foundNode->next = newNode;
        newNode->prev = foundNode;
        newNode->next = foundAfter;
        foundAfter->prev = newNode;
        ++size;
    }
}

template <typename T>
T DoublyLinkedList<T>::removeFront(){
    // check if list is empty
    if(isEmpty()){
        throw runtime_error("list is empty");
    }

    Node<T> *tempFront = front;
    // one node in list
    if(front->next == NULL){
        back = NULL;
    }
    // more than one node in list
    else{
        front->next->prev = NULL;
    }
    front = front->next;
    tempFront->next = NULL;
    // store front data
    T tempFrontData = tempFront->data;
    --size;
    delete tempFront;
    return tempFrontData;
}

template <typename T>
T DoublyLinkedList<T>::removeBack(){
    // check if list is empty
    if(isEmpty()){
        throw runtime_error("list is empty");
    }

    Node<T> *tempBack = back;
    // one node in list
    if(back->prev == NULL){
        front = NULL;
    }
    // more than one node
    else{
        back->prev->next = NULL;
    }
    // update back node
    back = back->prev;
    tempBack->prev = NULL;
    // store back data
    T tempBackData = tempBack->data;
    --size;
    delete tempBack;
    return tempBackData;
}

template <typename T>
unsigned int DoublyLinkedList<T>::removeNode(T nodeData){
    // check if list is empty
    if(isEmpty()){
        throw runtime_error("list is empty");
    }
    int index = 0;
    Node<T> *currentNode = front;
    // find node
    while(currentNode->data != nodeData){
        currentNode = currentNode->next;
        ++index;
        if(currentNode == NULL){
            return -1;
        }
    }
    // if the found node isn't the front or back, update accordingly
    if(currentNode != front && currentNode != back){
        currentNode->prev->next = currentNode->next;
        currentNode->next->prev = currentNode->prev;
    }
    T currentNodeData;
    // if the found node is front, update accordingly
    if(currentNode == front){
        if(front->next != NULL){
            front = currentNode->next;
            front->prev = NULL;
        }
        // found node is only node in list, so front and back are same
        else{
            currentNodeData = currentNode->data;
            front = NULL;
            back = NULL;
            --size;
            delete currentNode;
            return index;
        }
    }
    // if the found node is back, update accordingly
    else if(currentNode == back){
        back = currentNode->prev;
        back->next = NULL;
    }
    // update the prev and next pointers of node
    currentNode->next = NULL;
    currentNode->prev = NULL;
    currentNodeData = currentNode->data;
    --size;
    delete currentNode;
    return index;
}

template <typename T>
Node<T>* DoublyLinkedList<T>::find(T nodeData){
    // start at front node
    Node<T> *currNode = front;
    // while not at end of list
    while(currNode != NULL){
        // check if current node data is equivalent to given nodeData
        if(currNode->data == nodeData){
            return currNode;
        }
        // go to next node in list
        currNode = currNode->next;
    }
    // if given nodeData isn't found
    return currNode;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty(){
    return (size == 0);
}

template <typename T>
unsigned int DoublyLinkedList<T>::getSize(){
    return size;
}

template <typename T>
void DoublyLinkedList<T>::sort(){
    T myArray[size];
    int counter = 0;
    Node<T> *current = front;
    // fill array with data values of linked list
    while(counter < size){
        myArray[counter] = current->data;
        current = current->next;
        ++counter;
    }
    
    // sort
    T temp;
    for(int i = 0; i < size; ++i){
        for(int j = i+1; j < size; ++j){
            if(myArray[i] > myArray[j]){
                temp = myArray[i];
                myArray[i] = myArray[j];
                myArray[j] = temp;
            }
        }
    }
 
    // create sorted linked list
    current = front;
    counter = 0;
    while(current != NULL){
        current->data = myArray[counter];
        current = current->next;
        ++counter;
    }
}

template <typename T>
void DoublyLinkedList<T>::printList(string direction)
{
    // prints forward
    if(direction.compare("forward") == 0){
        Node<T> *curr = front;
        while(curr != 0){
            if(curr == front){
                cout << "{FRONT}: ";
            }
            cout << "[ " << curr->data << " ] ";
            if(curr == back){
                cout << ":{REAR}";
            }
            curr = curr->next;
            if(curr != 0){
                cout << " <==> ";
            }
        }
        cout << endl;
    }
    // print reversed list
    else if(direction.compare("backward") == 0){
        Node<T> *curr = back;
        while(curr != 0){
            if(curr == back){
                cout << "{REAR}: ";
            }
            cout << "[ " << curr->data << " ] ";
            if(curr == front){
                cout << ":{FRONT}";
            }
            curr = curr->prev;
            if(curr != 0){
                cout << " <==> ";
            }
        }
        cout << endl;
    }
}

template <typename T>
Node<T>* const DoublyLinkedList<T>::getHead(){
    return front;
}

#endif