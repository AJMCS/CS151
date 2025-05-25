/*Main.cpp - This program converts demical numbers to binary numbers
Author: AJ McDaniel
Module 4 
Project 01
Date: 4/3/2025
Problem Statement: This program will use a function to take in a int vairable and return the corresponding binary string 
to the main program.

Algorithm:
1. Ask the user to enter a decimal number and store in an  int  variable.  If the user enters a negative number, stop.
2. Call a function which takes the number as a parameter.
3. In the function, create an empty string which will hold the 0's and 1's representing the parameter in base 2.
4. Using a loop:
    a. divide the number to convert by two and determine the remainder (modulo).  It will be either 0 or 1.
    b. convert the modulo to a string and add to the front of the string which represents the number in base 2.
    c. continue dividing the number to convert by 2 until the result is 0.
5. When the loop is finished, return the string to "main".
6. In "main", display the resulting string as a binary representation of their number
7. Go back to step 1 and prompt for the next number to convert
*/

#include <iostream>
#include <string>

using namespace std;

//function to convert decimal to binary
//takes an int parameter and returns a string
string decimalToBinary(int decimalNumber) {
    //declare a string variable to hold the binary number
    string binaryString = "";

    //loop to convert decimal to binary
    while (decimalNumber > 0) {
        //add the remainder to the front of the binary string so we don't have to reverse it later
        binaryString = to_string(decimalNumber % 2) + binaryString;
        
        //divide the decimal number by 2
        decimalNumber /= 2;
    }

    //return the binary string when the loop is finished
    return binaryString;
}

int main() {
    //declare variables
    int decimalNumber;
    string binaryString;

    //prompt user to enter the decimal number
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    //check if the number is negative
    if (decimalNumber < 0) {
        //if the number is negative, print an error message nd end the program
        cout << "Please enter a positive number." << endl;
        
    }else {
        //otherwise, call the decimalToBinary function and display the result.
        binaryString = decimalToBinary(decimalNumber);
        cout << "The binary representation of " << decimalNumber << " is " << binaryString << endl;
    }
}