//Student.h
using namespace std;
#pragma once

#include "Date.h"

const double eps = 1e-6;

/// @brief Student
/// @details The struct consists of the student's id, full name, gpa, address, date of birth
struct Student
{
    char id[10];
    double gpa;
    char name[100];
    char address[200];
    Date dob;
};

/// @brief Compare two double numbers
/// @param a
/// @param b
/// @return
int cmpDouble(double a, double b);

/// @brief Input the student's information from console
/// @param s
/// @return
void SInput(Student &s);

/// @brief Output the student's information to console
/// @param s
/// @return
void SOutput(Student s);

/// @brief Input the student's information text file
/// @param s
/// @return
void SInputfile(std::ifstream &inp, Student &s);

/// @brief Output the student's information to text file
/// @param s
/// @return
void SOutputfile(std::ofstream &out, Student s);

/// @brief Find the student's first name
/// @param s
/// @param ans
/// @param num
/// @return
void firstName(Student s, char ans[], int &num);

/// @brief Output the student's class
/// @param s
/// @return
void FindClass(Student s, char C[5]);

/// @brief Compare two students by id
/// @param a
/// @param b
/// @return
int ComparebyID(Student s1, Student s2);

/// @brief Compare two students by first name
/// @param a
/// @param b
/// @return
int ComparebyFirstname(Student s1, Student s2);

/// @brief Compare two students by GPA
/// @param a
/// @param b
/// @return
int ComparebyGPA(Student s1, Student s2);

/// @brief Compare two students by DoB and id
/// @param a
/// @param b
/// @return
int ComparebyDoB(Student s1, Student s2);
