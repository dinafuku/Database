#include "Person.h"

Person::Person(){
    ID = -1;
    name = "";
    level = "";
    field = "";
}

Person::Person(int id, string n, string l, string f){
    ID = id;
    name = n;
    level = l;
    field = f;
}

Person::~Person(){}

void Person::setID(int id){
    ID = id;
}

void Person::setName(string n){
    name = n;
}

void Person::setLevel(string l){
    level = l;
}

void Person::setField(string f){
    field = f;
}

int Person::getID(){
    return ID;
}

string Person::getName(){
    return name;
}

string Person::getLevel(){
    return level;
}

string Person::getField(){
    return field;
}

bool Person::operator==(Person *p) const{
    return (ID == p->ID);
}

bool Person::operator!=(Person *p) const{
    return (ID != p->ID);
}

bool Person::operator<(Person *p) const{
    return (ID < p->ID);
}

bool Person::operator<=(Person *p) const{
    return (ID <= p->ID);
}

bool Person::operator>(Person *p) const{
    return (ID > p->ID);
}

bool Person::operator>=(Person *p) const{
    return (ID >= p->ID);
}