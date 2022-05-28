#include "Student.h"

Student::Student(){
    GPA = 0.0;
    advisorID = -1;
}

Student::~Student(){}

void Student::setGPA(double gpa){
    GPA = gpa;
}

void Student::setAdvisorID(int a){
    advisorID = a;
}

double Student::getGPA(){
    return GPA;
}

int Student::getAdvisorID(){
    return advisorID;
}

ostream& operator<<(ostream& os, Student *s){
    long sleep = 50000;
    usleep(sleep);
    os << "Student ID: " << s->ID << endl;
    usleep(sleep);
    os << "Name: " << s->name << endl;
    usleep(sleep);
    os << "Standing: " << s->level << endl;
    usleep(sleep);
    os << "Major: " << s->field << endl;
    usleep(sleep);
    os << "GPA: " << s->GPA << endl;
    usleep(sleep);
    if(s->advisorID == -1){
        os << "Advisor ID: None" << endl;
    }
    else{
        os << "Advisor ID: " << s->advisorID << endl;
    }
    return os;
}