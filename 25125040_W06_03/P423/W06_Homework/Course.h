//Course.h
using namespace std;
#pragma once

#include "Student.h"

struct Course
{
    char id[10];
    char name[200];
    Student studentList[80]; //Maybe adjusted depending on the type of course
    bool status; //Is it open or not?
    int maxStudent, minStudent;
    int curStudent;
};

/// @brief Input the information of a course from text file
/// @param c
/// @return
void Input(std::ifstream &inp, Course &c);

/// @brief Output the information of a course from text file
/// @param c
/// @return
void Output(std::ofstream &out, Course c);

/// @brief Add the information of a student into a course
/// @param c
/// @param s
/// @return
void AddStudent(Course &c, Student s);

/// @brief Remove the information of a student from a course and update the course's status
/// @param c
/// @param ID
/// @return
void RemoveStudent(Course &c, char ID[]);

/// @brief Find the students who were born in the given date's month
/// @param c
/// @return
void FindBornMonth(Course c);

/// @brief Find the students who were born in the given date's day
/// @param c
/// @return
void FindBornDay(Course c);

/// @brief Find the students who are above 18
/// @param c
/// @return
void FindAbove18(Course c);

/// @brief Find the students who are in class K19
/// @param c
/// @return
void FindK19Class(std::ofstream &out, Course c);

/// @brief Find the students by the given ID
/// @param c
/// @param id
/// @return
void FindStudentbyID(std::ofstream &out, Course c, char id[]);

/// @brief Find the students by the given name
/// @param c
/// @param Name
/// @return
void FindStudentbyName(std::ofstream &out, Course c, char Name[]);

/// @brief Sort the students' list in the course by ID
/// @param c
/// @return
void SortStudentbyID(std::ofstream &out, Course &c);

/// @brief Sort the students' list in the course by first name
/// @param c
/// @return
void SortStudentbyFirstname(std::ofstream &out, Course &c);

/// @brief Sort the students' list in the course by GPA
/// @param c
/// @return
void SortStudentbyGPA(std::ofstream &out, Course &c);

/// @brief Sort the students' list in the course by DoB
/// @param c
/// @return
void SortStudentbyDoB(std::ofstream &out, Course &c);
