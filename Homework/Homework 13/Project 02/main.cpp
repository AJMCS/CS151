/* Name.cpp - Demonstrates pushback and popback in the SimpleVector class
 * Author: AJ McDaniel
 * Module: 13
 * Project 02: SimpleVector Modification
 * Problem statement: Implement and test a templated class named SimpleVector that mimics limited STL vector behavior.
 * 
 *
 * Algorithm:
 * 1. Create a class template SimpleVector with dynamic memory allocation.
 * 2. Store both size and capacity as private members.
 * 3. Define pushback to insert an element if not full - otherwise, throw an exception.
 * 4. Define popback to remove the last element if not empty otherwise, throw an exception.
 * 5. In main.cpp, test the class using two separate int and string vectors.
 * 6. Use try-catch blocks for exception handling for both overflow and underflow.
 */

#include <iostream>
#include <string>
#include "SimpleVector.h"
using namespace std;

//Prototypes
void testIntVector();
void testStringVector();

int main() {
    testIntVector();
    testStringVector();
    return 0;
} 

// Tests the SimpleVector class with integers, demonstrating both overflow and underflow scenarios
void testIntVector() {
    cout << "\nTesting SimpleVector with integers:\n";
    cout << "--------------------------------\n";
    
    SimpleVector<int> intVec(5);
    cout << "Created vector with capacity 5\n";

    // Test overflow scenario: Attempt to add more elements than capacity
    try {
        // Tries to add 6 elements to a vector with capacity 5
        for (int i = 1; i <= 6; i++) {
            cout << "Pushing " << i << "... ";
            intVec.push_back(i);
            cout << "Current size: " << intVec.getSize() << endl;
        }
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    // Test underflow scenario by trying to remove elements from an empty vector
    cout << "\nPopping elements:\n";
    try {
        // Continues until vector is empty and throws an exception
        while (true) {
            int value = intVec.pop_back();
            cout << "Popped " << value << ". Current size: " << intVec.getSize() << endl;
        }
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

// Tests the SimpleVector class with strings, using the same overflow and underflow scenarios
void testStringVector() {
    cout << "\nTesting SimpleVector with strings:\n";
    cout << "--------------------------------\n";
    
    SimpleVector<string> strVec(5);
    cout << "Created vector with capacity 5\n";

    // Test overflow scenario with strings
    try {
        string words[] = {"Hello", "World", "C++", "Programming", "Test", "Extra"};
        // tries to add 6 strings to a vector with capacity 5
        for (int i = 0; i < 6; i++) {
            cout << "Pushing \"" << words[i] << "\"... ";
            strVec.push_back(words[i]);
            cout << "Current size: " << strVec.getSize() << endl;
        }
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    // Test underflow scenario with strings
    cout << "\nPopping elements:\n";
    try {
        // Loop continues until vector is empty and throws an exception
        while (true) {
            string value = strVec.pop_back();
            cout << "Popped \"" << value << "\". Current size: " << strVec.getSize() << endl;
        }
    } catch (const runtime_error& e) {
        cout << "Exception: " << e.what() << endl;
    }
}