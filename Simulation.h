#ifndef SIMULATION_H
#define SIMULATION_H

#include "Student.h"
#include "Faculty.h"
#include "BST.h"
#include "DBTR.h"
#include <exception>
#include <fstream>
#include <sstream>
#include <unistd.h>

class Simulation{
    public:
        Simulation();
        ~Simulation();

        void buildBST(DoublyLinkedList<string> *list, string person);       // builds BST given list from tables and person type
        void simulate();                                                    // runs simulation
        bool isNumber(string n);                                            // error checking for numbers

    private:
        BST<Faculty*> *masterFaculty;                                       // BST that stores faculty members
        BST<Student*> *masterStudent;                                       // BST that stores students
};

#endif