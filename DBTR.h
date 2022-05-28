#ifndef DBTR_H
#define DBTR_H

#include "Faculty.h"
#include "Student.h"
#include "GenStack.h"

class DBTR{
    public:
        DBTR();
        ~DBTR();
        
        void storeCommandFaculty(string command, Faculty *faculty);             // stores command and faculty member for rollback
        void storeCommandStudent(string command, Student *student);             // stores command and student for rollback
        void storeCommandAdvisee(string command, int ID, Faculty *advisor);     // stores command, ID, and advisor for rollback
        void storeCommandAdvisor(string commabd, int ID, Student *advisee);     // stores command, ID, and advisee for rollback
        void storeNewAdvisor(Faculty *newAdvisor);                              // stores replaced advisor
        void manageSize();                                                      // maintains 5 rollbacks by maintaing stack size

        string getCommand();                                                    // accessor
        Faculty *getFaculty();                                                  // accessor
        Student *getStudent();                                                  // accessor
        Faculty *getNewAdvisor();                                               // accessor
        int getAdvisorID();                                                     // accessor
        int getAdviseeID();                                                     // accessor

    private:
        GenStack<string> *commandStack;                                         // all of these are stacks to store data for rollback
        GenStack<Student*> *studentStack;
        GenStack<Faculty*> *facultyStack;
        GenStack<int> *advisorIDStack;
        GenStack<int> *adviseeIDStack;
        GenStack<Faculty*> *newAdvisorStack;
};

#endif