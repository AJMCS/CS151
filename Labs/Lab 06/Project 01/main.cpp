/* main.cpp - Customize the String class by overloading the assignment and stream insertion operators
* Author: AJ McDaniel
* Module: 06
* Project: 01
* Problem statement: Overload several operators using an EString class I created and test them.
* 
* Algorthim:
* 1. Create two EString objects.
* 2. Test the assignment operator and stream insertion operator.
* 3. Test the prefix and postfix increment operators.
* 4. Test the + operator.
* 5. Test the [] operator.
* 6. Test the character increment operator.
* 
*/

#include "EString.h"
#include <iostream>

using namespace std;

int main() {
    // Test assignment operator and stream insertion
    EString estring1 = "Hello MiraCosta!", estring2;
    estring2 = estring1;
    
    cout << "First string:  " << estring1 << endl
         << "Second string: " << estring2 << endl << endl;

    // Create test strings with mixed case, numbers, and punctuation
    EString test1 = "New Year's Party at 8:30.";
    EString test2 = "End of the Year Party at 5:00 PM!";

    // Test prefix ++ operator
    cout << "Original string:        " << test1 << endl;
    cout << "Using prefix operator:  " << ++test1 << endl;
    cout << "After using prefix:     " << test1 << endl << endl;

    // Test postfix ++ operator
    cout << "Original string:        " << test2 << endl;
    cout << "Using postfix operator: " << test2++ << endl;
    cout << "After using postfix:    " << test2 << endl << endl;

    // Test + operator
    EString combined = test1 + test2;
    cout << "Combined strings: " << combined << endl << endl;

    // Test [] operator - print characters separated by spaces
    cout << "Original: ";
    for (int i = 0; i < test1.getSize(); i++) {
        cout << test1[i] << " ";
    }
    cout << endl;

    // Test [] operator with character increment
    cout << "Updated:  ";
    for (int i = 0; i < test1.getSize(); i++) {
        test1[i]++;
        cout << test1[i] << " ";
    }
    cout << endl;

    return 0;
} 