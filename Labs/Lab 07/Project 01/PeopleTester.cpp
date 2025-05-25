/* peopletester.cpp - Tests the functionality of PersonAtMCC and derived classes with sample data and output.
* Author: AJ McDaniel
* Lab: 7
* Project 01: Complete the People At MiraCosta classes
* Problem statement: This program uses inheritance to model different types of people at MiraCosta College
* 
*
* Algorithm:
* 1. Create two Student objects using full constructors and print their info.
* 2. Create one Instructor and one Staff object using full constructors and print their info.
* 3. Create a general personAtMCC object and print their info using the base class.
* 4. Demonstrate polymorphism by explicitly calling the base class showInfo for a derived object (s1).
* 5. Format all output into clear sections and label each person shown for readability.
*/

#include <iostream>
#include "Student.h"
#include "Instructor.h"
#include "Staff.h"
#include "personAtMCC.h"
using namespace std;

int main() {

    // Make objects to test
    Student s1(749385, "John Jacob", "123 Main Street, Oceanside, CA", "760.213.4930", "Computer Science", 240, true, true);
    Student s2(938746, "Jingleheimer Schmidt", "294A West 4th Ave., Escondido, CA", "760.294.4932", "Math", 134, false, false);
    Instructor i1(9943475, "Ellen Matthews", "843 C St., San Diego, CA", "619.427.4933", "English", true, 59.85, 160);
    Staff st1(483957463, "Mark Stramaglia", "15 East Ramona Way, Ramona, CA", "760.583.3911", "x5923", "Nov. 15, 2015", 49.25);
    personAtMCC p1(10000001, "Ralph Kramden", "999 Yellow Brick Road", "555-BANG-ZOOM");

    // Output demonstration
    cout << "*** TWO STUDENTS ***" << endl;
    s1.showInfo();
    cout << endl;
    s2.showInfo();
    cout << endl;

    cout << "*** A FRIENDLY INSTRUCTOR ***" << endl;
    i1.showInfo();
    cout << endl;

    cout << "*** STAFF MEMBER ***" << endl;
    st1.showInfo();
    cout << endl;

    cout << "*** JUST ANOTHER PERSON AT MCC ***" << endl;
    p1.showInfo();
    cout << endl;

    cout << "*** BASE CLASS SHOWINFO FOR MS. EARHART ***" << endl;
    s1.personAtMCC::showInfo();

    return 0;
}
