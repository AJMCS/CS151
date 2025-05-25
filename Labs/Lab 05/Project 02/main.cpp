/* main.cpp - description
* Author: AJ McDaniel
* Lab: 5
* Project 02: Copy Constructors
* Problem statement: This program demonstrates how to implement a custom String class using dynamic memory in C++.
* 
*
* Algorithm:
* 1. Include the custom String class via the header file String.h.
 * 2. In the main function:
 *    - Create a String object str1 using the constructor.
 *    - Create a second String object str2 using an assignment statement, which invokes the copy constructor.
 *    - Print both strings using the external friend function print().
 * 3. Use the change() method on str2 to reassign its contents and print both str1 and str2.
 *    - Verify that str1 remains unchanged, showing that a deep copy was made.
 * 4. Use the change() method on str1 and print both again to demonstrate full independence between the two.
 * 5. Exit the program, allowing destructors to clean up dynamically allocated memory. 
*/
#include "String.h"
#include <iostream>
using namespace std;

int main() {
    // Manipulate Strings using a constructor and an assignment statement
    cout << "Create two strings, one using a constructor, "
         << "another an assignment statement:" << endl << endl;
    String str1("MiraCosta College");    // constructor
    String str2 = str1;                  // copy constructor

    // Print initial values
    cout << "Initial values:" << endl;
    cout << "String 1: ";
    print(str1);
    cout << "String 2: ";
    print(str2);

    // Use the change function and print
    cout << "\nAfter changing string 2 using change()" << endl;
    str2.change("San Diego State");
    cout << "String 1: ";
    print(str1);
    cout << "String 2: ";
    print(str2);

    // Use the change function on string 1 and print
    cout << "\nAfter changing string 1 using change()" << endl;
    str1.change("UCSD");
    cout << "String 1: ";
    print(str1);
    cout << "String 2: ";
    print(str2);

    return 0;
} 