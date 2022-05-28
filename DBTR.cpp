#include "DBTR.h"

DBTR::DBTR(){
    commandStack = new GenStack<string>();
    facultyStack = new GenStack<Faculty*>();
    studentStack = new GenStack<Student*>();
    advisorIDStack = new GenStack<int>();
    adviseeIDStack = new GenStack<int>();
    newAdvisorStack = new GenStack<Faculty*>();
}

DBTR::~DBTR(){
    delete commandStack;
    delete facultyStack;
    delete studentStack;
    delete advisorIDStack;
    delete adviseeIDStack;
    delete newAdvisorStack;
}

void DBTR::storeCommandFaculty(string command, Faculty *faculty){
    // manages size of stack, then pushes data onto stacks
    manageSize();
    commandStack->push(command);
    facultyStack->push(faculty);
}

void DBTR::storeCommandStudent(string command, Student *student){
    manageSize();
    commandStack->push(command);
    studentStack->push(student);
}

void DBTR::storeCommandAdvisee(string command, int ID, Faculty *advisor){
    manageSize();
    commandStack->push(command);
    adviseeIDStack->push(ID);
    facultyStack->push(advisor);
}

void DBTR::storeCommandAdvisor(string command, int ID, Student *student){
    manageSize();
    commandStack->push(command);
    advisorIDStack->push(ID);
    studentStack->push(student);
}

void DBTR::storeNewAdvisor(Faculty *newAdvisor){
    manageSize();
    newAdvisorStack->push(newAdvisor);
}

void DBTR::manageSize(){
    // manages size of stack to 5 by popping the bottom element out when the size is 5 
    if(commandStack->getSize() == 5){
        GenStack<string> *reverse = new GenStack<string>();
        while(!commandStack->isEmpty()){
            reverse->push(commandStack->pop());
        }
        reverse->pop();
        while(!reverse->isEmpty()){
            commandStack->push(reverse->pop());
        }
        delete reverse;
    }
    if(facultyStack->getSize() == 5){
        GenStack<Faculty*> *reverse = new GenStack<Faculty*>();
        while(!facultyStack->isEmpty()){
            reverse->push(facultyStack->pop());
        }
        reverse->pop();
        while(!reverse->isEmpty()){
            facultyStack->push(reverse->pop());
        }
        delete reverse;
    }
    if(studentStack->getSize() == 5){
        GenStack<Student*> *reverse = new GenStack<Student*>();
        while(!studentStack->isEmpty()){
            reverse->push(studentStack->pop());
        }
        reverse->pop();
        while(!reverse->isEmpty()){
            studentStack->push(reverse->pop());
        }
        delete reverse;
    }
    if(advisorIDStack->getSize() == 5){
        GenStack<int> *reverse = new GenStack<int>();
        while(!advisorIDStack->isEmpty()){
            reverse->push(advisorIDStack->pop());
        }
        reverse->pop();
        while(!reverse->isEmpty()){
            advisorIDStack->push(reverse->pop());
        }
        delete reverse;
    }
    if(adviseeIDStack->getSize() == 5){
        GenStack<int> *reverse = new GenStack<int>();
        while(!adviseeIDStack->isEmpty()){
            reverse->push(adviseeIDStack->pop());
        }
        reverse->pop();
        while(!reverse->isEmpty()){
            adviseeIDStack->push(reverse->pop());
        }
        delete reverse;
    }
    if(newAdvisorStack->getSize() == 5){
        GenStack<Faculty*> *reverse = new GenStack<Faculty*>();
        while(!newAdvisorStack->isEmpty()){
            reverse->push(newAdvisorStack->pop());
        }
        reverse->pop();
        while(!reverse->isEmpty()){
            newAdvisorStack->push(reverse->pop());
        }
        delete reverse;
    }
}

string DBTR::getCommand(){
    if(!commandStack->isEmpty()){
        return commandStack->pop();
    }
    return "";
}

Faculty* DBTR::getFaculty(){
    if(!facultyStack->isEmpty()){
        return facultyStack->pop();
    }
    return NULL;
}

Student* DBTR::getStudent(){
    if(!studentStack->isEmpty()){
        return studentStack->pop();
    }
    return NULL;
}

int DBTR::getAdvisorID(){
    if(!advisorIDStack->isEmpty()){
        return advisorIDStack->pop();
    }
    return -1;
}

int DBTR::getAdviseeID(){
    if(!adviseeIDStack->isEmpty()){
        return adviseeIDStack->pop();
    }
    return -1;
}

Faculty* DBTR::getNewAdvisor(){
    if(!newAdvisorStack->isEmpty()){
        return newAdvisorStack->pop();
    }
    return NULL;
}