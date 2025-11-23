//25125040
//Le Hong Dang
//25A02
#include<iostream>
#include<fstream>

#include "Course.h"

/*Test case 1:
Input:
    1
    CS160
    Introduction to Computer Science
    80 10
    2
    3
    25125040
    Dang Le Hong
    8.0
    15 Truong Son
    13 11 2007
    2
    4
    25
    4
    25125040
    2
    0

Output:
    Course: CS160 - Introduction to Computer Science
    Status: Close
    Students list:

    Course: CS160 - Introduction to Computer Science
    Status: Close
    Students list:
        Id: 25125040
        Full name: Dang Le Hong
        GPA: 8.00
        Address: 15 Truong Son
        DOB: 13/11/2007
    Student not found.
    Course: CS160 - Introduction to Computer Science
    Status: Close
    Students list:
*/

/*
Test case 2:
Input:
    1
    CS160
    Introduction to Computer Science
    8 1
    2
    3
    25125040
    Dang Le Hong
    8.0
    15 Truong Son
    13 11 2007
    3
    25125041
    Dang Le
    10.0
    11 Nguyen Van Cu
    23 11 2007
    5
    6
    7
    8
    9
    25125040
    10
    Dang
    0

Output:
    Course: CS160 - Introduction to Computer Science
    Status: Close
    Students list:

    Dang Le Hong (25125040)
    Dang Le (25125041)

    Dang Le (25125041)

    Dang Le Hong (25125040)
    Dang Le (25125041)
    No students found for this condition.
    Dang Le Hong (25125040)

    Dang Le Hong (25125040)
    Dang Le (25125041)
*/

/*
Test case 3:
Input:
    1
    CS160
    Introduction to Computer Science
    8 1
    3
    25125040
    Dang Le Hong
    8.0
    15 Truong Son
    13 11 2007
    3
    25125041
    Dang Le
    10.0
    11 Nguyen Van Cu
    23 11 2007
    3
    25125007
    Hieu Nguyen Minh
    2.2
    123 Nguyen Bieu
    1 2 2007
    11
    12
    13
    14
    0

Output:
    Course: CS160 - Introduction to Computer Science
    Status: Open
    Students list:
        Id: 25125007
        Full name:     Hieu Nguyen Minh
        GPA: 2.20
        Address:     123 Nguyen Bieu
        DOB: 1/2/2007
    Id: 25125040
    Full name:     Dang Le Hong
    GPA: 8.00
    Address:     15 Truong Son
    DOB: 13/11/2007
        Id: 25125041
        Full name:     Dang Le
        GPA: 10.00
        Address:     11 Nguyen Van Cu
        DOB: 23/11/2007

    Course: CS160 - Introduction to Computer Science
    Status: Open
    Students list:
        Id: 25125041
        Full name:     Dang Le
        GPA: 10.00
        Address:     11 Nguyen Van Cu
        DOB: 23/11/2007
    Id: 25125040
    Full name:     Dang Le Hong
    GPA: 8.00
    Address:     15 Truong Son
    DOB: 13/11/2007
        Id: 25125007
        Full name:     Hieu Nguyen Minh
        GPA: 2.20
        Address:     123 Nguyen Bieu
        DOB: 1/2/2007

    Course: CS160 - Introduction to Computer Science
    Status: Open
    Students list:
        Id: 25125007
        Full name:     Hieu Nguyen Minh
        GPA: 2.20
        Address:     123 Nguyen Bieu
        DOB: 1/2/2007
    Id: 25125040
    Full name:     Dang Le Hong
    GPA: 8.00
    Address:     15 Truong Son
    DOB: 13/11/2007
        Id: 25125041
        Full name:     Dang Le
        GPA: 10.00
        Address:     11 Nguyen Van Cu
        DOB: 23/11/2007

    Course: CS160 - Introduction to Computer Science
    Status: Open
    Students list:
        Id: 25125041
        Full name:     Dang Le
        GPA: 10.00
        Address:     11 Nguyen Van Cu
        DOB: 23/11/2007
    Id: 25125040
    Full name:     Dang Le Hong
    GPA: 8.00
    Address:     15 Truong Son
    DOB: 13/11/2007
        Id: 25125007
        Full name:     Hieu Nguyen Minh
        GPA: 2.20
        Address:     123 Nguyen Bieu
        DOB: 1/2/2007
*/

using namespace std;

int main()
{
    Course c;
    c.curStudent = 0;
    c.status = false;
    c.maxStudent = 80;
    c.minStudent = 0;
    cout << "This is the program to operate with the courses.\n";
    cout << "The operations to operate with the courses are: \n";
    cout << "0. Exit;\n";
    cout << "1. Input a course from text file;\n";
    cout << "2. Output course info to text file;\n";
    cout << "3. Add a student to the course;\n";
    cout << "4. Remove a student from the course;\n";
    cout << "5. Find students born in the current month;\n";
    cout << "6. Find students born today;\n";
    cout << "7. Find students legal to have driving licenses;\n";
    cout << "8. Find K19 students;\n";
    cout << "9. Find student by ID;\n";
    cout << "10. Find students by Name;\n";
    cout << "11. Sort students by their ID;\n";
    cout << "12. Sort students by their first name;\n";
    cout << "13. Sort students by their GPA;\n";
    cout << "14. Sort students by their DoB.\n";
    int choice = 0;
    do
    {
        cout << "Please enter the index of the operation: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case 0: break;
            case 1:
            {
                ifstream inp("Input.txt");
                Input(inp, c);
                inp.close();
                break;
            }
            case 2:
            {
                ofstream out("Result.txt");
                Output(out, c);
                out.close();
                break;
            }
            case 3:
            {
                Student s;
                cout << "Please enter the student's information:\n";
                SInput(s);
                AddStudent(c, s);
                break;
            }
            case 4:
            {
                char ID[10];
                cout << "Please enter the student's id to remove: ";
                cin >> ID;
                cin.ignore();
                RemoveStudent(c, ID);
                break;
            }
            case 5:
            {
                FindBornMonth(c);
                break;
            }
            case 6:
            {
                FindBornDay(c);
                break;
            }
            case 7:
            {
                FindAbove18(c);
                break;
            }
            case 8:
            {
                ofstream out("Result.txt");
                FindK19Class(out, c);
                out.close();
                break;
            }
            case 9:
            {
                ofstream out("Result.txt");
                char ID[10];
                cout << "Please enter the student's id to find: ";
                cin.get(ID, 10, '\n');
                FindStudentbyID(out, c, ID);
                out.close();
                break;
            }
            case 10:
            {
                ofstream out("Result.txt");
                char Name[100];
                cout << "Please enter the student's name to find: ";
                cin.get(Name, 100, '\n');
                FindStudentbyName(out, c, Name);
                out.close();
                break;
            }
            case 11:
            {
                ofstream out("Result.txt");
                SortStudentbyID(out, c);
                out.close();
                break;
            }
            case 12:
            {
                ofstream out("Result.txt");
                SortStudentbyFirstname(out, c);
                out.close();
                break;
            }
            case 13:
            {
                ofstream out("Result.txt");
                SortStudentbyGPA(out, c);
                out.close();
                break;
            }
            case 14:
            {
                ofstream out("Result.txt");
                SortStudentbyDoB(out, c);
                out.close();
                break;
            }
        }
    } while (choice != 0);
    return 0;
}
