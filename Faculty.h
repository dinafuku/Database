#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

class Faculty : public Person{
    public:
        Faculty();
        ~Faculty();
        Faculty(int id, string n, string l, string f) : Person(id, n, l, f){}   // overloaded constructor, inheritance

        void setAdviseeIDs(DoublyLinkedList<int> *input);                       // mutator
        DoublyLinkedList<int>* getAdviseeIDs();                                 // accessor
        void addID(int input);                                                  // add advisee ID to advisor
        void deleteID(int input);                                               // delete advisee ID from advisor

        friend ostream& operator<<(ostream& os, Faculty *f);                    // overload << operator to print faculty member

    protected:
        DoublyLinkedList<int> *adviseeIDs;                                      // list of advisor's advisee IDs
};

#endif