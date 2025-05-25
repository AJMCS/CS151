/* main.cpp - Demonstrates usage of the Numbers class by accepting input and printing English translation
 * Author: AJ McDaniel
 * Module: 5
 * Project 01: Numbers to Words
 * Problem statement: Design a class that takes a non-negative integer between 0 and 9999 and prints its
 * English word representation, handling thousands, hundreds, tens, and units. Continue prompting the user
 * until they enter 0 to stop.
 *
 * Algorithm:
 * 1. Prompt the user for a number between 0 and 9999.
 * 2. If the number is 0, print a closing message and exit.
 * 3. If the number is out of range, print an error and prompt again.
 * 4. Otherwise, construct a Numbers object using the input.
 * 5. Call the object's print function:
 *    - If the number is 0, print "zero".
 *    - If the number is >= 1000, divide by 1000, print corresponding word + "thousand", and reduce the number.
 *    - If the number is >= 100, divide by 100, print corresponding word + "hundred", and reduce the number.
 *    - If the number is < 20, print the corresponding word directly.
 *    - If the number is 20 or more, print the corresponding tens word, and if needed, the ones digit.
 * 6. Loop back to step 1 for the next input.
 */

#include "Numbers.h"
#include <iostream>
using namespace std;

int main() {
    int num;
    
    cout << "Enter a number between 0 and 9,999." << endl;
    cout << "Enter 0 to exit" << endl;
    
    //loop to allow user to enter multiple numbers till they enter0/false
    while (true) {
        cout << "\nEnter a number: ";
        cin >> num;
        
        //if user enters 0, end program
        if (num == 0) {
            cout << "Ending Program..." << endl;
            break;
        }

        //if user enters a number outside the bounds print error message and continue the loop
        //so the can re-enter
        if (num < 0 || num > 9999) {
            cout << "Error: Number must be between 0 and 9999" << endl;
            continue;
        }
        
        //otherwise, create the number object and run the print function
        Numbers number(num);
        cout << "English: ";
        number.print();
        cout << endl;
    }
    
    return 0;
} 