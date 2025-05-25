/* main.cpp - test the Money class
structures
* Author: AJ McDaniel
* Module: 06
* Project: 02
* Problem statement: This program tests the Money class by adding two Money objects together and comparing the results.
*
*Algorithm:
* 1. Create four  Money  objects with values 4.90, 1.27, 5.24, and 0.99,  assigning to four  Money  variables.
* 2. Add the first and second  Money  objects using the overloaded  +  operator, put the sum in a new  Money  variable, and print the results.
* 3. Add the third and fourth  Money  objects, store in another  Money  variable, and print the results.
* 4. Compare the values of the two "sum" objects and print the larger of the two objects using the overloaded >= operator (should be the second sum).
* 5. Re-assign the first  Money  variable to a new  Money  object with a value of 5.00, then recalculate the first "sum" using the (updated) first and second  Money  objects.
* 6. Compare the values of the two "sum" objects again and print the larger of the two  (now should be the new first "sum").
*/

#include "Money.cpp"
#include <iostream>
using namespace std;

// Function prototype for testing move constructor
Money testMove(Money);

int main() {
    // Create Money objects
    Money m1("4.90");
    Money m2("1.27");
    Money m3("5.24");
    Money m4("0.99");

    // Add first and second Money objects
    Money sum1 = m1 + m2;
    cout << m1 << " + " << m2 << " = " << sum1 << endl;

    // Add third and fourth Money objects
    Money sum2 = m3 + m4;
    cout << m3 << " + " << m4 << " = " << sum2 << endl;

    // Compare the two sums
    if (sum1 >= sum2) {
        cout << "Larger amount: " << sum1 << endl;
    } else {
        cout << "Larger amount: " << sum2 << endl;
    }

    // Reassign first Money object and recalculate sum
    m1 = Money("5.00");
    sum1 = m1 + m2;
    cout << m1 << " + " << m2 << " = " << sum1 << endl;

    // Compare the sums again
    if (sum1 >= sum2) {
        cout << "Larger amount: " << sum1 << endl;
    } else {
        cout << "Larger amount: " << sum2 << endl;
    }

    // Test move constructor
    Money returned = testMove(Money("8.36"));
    cout << "Returned: " << returned << endl;

    return 0;
}

// Function to test move constructor
Money testMove(Money in) {
    return in;
} 