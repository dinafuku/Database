#include "FileProcessor.h"

FileProcessor::FileProcessor(){}
FileProcessor::~FileProcessor(){}

void FileProcessor::processFile(string facultyInput, string studentInput){
    try{
        ifstream facultyFS;
        ifstream studentFS;
        string data;

        // if tables are not found, tell user
        facultyFS.open(facultyInput);
        if(!facultyFS.is_open()){
            cout << endl << "\x1b[31m*FACULTY TABLE NOT FOUND*\x1b[0m" << endl;
        }
        studentFS.open(studentInput);
        if(!studentFS.is_open()){
            cout << endl << "\x1b[31m*STUDENT TABLE NOT FOUND*\x1b[0m" << endl;
        }
        Simulation *simulation = new Simulation();
        string *facultyInfo;
        string *studentInfo;
        DoublyLinkedList<string> *facultyList = new DoublyLinkedList<string>();
        DoublyLinkedList<string> *studentList = new DoublyLinkedList<string>();
        long sleep = 50000;
        // if both files are in current directory, build BSTs for them 
        if(facultyFS.is_open() && studentFS.is_open()){
            // read from files, build BSTs from them
            // read faculty file line by line
            usleep(sleep);
            cout << endl << "\x1b[32m*FACULTY TABLE AND STUDENT TABLE FOUND*\x1b[0m" << endl;
            while(!facultyFS.eof()){
                getline(facultyFS, data);
                facultyList->insertBack(data);
            }
            while(!studentFS.eof()){
                getline(studentFS, data);
                studentList->insertBack(data);
            }

            simulation->buildBST(facultyList, "faculty");
            simulation->buildBST(studentList, "student");
            usleep(sleep);
            cout << "\x1b[32m*DATABASE GENERATED*\x1b[0m" << endl;
        }

        simulation->simulate();
        facultyFS.close();
        studentFS.close();

        delete facultyList;
        delete studentList;
        delete simulation;
    }
    catch(runtime_error& e){
        cout << "Formatting in file is wrong or file doesn't exist" << endl;
    }
}