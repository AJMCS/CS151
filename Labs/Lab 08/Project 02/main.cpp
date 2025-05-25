/* main.cpp - Converts integers to string, binary, and hex representations
* Author: AJ McDaniel
* Lab: 8
* Project 02: Exercise several string functions
* Problem statement: This program prompts the user to enter a number and converts them various ways
* 
*
* Algorithm:
* 1. Prompt the user for an integer and store it in original.
 * 2. Use to_string to convert the number to a string, append " rah!", and print it.
 * 3. Use stringstream to extract the integer value from the modified string and print it.
 * 4. Convert the number to binary using a char* buffer and print the binary string.
 * 5. Convert the binary string back to an integer using stoi and print it.
 * 6. Convert the original number to hexadecimal using stringstream and print it.
 * 7. Convert the hex back to decimal using the same stream and print the result.
 * 8. Release the dynamically allocated memory used for the binary string.
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    // Prompt user for input
    cout << "Please enter a number: ";
    int original = 0;
    cin >> original;

    // Convert number to string and append " rah!"
    string original_as_string = to_string(original) + " rah!";
    cout << "Number as string with 'rah!': " << original_as_string << endl;

    // Convert string back to number using stringstream
    stringstream inpstr(original_as_string);
    int original_copy;
    inpstr >> original_copy;
    cout << "Converted back to a number: " << original_copy << endl;

    // Convert number to binary string
    char* binary = new char[33];
    *(binary + 32) = '\0';  // Null terminate the string
    int index = 32;
    do {
        *(binary + (--index)) = (char)(original_copy % 2 + '0');
        original_copy /= 2;
    } while (original_copy > 0);
    cout << "That number in binary is: " << (binary + index) << endl;

    // Convert binary string back to decimal using stoi
    original_copy = stoi((binary + index), nullptr, 2);
    cout << "Converted back from binary: " << original_copy << endl;

    // Convert to hexadecimal
    stringstream iostr;
    iostr << hex << original;
    cout << "That number in hex is: 0x" << iostr.str() << endl;

    // Convert hex back to decimal
    iostr >> hex >> original_copy;
    cout << "Converted back from hex: " << original_copy << endl;

    // Clean up dynamically allocated memory
    delete[] binary;

    return 0;
} 