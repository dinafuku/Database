#ifndef GENSTACK_H
#define GENSTACK_H

#include "DoublyLinkedList.h"

template <typename T>
class GenStack{
    public:
        GenStack();                 // default constructor
        ~GenStack();                // destructor
        void push(T data);          // push data onto stack
        T pop();                    // pop data from stack
        T peek();                   // view top of stack
        unsigned int getSize();     // get number of elements in stack
        bool isEmpty();             // check if stack is empty
        
    private:
        DoublyLinkedList<T> *list;
        T top;                      // value of top of stack
        unsigned int size;          // keeps track of size of stack/number of elements
};

template <typename T>
GenStack<T>::GenStack(){
    list = new DoublyLinkedList<T>();
    size = 0;
}

template <typename T>
GenStack<T>::~GenStack(){
    delete list;
}

template <typename T>
void GenStack<T>::push(T data){
    // puts data at front of list (a.k.a top of stack)
    list->insertFront(data);
    top = data;
    ++size;
}

template <typename T>
T GenStack<T>::pop(){
    // if stack empty throw error
    if(isEmpty()){
        throw runtime_error("stack is empty");
    }
    // store popped data of stack
    T popped = list->removeFront();
    // update new top of stack if list isn't empty
    if(!list->isEmpty()){
        top = list->removeFront();
        list->insertFront(top);
    }
    --size;
    return popped;
}

template <typename T>
T GenStack<T>::peek(){
    // check if stack empty
    if(isEmpty()){
        throw runtime_error("stack is empty");
    }
    return top;
}

template <typename T>
unsigned int GenStack<T>::getSize(){
    return size;
}

template <typename T>
bool GenStack<T>::isEmpty(){
    return (size == 0);
}

#endif