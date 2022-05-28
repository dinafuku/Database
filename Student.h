#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person{
    public:
        Student();
        ~Student();
        Student(int id, string n, string l, string f, double gpa, int a) : Person(id, n, l, f){     // overloaded constructor, uses inheritance
            GPA = gpa;
            advisorID = a;
        }

        void setGPA(double gpa);                                                                    // mutators
        void setAdvisorID(int a);
        double getGPA();                                                                            // accessors
        int getAdvisorID();

        friend ostream& operator<<(ostream& os, Student *s);                                        // overloadeds << operator to print student information

    protected:
        double GPA;                                                                                 // student GPA
        int advisorID;                                                                              // student's advisor ID
};

#endif