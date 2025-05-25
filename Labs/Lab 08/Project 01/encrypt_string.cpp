/* main.cpp - Encrypts strings using a lambda-based character encoder
* Author: AJ McDaniel
* Lab: 8
* Project 01: Encrypt a string using lambda functions
* Problem statement: This program prompts the user to enter a string and apply an encryption algorithm to it.
* 
*
* Algorithm:
* 1. Use a loop to prompt the user for a string to encrypt.
 * 2. Copy the user input to quit_test, convert it to lowercase using for_each and a lambda.
 * 3. If the lowercase version is "quit", exit the loop.
 * 4. Display the original string.
 * 5. Encrypt the string in-place using for_each and a lambda that calls encrypt(char&).
 * 6. Display the encrypted version.
 * 7. Repeat encryption and display the double-encrypted version.
 * 8. Loop back for more input.
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function prototype
void encrypt(char &character);

int main() {
    string message;
    string quit_test;
    
    while (true) {
        cout << "Enter a string to encrypt (or 'quit' to exit): ";
        getline(cin, message);
        
        // Create a copy for quit testing
        quit_test = message;
        
        // Convert quit_test to lowercase using lambda
        for_each(quit_test.begin(), quit_test.end(),
            [](char &c) { c = tolower(c); });
            
        // Check if user wants to quit
        if (quit_test == "quit") {
            break;
        }
        
        // Print original string
        cout << "Original string: " << message << endl;
        
        // Encrypt the string using lambda
        for_each(message.begin(), message.end(),
            [](char &c) { encrypt(c); });
            
        // Print encrypted string
        cout << "Encrypted string: " << message << endl;
        
        // Double encrypt
        for_each(message.begin(), message.end(),
            [](char &c) { encrypt(c); });
            
        // Print double encrypted string
        cout << "Double encrypted string: " << message << endl;
        cout << endl;
    }
    
    return 0;
}

// Function to encrypt a single character
void encrypt(char &character) {
    if (isalnum(character)) {
        if (character == 'Z') {
            character = 'A';
        }
        else if (character == 'z') {
            character = 'a';
        }
        else if (character == '9') {
            character = '0';
        }
        else {
            character++;
        }
    }
} 