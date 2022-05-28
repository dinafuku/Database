#include "Simulation.h"

Simulation::Simulation(){
    masterFaculty = new BST<Faculty*>();
    masterStudent = new BST<Student*>();
}

Simulation::~Simulation(){
    cout << "\x1b[0m";
    delete masterFaculty;
    delete masterStudent;
}

void Simulation::buildBST(DoublyLinkedList<string> *list, string person){
    if(person.compare("faculty") == 0){
        while(!list->isEmpty()){
            string line;
            string ID;
            string name;
            string level;
            string field;
            DoublyLinkedList<int> *ids = new DoublyLinkedList<int>();
            DoublyLinkedList<string> *info = new DoublyLinkedList<string>();
            line = list->removeFront();
            string temp = "";
            // stores string before comma in a linked list until the end
            for(int i = 0; i < line.size(); ++i){
                if(line.at(i) == ','){
                    info->insertBack(temp);
                    temp = "";
                }
                else if(i+1 == line.size()){
                    temp += line.at(i);
                    info->insertBack(temp);
                    temp = "";
                }
                else{
                    temp += line.at(i);
                }
            }
            // set variables for faculty members pulling from the list
            ID = info->removeFront();
            name = info->removeFront();
            level = info->removeFront();
            field = info->removeFront();
            // create faculty members with those variables
            Faculty *newFaculty = new Faculty(stoi(ID), name, level, field);
            // insert all advisee IDs
            while(!info->isEmpty()){
                ids->insertBack(stoi(info->removeFront()));
            }
            newFaculty->setAdviseeIDs(ids);
            masterFaculty->insert(newFaculty);
        }
    }
    else{
        while(!list->isEmpty()){
            string line;
            string ID;
            string name;
            string level;
            string field;
            string gpa;
            string advisorID;
            DoublyLinkedList<string> *info = new DoublyLinkedList<string>();
            line = list->removeFront();
            string temp = "";
            // stores string before comma in a linked list until the end
            for(int i = 0; i < line.size(); ++i){
                if(line.at(i) == ','){
                    info->insertBack(temp);
                    temp = "";
                }
                else if(i+1 == line.size()){
                    temp += line.at(i);
                    info->insertBack(temp);
                    temp = "";
                }
                else{
                    temp += line.at(i);
                }
            }
            // set variables pulling from the list
            ID = info->removeFront();
            name = info->removeFront();
            level = info->removeFront();
            field = info->removeFront();
            gpa = info->removeFront();
            advisorID = info->removeFront();
            // create student
            Student *newStudent = new Student(stoi(ID), name, level, field, stod(gpa), stoi(advisorID));
            // insert into student BST
            masterStudent->insert(newStudent);
        }
    }
}

void Simulation::simulate(){
    string input;
    cout << endl;
    DBTR *dbtr = new DBTR();
    long sleep = 50000;
    
    while(true){

        // output list of operations for database
        cout << "\x1b[32m                             | DATABASE OPERATIONS | \x1b[0m                           " << endl;
        usleep(sleep);
        cout << " --------------------------------------------------------------------------------" << endl;
        cout << "|\x1b[32m   1.\x1b[0m Print all students and their information (sorted by ascending id #)       |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   2.\x1b[0m Print all faculty and their information (sorted by ascending id #)        |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   3.\x1b[0m Find and display student information given the students id                |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   4.\x1b[0m Find and display faculty information given the faculty id                 |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   5.\x1b[0m Given a student's id, print the name and info of their faculty advisor    |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   6.\x1b[0m Given a faculty id, print ALL the names and info of his/her advisees      |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   7.\x1b[0m Add a new student                                                         |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   8.\x1b[0m Delete a student given the id                                             |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   9.\x1b[0m Add a new faculty member                                                  |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   10.\x1b[0m Delete a faculty member given the id                                     |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   11.\x1b[0m Change a student's advisor given the student id and the new faculty id   |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   12.\x1b[0m Remove an advisee from a faculty member given the ids                    |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   13.\x1b[0m Rollback                                                                 |" << endl;
        cout << "|--------------------------------------------------------------------------------|" << endl;
        usleep(sleep);
        cout << "|\x1b[32m   14.\x1b[0m Exit                                                                     |" << endl;
        cout << " --------------------------------------------------------------------------------" << endl;
        usleep(sleep);
        cout << endl;
        cout << "\x1b[32m Operation:\x1b[0m ";

        getline(cin, input);

        cout << endl;
        // print all student info 
        if(input.compare("1") == 0){
            usleep(sleep);
            cout << "\x1b[32m| PRINTING STUDENTS |\x1b[0m" << endl << endl;
            usleep(sleep);
            masterStudent->printNodes();
            if(masterStudent->isEmpty()){
                usleep(sleep);
                cout << "NO STUDENTS IN DATABASE" << endl << endl;
            }
        }
        // printo all faculty info
        else if(input.compare("2") == 0){
            usleep(sleep);
            cout << "\x1b[32m| PRINTING FACULTY |\x1b[0m" << endl << endl;
            usleep(sleep);
            masterFaculty->printNodes();
            if(masterFaculty->isEmpty()){
                usleep(sleep);
                cout << "NO FACULTY IN DATABASE" << endl << endl;
            }
        }
        // print student info given student ID
        else if(input.compare("3") == 0){
            usleep(sleep);
            cout << "\x1b[32m| DISPLAYING STUDENT INFO GIVEN STUDENT ID |\x1b[0m" << endl << endl;
            usleep(sleep);
            cout << "Student ID?" << endl;
            string ID;
            getline(cin, ID);
            if(ID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(ID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            Student *currStudent = new Student();
            currStudent->setID(stoi(ID));
            if(masterStudent->contains(currStudent)){
                cout << endl << masterStudent->getNode(currStudent) << endl;
                usleep(sleep);
                cout << "*\x1b[32mSTUDENT INFO DISPLAYED\x1b[0m*" << endl << endl;
            }
            else{
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Student with given ID does not exist\x1b[0m*" << endl << endl;
            }
            delete currStudent;
        }
        // print faculty info given faculty ID
        else if(input.compare("4") == 0){
            usleep(sleep);
            cout << "\x1b[32m| DISPLAYING FACULTY INFO GIVEN FACULTY ID |\x1b[0m" << endl << endl;
            usleep(sleep);
            cout << "Faculty ID?" << endl;
            string ID;
            getline(cin, ID);
            if(ID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(ID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            Faculty *currFaculty = new Faculty();
            currFaculty->setID(stoi(ID));
            if(masterFaculty->contains(currFaculty)){
                cout << endl << masterFaculty->getNode(currFaculty) << endl;
                usleep(sleep);
                cout << "*\x1b[32mFACULTY INFO DISPLAYED\x1b[0m*" << endl << endl;
            }
            else{
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Faculty with given ID does not exist\x1b[0m*" << endl << endl;
            }
            delete currFaculty;
        }
        // print student's advisor info
        else if(input.compare("5") == 0){
            usleep(sleep);
            cout << "\x1b[32m| DISPLAYING STUDENTS ADVISOR INFO |\x1b[0m" << endl << endl;
            usleep(sleep);
            cout << "Student ID?" << endl;
            string ID;
            getline(cin, ID);
            if(ID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(ID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            Student *currStudent = new Student();
            currStudent->setID(stoi(ID));
            // check if student exists, display info by getting student's advisor and printing
            if(masterStudent->contains(currStudent)){
                Student *myStudent = masterStudent->getNode(currStudent);
                Faculty *myFaculty = new Faculty();
                myFaculty->setID(myStudent->getAdvisorID());
                usleep(sleep);
                cout << endl << masterFaculty->getNode(myFaculty) << endl;
                usleep(sleep);
                cout << "*\x1b[32mADVISOR INFO DISPLAYED\x1b[0m*" << endl << endl;
                delete myFaculty;
            }
            else{
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Student with given ID does not exist\x1b[0m*" << endl << endl;
            }
            delete currStudent;
        }
        // print info of all advisees of advisor
        else if(input.compare("6") == 0){
            usleep(sleep);
            cout << "\x1b[32m| DISPLAYING ADVISORS STUDENT INFO |\x1b[0m" << endl << endl;
            usleep(sleep);
            cout << "Faculty ID?" << endl;
            string ID;
            getline(cin, ID);
            if(ID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(ID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            Faculty *currFaculty = new Faculty();
            currFaculty->setID(stoi(ID));
            // check if faculty members exists, get advisees, print all of their info
            if(masterFaculty->contains(currFaculty)){
                Faculty *myFaculty = masterFaculty->getNode(currFaculty);
                DoublyLinkedList<int> *idList = myFaculty->getAdviseeIDs();
                Node<int> *front = idList->getHead();
                cout << endl;
                while(front != NULL){
                    Student *myStudent = new Student();
                    myStudent->setID(front->data);
                    cout << masterStudent->getNode(myStudent) << endl;
                    front = front->next;
                    delete myStudent;
                }
                usleep(sleep);
                cout << "*\x1b[32mSTUDENT INFO DISPLAYED\x1b[0m*" << endl << endl;
            }
            else{
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Faculty with given ID does not exist\x1b[0m*" << endl << endl;
            }
            delete currFaculty;
        }
        // create student, get all inputs, error checking
        else if(input.compare("7") == 0){
            Student *newStudent;
            string ID;
            string name;
            string standing;
            string major;
            string GPA;
            string advisorID;

            usleep(sleep);
            cout << "\x1b[32m| CREATE STUDENT |\x1b[0m" << endl << endl;
            usleep(sleep);
            cout << "Student ID?" << endl;
            getline(cin, ID);
            if(ID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(ID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            usleep(sleep);
            cout << "Name?" << endl;
            getline(cin, name);
            if(name == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a name\x1b[0m*" << endl << endl;
                continue;
            }
            usleep(sleep);
            cout << "Level (Freshman, Sophomore, Junior, Senior)?" << endl;
            getline(cin, standing);
            if(standing == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a standing\x1b[0m*" << endl << endl;
                continue;
            }
            if(standing.compare("Freshman") != 0 && standing.compare("Sophomore") != 0 && standing.compare("Junior") != 0 && standing.compare("Senior") != 0){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Did not input Freshman, Sophomore, Junior, or Senior\x1b[0m*" << endl << endl;
                continue;
            }
            usleep(sleep);
            cout << "Major?" << endl;
            getline(cin, major);
            if(major == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid major\x1b[0m*" << endl << endl;
                continue;
            }
            usleep(sleep);
            cout << "GPA?" << endl;
            getline(cin, GPA);
            if(GPA == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a GPA\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(GPA)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid GPA (3.8, 4, etc.)\x1b[0m*" << endl << endl;
                continue;
            }
            usleep(sleep);
            cout << "Advisor ID?" << endl;
            getline(cin, advisorID);
            if(advisorID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            // if advisor ID does not exist, prompt as so and continue
            if(!isNumber(advisorID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid advisor ID\x1b[0m*" << endl << endl;
                continue;
            }
            Faculty *currFaculty = new Faculty();
            currFaculty->setID(stoi(advisorID));
            // check if advisor given ID exists
            if(!masterFaculty->contains(currFaculty)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Advisor with given ID does not exist\x1b[0m*" << endl << endl;
                continue;
            }
            // create student, insert into BST, update faculty advisees
            newStudent = new Student(stoi(ID), name, standing, major, stod(GPA), stoi(advisorID));
            masterStudent->insert(newStudent);
            currFaculty = masterFaculty->getNode(currFaculty);
            currFaculty->addID(stoi(ID));
            usleep(sleep);
            cout << endl << "*\x1b[32mSTUDENT ADDED\x1b[0m*" << endl << endl;
            dbtr->storeCommandStudent("delete student", newStudent);
        }
        // delete student given ID
        else if(input.compare("8") == 0){
            Student *currStudent = new Student();
            string studentID;
            usleep(sleep);
            cout << "\x1b[32m| DELETE STUDENT |\x1b[0m" << endl << endl;
            usleep(sleep);
            cout << "Student ID?" << endl;
            getline(cin, studentID);
            if(studentID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(studentID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid student ID\x1b[0m*" << endl << endl;
                continue;
            }
            currStudent->setID(stoi(studentID));
            // check if student given ID exists
            if(masterStudent->contains(currStudent)){
                Faculty *faculty = new Faculty();
                Student *student = masterStudent->getNode(currStudent);
                faculty->setID(student->getAdvisorID());
                faculty = masterFaculty->getNode(faculty);
                faculty->deleteID(student->getID());
                dbtr->storeCommandStudent("add student", masterStudent->getNode(currStudent));
            }
            usleep(sleep);
            // delete student from BST, database
            if(masterStudent->deleteNode(currStudent)){
                cout << endl << "*\x1b[32mSTUDENT DELETED\x1b[0m*" << endl << endl;
            }
            else{
                cout << endl << "*\x1b[31mISSUE: Student with given ID does not exist\x1b[0m*" << endl << endl;
            }   
        }
        // create faculty member, prompt for inputs, error checking
        else if(input.compare("9") == 0){
            Faculty *newFaculty = new Faculty();
            string ID;
            string name;
            string level;
            string department;
            string studentIDs;

            usleep(sleep);
            cout << "\x1b[32m| CREATE FACULTY |\x1b[0m" << endl << endl;
            usleep(sleep);
            cout << "Faculty ID?" << endl;
            getline(cin, ID);
            if(ID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(ID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            usleep(sleep);
            cout << "Name?" << endl;
            getline(cin, name);
            if(name == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid name\x1b[0m*" << endl << endl;
                continue;
            }
            usleep(sleep);
            cout << "Level (Lecturer, Assistant Prof, Associate Prof, Prof)?" << endl;
            getline(cin, level);
            if(level == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid level\x1b[0m*" << endl << endl;
                continue;
            }
            if(level.compare("Lecturer") != 0 && level.compare("Assistant Prof") != 0 && level.compare("Associate Prof") != 0 && level.compare("Prof") != 0){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Did not input Lecturer, Assistant Prof, Associate Prof, or Prof\x1b[0m*" << endl << endl;
                continue;
            }
            usleep(sleep);
            cout << "Department?" << endl;
            getline(cin, department);
            if(department == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a department\x1b[0m*" << endl << endl;
                continue;
            }
            usleep(sleep);
            cout << "How many student IDs?" << endl;
            string count;
            getline(cin, count);
            if(count == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a count\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(count)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID count\x1b[0m*" << endl << endl;
                continue;
            }
            newFaculty->setID(stoi(ID));
            newFaculty->setName(name);
            newFaculty->setLevel(level);
            newFaculty->setField(department);
            DoublyLinkedList<int> *ids = new DoublyLinkedList<int>();
            bool notValid = false;
            bool contains = true;

            usleep(sleep);
            cout << "Enter Student IDs one at a time per line" << endl;
            for(int i = 0; i < stoi(count); ++i){
                cout << "-- ";
                getline(cin, studentIDs);
                if(studentIDs == ""){
                    usleep(sleep);
                    cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                    continue;
                }
                if(!isNumber(studentIDs)){
                    usleep(sleep);
                    cout << endl << "*\x1b[31mISSUE: Input a valid student ID\x1b[0m*" << endl << endl;
                    notValid = true;
                    break;
                }
                Student *currStudent = new Student();
                currStudent->setID(stoi(studentIDs));
                // check if advisee given ID exists
                if(!masterStudent->contains(currStudent)){
                    usleep(sleep);
                    cout << endl << "*\x1b[31mISSUE: Advisee with given ID does not exist\x1b[0m*" << endl << endl;
                    contains = false;
                    break;
                }
                currStudent = masterStudent->getNode(currStudent);
                // check if advisee already has an advisor, if so don't create faculty member
                if(currStudent->getAdvisorID() != -1){
                    usleep(sleep);
                    cout << endl << "*\x1b[31mISSUE: Advisee with given ID already has an advisor\x1b[0m*" << endl << endl;
                    contains = false;
                    break;
                }
                ids->insertBack(stoi(studentIDs));
            }
            // error checking for inputs
            if(notValid || !contains){
                continue;
            }
            Node<int> *front = ids->getHead();
            // updates student advisor
            while(front != NULL){
                Student *student = new Student();
                student->setID(front->data);
                student = masterStudent->getNode(student);
                student->setAdvisorID(newFaculty->getID());
                front = front->next;
            }

            newFaculty->setAdviseeIDs(ids);
            // if advisor ID does not exist, prompt as so and continue
            masterFaculty->insert(newFaculty);
            usleep(sleep);
            cout << endl << "*\x1b[32mFACULTY ADDED\x1b[0m*" << endl << endl;
            dbtr->storeCommandFaculty("delete faculty", newFaculty);
        }
        // delete faculty member
        else if(input.compare("10") == 0){
            Faculty *currFaculty = new Faculty();
            string facultyID;
            usleep(sleep);
            cout << "\x1b[32m| DELETE FACULTY |\x1b[0m" << endl << endl;
            usleep(sleep);
            cout << "Faculty ID?" << endl;
            getline(cin, facultyID);
            if(facultyID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(facultyID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid faculty ID\x1b[0m*" << endl << endl;
                continue;
            }
            currFaculty->setID(stoi(facultyID));
            // check that faculty ID is valid
            if(masterFaculty->contains(currFaculty)){
                Faculty *faculty = new Faculty();
                faculty->setID(currFaculty->getID());
                faculty = masterFaculty->getNode(faculty);
                // if the faculty has advisees, tell user to change the student advisor first
                if(faculty->getAdviseeIDs()->getSize() > 0){
                    usleep(sleep);
                    cout << endl << "*\x1b[31mISSUE: Before deleting a faculty member, change the advisor of the advisees\x1b[0m*" << endl << endl;
                    continue;
                }
                DoublyLinkedList<int> *list = faculty->getAdviseeIDs();
                Node<int> *front = list->getHead();
                while(front != NULL){
                    Student *student = new Student();
                    student->setID(front->data);
                    student = masterStudent->getNode(student);
                    student->setAdvisorID(-1);
                    front = front->next;
                }
                dbtr->storeCommandFaculty("add faculty", masterFaculty->getNode(currFaculty));
                
            }
            usleep(sleep);
            if(masterFaculty->deleteNode(currFaculty)){
                // update students who have deleted advisor
                cout << endl << "*\x1b[32mFACULTY DELETED\x1b[0m*" << endl << endl;
            }
            else{
                cout << endl << "\x1b[31mISSUE: Faculty with given ID does not exist\x1b[0m*" << endl << endl;
            }   
        }
        // change student advisor given student and faculty IDS
        else if(input.compare("11") == 0){
            usleep(sleep);
            cout << "\x1b[32m| CHANGE STUDENT ADVISOR GIVEN STUDENT AND FACULTY IDS |\x1b[0m" << endl << endl;
            Faculty *currFaculty = new Faculty();
            Student *currStudent = new Student();
            string studentID;
            string facultyID;
            usleep(sleep);
            cout << "Student ID?" << endl;
            getline(cin, studentID);
            if(studentID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(studentID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid student ID\x1b[0m*" << endl << endl;
                continue;
            }
            usleep(sleep);
            cout << "Faculty ID?" << endl;
            getline(cin, facultyID);
            if(facultyID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(facultyID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid faculty ID\x1b[0m*" << endl << endl;
                continue;
            }
            currStudent->setID(stoi(studentID));
            currFaculty->setID(stoi(facultyID));
            // make sure student and advisor exist in the database
            if(masterStudent->contains(currStudent)){
                if(masterFaculty->contains(currFaculty)){
                    Student *myStudent = masterStudent->getNode(currStudent);
                    Faculty *myFaculty = masterFaculty->getNode(currFaculty);
                    dbtr->storeCommandAdvisor("revert advisor", myStudent->getAdvisorID(), myStudent);
                    // update advisors list of advisees
                    bool hasID = false;
                    Faculty *temp = new Faculty();
                    temp->setID(myStudent->getAdvisorID());
                    Faculty *prevFaculty = masterFaculty->getNode(temp);
                    DoublyLinkedList<int> *myList = prevFaculty->getAdviseeIDs();
                    Node<int> *front = myList->getHead();
                    while(front != NULL){
                        if(front->data == myStudent->getID()){
                            hasID = true;
                            prevFaculty->deleteID(myStudent->getID());
                        }
                        front = front->next;
                    }
                    if(!hasID){
                        usleep(sleep);
                        cout << endl << "*\x1b[31mISSUE: Advisor does not have given advisee ID\x1b[0m*" << endl << endl;
                        continue;
                    }
                    // update student info and faculty info
                    myStudent->setAdvisorID(currFaculty->getID());
                    myFaculty->addID(myStudent->getID());
                    usleep(sleep);
                    cout << endl << "*\x1b[32mADVISOR CHANGED\x1b[0m*" << endl << endl;
                }
                else{
                    usleep(sleep);
                    cout << endl << "*\x1b[31mISSUE: Faculty with given ID does not exist\x1b[0m*" << endl << endl;
                }
            }
            else{
                cout << endl << "*\x1b[31mISSUE: Student with given ID does not exist\x1b[0m*" << endl << endl;
            }
            delete currStudent;
            delete currFaculty;
        }
        // remove advisee from faculty member given IDS
        else if(input.compare("12") == 0){
            usleep(sleep);
            cout << "\x1b[32m| REMOVE ADVISEE FROM FACULTY GIVEN IDS |\x1b[0m" << endl << endl;
            usleep(sleep);
            cout << "Faculty ID?" << endl;
            Faculty *currFaculty = new Faculty();
            string facultyID;
            getline(cin, facultyID);
            if(facultyID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(facultyID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid faculty ID\x1b[0m*" << endl << endl;
                continue;
            }
            currFaculty->setID(stoi(facultyID));
            // make sure faculty member exists in database
            if(!masterFaculty->contains(currFaculty)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Faculty with given ID does not exist\x1b[0m*" << endl << endl;
                continue;
            }
            string studentIDs;
            bool notValid = false;
            bool hasID = false;
            usleep(sleep);
            cout << "Student ID?" << endl;
            getline(cin, studentIDs);
            if(studentIDs == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(studentIDs)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid student ID\x1b[0m*" << endl << endl;
                notValid = true;
                continue;
            }

            Student *currStudent = new Student();
            currStudent->setID(stoi(studentIDs));

            string newAdvisorID;
            usleep(sleep);
            cout << "Assign student new advisor (provide ID of faculty)?" << endl;
            getline(cin, newAdvisorID);
            if(newAdvisorID == ""){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid ID number (3984429, only numbers)\x1b[0m*" << endl << endl;
                continue;
            }
            if(!isNumber(newAdvisorID)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid student ID\x1b[0m*" << endl << endl;
                notValid = true;
                continue;
            }

            Faculty *newAdvisor = new Faculty();
            newAdvisor->setID(stoi(newAdvisorID));
            if(!masterFaculty->contains(newAdvisor)){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Input a valid faculty ID number\x1b[0m*" << endl << endl;
                continue;
            }

            newAdvisor = masterFaculty->getNode(newAdvisor);

            Faculty *temp = masterFaculty->getNode(currFaculty);
            DoublyLinkedList<int> *myList = temp->getAdviseeIDs();
            Node<int> *front = myList->getHead();
            // make sure advisor has the advisee (given ID)
            while(front != NULL){
                if(front->data == stoi(studentIDs)){
                    hasID = true;
                }
                front = front->next;
            }
            if(!hasID){
                usleep(sleep);
                cout << endl << "*\x1b[31mISSUE: Advisor does not have advisee (given ID)\x1b[0m*" << endl << endl;
                continue;
            }
            // update student info, delete ID from faculty member and delete advisor ID from student
            currStudent = masterStudent->getNode(currStudent);
            
            newAdvisor->addID(currStudent->getID());
            dbtr->storeNewAdvisor(newAdvisor);
            
            dbtr->storeCommandAdvisee("add advisee", currStudent->getID(), temp);
            temp->deleteID(currStudent->getID());
            currStudent->setAdvisorID(newAdvisor->getID());
            usleep(sleep);
            cout << endl << "*\x1b[32mADVISEE REMOVED\x1b[0m*" << endl << endl;
            delete currFaculty;
        }
        // rollback
        else if(input.compare("13") == 0){
            string command = dbtr->getCommand();
            if(command.compare("") == 0){
                usleep(sleep);
                cout << "*\x1b[31mISSUE: No past commands to rollback\x1b[0m*" << endl << endl;
                continue;
            }
            usleep(sleep);
            // if the past command was delete student, then you would "add student"
            if(command.compare("add student") == 0){
                Student *student = dbtr->getStudent();
                masterStudent->insert(student);
                Faculty *faculty = new Faculty();
                faculty->setID(student->getAdvisorID());
                faculty = masterFaculty->getNode(faculty);
                faculty->addID(student->getID());
                cout << "*\x1b[32mROLLBACK: STUDENT ADDED\x1b[0m*" << endl << endl;
            }
            // update student info and restore faculty info as well (advisee ID)
            else if(command.compare("delete student") == 0){
                Student *student = dbtr->getStudent();
                Faculty *faculty = new Faculty();
                faculty->setID(student->getAdvisorID());
                faculty = masterFaculty->getNode(faculty);
                faculty->deleteID(student->getID());
                masterStudent->deleteNode(student);
                cout << "*\x1b[32mROLLBACK: STUDENT DELETED\x1b[0m*" << endl << endl;
            }
            // add faculty member back
            else if(command.compare("add faculty") == 0){
                Faculty *faculty = dbtr->getFaculty();
                masterFaculty->insert(faculty);
                DoublyLinkedList<int> *list = faculty->getAdviseeIDs();
                Node<int> *front = list->getHead();
                while(front != NULL){
                    Student *student = new Student();
                    student->setID(front->data);
                    student = masterStudent->getNode(student);
                    student->setAdvisorID(faculty->getID());
                    front = front->next;
                }
                cout << "*\x1b[32mROLLBACK: FACULTY ADDED\x1b[0m*" << endl << endl;
            }
            // delete faculty member
            else if(command.compare("delete faculty") == 0){
                Faculty *faculty = dbtr->getFaculty();
                Student *student = new Student();
                student->setAdvisorID(faculty->getID());
                // update all students that previously had faculty member as an advisor
                while(masterStudent->contains(student)){
                    student = masterStudent->getNode(student);
                    student->setAdvisorID(-1);
                }
                masterFaculty->deleteNode(faculty);
                cout << "*\x1b[32mROLLBACK: FACULTY DELETED\x1b[0m*" << endl << endl;
            }
            // add advisee back to faculty member
            else if(command.compare("add advisee") == 0){
                // restore all info, then insert back into the database
                Faculty *faculty = dbtr->getFaculty();
                int adviseeID = dbtr->getAdviseeID();
                faculty->addID(adviseeID);
                Student *student = new Student();
                student->setID(adviseeID);
                student = masterStudent->getNode(student);
                student->setAdvisorID(faculty->getID());
                Faculty *newAdvisor = dbtr->getNewAdvisor();
                if(newAdvisor != NULL){
                    newAdvisor->deleteID(student->getID());
                }
                cout << "*\x1b[32mROLLBACK: ADVISEE ADDED BACK TO ADVISOR\x1b[0m*" << endl << endl;
            }
            // revert advisor/the change of advisor
            else if(command.compare("revert advisor") == 0){
                // revert advisor by getting previous advisor info and student info
                Student *student = dbtr->getStudent();
                int advisorID = dbtr->getAdvisorID();
                int previousID = student->getAdvisorID();
                student->setAdvisorID(advisorID);
                Faculty *temp = new Faculty();
                temp->setID(advisorID);
                temp = masterFaculty->getNode(temp);
                temp->addID(student->getID());

                Faculty *faculty = new Faculty();
                faculty->setID(previousID);
                faculty = masterFaculty->getNode(faculty);
                faculty->deleteID(student->getID());
                cout << "*\x1b[32mROLLBACK: ADVISOR REVERTED\x1b[0m*" << endl << endl;
            }
        }
        // saving database and exiting
        else if(input.compare("14") == 0){            
            // save database to facultyTable and studentTable files, then break
            try{
                ofstream outputFaculty;
                ofstream outputStudent;
                string line = "";
                string studentLine = "";

                // create new facultyTable and studentTable files
                outputFaculty.open("facultyTable");
                outputStudent.open("studentTable");
                // iterate through BST, get every faculty member, output their info to file
                while(!masterFaculty->isEmpty()){
                    line = "";
                    Faculty *addFaculty = *masterFaculty->getMin();
                    DoublyLinkedList<int> *list = addFaculty->getAdviseeIDs();
                    line += to_string(addFaculty->getID()) + ',';
                    line += addFaculty->getName() + ',';
                    line += addFaculty->getLevel() + ',';
                    line += addFaculty->getField();
                    while(!list->isEmpty()){
                        line += ',' + to_string(list->removeFront());
                    }
                    outputFaculty << line;
                    masterFaculty->deleteNode(addFaculty);
                    if(!masterFaculty->isEmpty()){
                        outputFaculty << endl;
                    }
                }
                // iterate through BST, get every student, output their info to file
                while(!masterStudent->isEmpty()){
                    studentLine = "";
                    Student *addStudent = *masterStudent->getMin();
                    studentLine += to_string(addStudent->getID()) + ',';
                    studentLine += addStudent->getName() + ',';
                    studentLine += addStudent->getLevel() + ',';
                    studentLine += addStudent->getField() + ',';
                    ostringstream ss;
                    ss << addStudent->getGPA();
                    studentLine += ss.str() + ',';
                    studentLine += to_string(addStudent->getAdvisorID());
                    outputStudent << studentLine;
                    masterStudent->deleteNode(addStudent);
                    if(!masterStudent->isEmpty()){
                        outputStudent << endl;
                    }
                }
                usleep(sleep);
                cout << "*\x1b[32mDATABASE SAVED TO STUDENT TABLE AND FACULTY TABLE\x1b[0m*" << endl;
                usleep(sleep);
                cout << "*\x1b[32mEXITING\x1b[0m*" << endl << endl;

                outputFaculty.close();
                outputStudent.close();
            }
            catch(runtime_error& e){
                cout << "Formatting in file is wrong or file doesn't exist" << endl;
            }                                                                                                                                                                                                                                                                                                                                                                                                                                            
            break;
        }
        else{
            usleep(sleep);
            cout << "*\x1b[31mISSUE: Not a valid command (1-14)\x1b[0m*" << endl << endl;
        }
    }
    delete dbtr;
}

// determine if string is a number of not bhy utilizing isdigit
bool Simulation::isNumber(string n){
    for(int i = 0; i < n.size(); ++i){
        if(n.at(i) == '.'){
            continue;
        }
        if(isdigit(n.at(i)) == 0){
            return false;
        }
    }
    return true;
}