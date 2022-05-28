# CPSC350_SP22_ASSIGNMENT6_INAFUKU

Dylan Inafuku

Student ID: 2375529

Email: dinafuku@chapman.edu

Class: CPSC 350-01

Assignment 6 - Building a Database with Binary Search Trees

Files:
GenStack.h, DoublyLinkedList.h, BST.h, Person.h, Person.cpp, Student.h, Student.cpp, Fcaculty.h, Faculty.cpp, Simulation.h, Simulation.cpp, FileProcessor.h, FileProcessor.cpp, DBTR.h, DBTR.cpp, main.cpp

Other files:
Makefile, 
.gitignore, 
README.md, 
facultyTable (stores faculty information), 
studentTable (stores student information) 

Resources:
Zybooks and In Class Assignments

Usage:

make

./assignment6.out 

Notes:
For adding new faculty members you can't assign a student to the advisor if that student already has one.
You must add a faculty member with no advisees at first. Then you can use the change advisor feature, delete an advisee from an advisor, or add a new student with the given advisor ID to assign the faculty member with said advisee.