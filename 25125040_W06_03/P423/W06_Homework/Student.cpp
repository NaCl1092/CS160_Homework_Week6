//Student.cpp
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
using namespace std;

#include "Student.h"

int cmpDouble(double a, double b)
{
    double diff = a - b;
    if (-eps < diff && diff < eps) return 0;
    if (diff > eps) return 1;
    return -1;
}

void SInput(Student &s)
{
    cin >> s.id;
    cin.ignore();
    cin.getline(s.name, 100, '\n');
    cin >> s.gpa;
    cin.ignore();
    cin.get(s.address, 200, '\n');
    cin >> s.dob.day >> s.dob.month >> s.dob.year;
    cin.ignore();
}

void SOutput(Student s)
{
    cout << "The student's information:\n";
    cout << "Id: " << s.id << '\n';
    cout << "Full name: " << s.name << '\n';
    cout << "GPA: " << fixed << setprecision(2) << s.gpa << '\n';
    cout << "Address: " << s.address << '\n';
    cout << "DOB: " << s.dob.day << "/" << s.dob.month << "/" << s.dob.year << '\n';
}

void SInputfile(std::ifstream &inp, Student &s)
{
    inp.get(s.id, 10, '\n');
    inp.get(s.name, 100, '\n');
    inp >> s.gpa;
    inp.ignore();
    inp.get(s.address, 200, '\n');
    inp >> s.dob.day >> s.dob.month >> s.dob.year;
    inp.ignore();
}

void SOutputfile(std::ofstream &out, Student s)
{
    out << "Id: " << s.id << '\n';
    out << "Full name: " << s.name << '\n';
    out << "GPA: " << fixed << setprecision(2) << s.gpa << '\n';
    out << "Address: " << s.address << '\n';
    out << "DOB: " << s.dob.day << "/" << s.dob.month << "/" << s.dob.year << '\n';
}

void firstName(Student s, char ans[], int &num)
{
    for (int i = 0; s.name[i] != '\0'; ++i)
    {
        if (s.name[i] == ' ') return;
        ans[num++] = s.name[i];
    }
}

void lastName(Student s, char ans[], int &num)
{
    int pos = -1;
    for (int i = 0; s.name[i] != '\0'; ++i)
    {
        if (s.name[i] == ' ')
        {
            pos = i;
        }
    }
    if (pos == -1) return;
    for (int i = pos + 1; s.name[i] != '\0'; ++i) ans[num++] = s.name[i];
}

void FindClass(Student s, char C[])
{
    C[0] = 'K';
    C[1] = s.id[0];
    C[2] = s.id[1];
    C[3] = '\0';
}

int ComparebyID(Student s1, Student s2)
{
    int res = strcmp(s1.id, s2.id);
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}

int ComparebyFirstname(Student s1, Student s2)
{
    char s_1[100], s_2[100];
    int num_1 = 0, num_2 = 0;
    firstName(s1, s_1, num_1);
    firstName(s2, s_2, num_2);
    int res = strcmp(s_1, s_2);
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}

int ComparebyGPA(Student s1, Student s2)
{
    return cmpDouble(s1.gpa, s2.gpa);
}

int ComparebyDoB(Student s1, Student s2)
{
    int d_1 = toDays(s1.dob);
    int d_2 = toDays(s2.dob);
    if (d_1 > d_2) return 1;
    else if (d_1 < d_2) return -1;
    else return 0;
}

