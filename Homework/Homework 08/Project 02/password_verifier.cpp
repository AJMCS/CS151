/* password_verifier.cpp - Create a program that verifies a password based on specific criteria.
* Author: AJ McDaniel
* Module: 08
* Project: 02
* Problem statement: Create a program that verifies a password based on if it has a least 
* one uppercase letter, one lowercase letter, one digit, and no blanks.
* 
* Algorithm:
* 1. Define a function verifyPassword that:
*    - Checks each rule using a loop or string method (pass > 6 chars, uppercase letter, digit, etc.)
*    - Pushes descriptive error messages to a vector if any rule fails
*    - Returns true if all rules are met, false otherwise
* 2. In main, create a list of test passwords.
* 3. Loop through each password:
*    - Call verifyPassword()
*    - Print whether the password is accepted or rejected
*    - If rejected, print all reasons from the error vector
*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Prototype
bool verifyPassword(const string& password, vector<string>& errors);

int main() {
    // Test password candidates
    vector<string> testPasswords = {"alfred", "OLIVIA", "12345", "Pass  9", "Mannix12"};
    vector<string> errors;

    // Test each password
    for (const string& password : testPasswords) {
        cout << "\nTesting password: '" << password << "'" << endl;
        bool isValid = verifyPassword(password, errors);

        // If the password is valid, print a message saying so.
        if (isValid) {
            cout << "Password accepted!" << endl;
        } else {

            // If the password is not valid, print the reasons why it is not valid.
            cout << "Password rejected. Reasons:" << endl;
            for (const string& error : errors) {
                cout << "- " << error << endl;
            }
        }
    }

    return 0;
} 


bool verifyPassword(const string& password, vector<string>& errors) {
    bool isValid = true;
    errors.clear();

    // Check if password is at least 6 characters long
    if (password.length() < 6) {
        errors.push_back("Password must be at least 6 characters long");
        isValid = false;
    }

    // Check for at least one uppercase letter
    bool hasUpper = false;
    for (char c : password) {
        if (isupper(c)) {
            hasUpper = true;
            break;
        }
    }
    if (!hasUpper) {
        errors.push_back("Password must contain at least one uppercase letter");
        isValid = false;
    }

    // Check for at least one lowercase letter basically doing the same thing.
    bool hasLower = false;
    for (char c : password) {
        if (islower(c)) {
            hasLower = true;
            break;
        }
    }
    if (!hasLower) {
        errors.push_back("Password must contain at least one lowercase letter");
        isValid = false;
    }

    // Check for at least one digit
    bool hasDigit = false;
    for (char c : password) {
        if (isdigit(c)) {
            hasDigit = true;
            break;
        }
    }
    if (!hasDigit) {
        errors.push_back("Password must contain at least one digit");
        isValid = false;
    }

    // Check for no blanks
    if (password.find(' ') != string::npos) {
        errors.push_back("Password cannot contain any blanks");
        isValid = false;
    }

    return isValid;
}