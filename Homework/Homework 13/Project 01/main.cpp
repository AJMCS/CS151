/* Name.cpp - description
* Author: AJ McDaniel
* Module: 13
* Project 01: String Bound Exceptions
* Problem statement: This program defines a class BCheckString, derived from the standard string class.
* It adds bounds checking to the subscript operator so that if an invalid index is used,
* a custom exception is thrown.
* 
*
* Algorithm: (replace)
* 1. Define class BCheckString derived from string.
* 2. Overload operator[] to throw BoundsException if index is invalid.
* 3. Define custom exception class BoundsException inheriting from std::exception.
* 4. In main(), create a BCheckString and print the test string.
* 5. Use try-catch blocks to:
*    - Access valid indices and print results.
*    - Attempt out-of-bounds accesses and catch exceptions.
*/ 

#include <iostream>
#include "BCheckString.h"
using namespace std;

int main() {
    // Create a test string
    BCheckString testString("Hello World!");
    cout << "Test string: " << testString << endl;
    
    try {
        // Test case 1: Access valid index (within bounds)
        cout << "\nTest Case 1: Accessing valid index" << endl;
        cout << "Character at index 4: " << testString[4] << endl;
        
        // Test case 2: Access another valid index
        cout << "\nTest Case 2: Accessing another valid index" << endl;
        cout << "Character at index 7: " << testString[7] << endl;
        
        // Test case 3: Access negative index
        cout << "\nTest Case 3: Accessing negative index" << endl;
        cout << "Character at index -1: " << testString[-1] << endl;
    }
    catch (const BoundsException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    
    try {
        // Test case 4: Access index beyond string length
        cout << "\nTest Case 4: Accessing index beyond string length" << endl;
        cout << "Character at index 20: " << testString[20] << endl;
    }
    catch (const BoundsException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    
    return 0;
} 