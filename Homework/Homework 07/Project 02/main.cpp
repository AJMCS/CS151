/* main.cpp - Test the EncryptableString class.
* Author: AJ McDaniel
* Module: 07
* Project: 02
* Problem statement: Test the EncryptableString class.
* 
* Algorthim:
* 1. Create an EncryptableString object.
* 2. Test the encrypt function.
* 3. Test the decrypt function.
* 4. Test the encrypt function again.
* 5. Test the decrypt function again.
* 
*/

#include <iostream>
#include "EncryptableString.h"
using namespace std;

void testEncryption(const string& testString) {
    EncryptableString str1(testString);
    EncryptableString str2(testString);
    
    cout << "Original string: \"" << str1 << "\"" << endl;
    
    str1.encrypt();
    cout << "Encrypted once:  \"" << str1 << "\"" << endl;
    
    str1.encrypt();
    cout << "Encrypted twice: \"" << str1 << "\"" << endl;
    cout << endl;
}

int main() {
    // Test cases
    testEncryption("Holy Moly!");
    testEncryption("San Diego Zoo.");
    testEncryption("The cost is $25.89.");
    testEncryption("Go away – unless you have tacos.");
    testEncryption("No one can make you feel inferior without your consent.");
    
    return 0;
} 