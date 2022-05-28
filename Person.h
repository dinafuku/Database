#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "DoublyLinkedList.h"
#include <unistd.h>
using namespace std;

class Person{
    public:
        Person();
        Person(int id, string n, string l, string f);   // general person class, with given data
        ~Person();

        void setID(int id);                             // mutators
        void setName(string n);
        void setLevel(string l);
        void setField(string f);

        int getID();                                    // accessors
        string getName();
        string getLevel();
        string getField();

        bool operator==(Person *p) const;               // overloaded operators for comparing person objects
        bool operator!=(Person *p) const;
        bool operator<(Person *p) const;
        bool operator<=(Person *p) const;
        bool operator>(Person *p) const;
        bool operator>=(Person *p) const;

    protected:
        int ID;                                         // ID for each person
        string name;                                    // name of person
        string level;                                   // given level
        string field;                                   // either major or department
};

#endif