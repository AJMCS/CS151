/* main.cpp - Calculates factorials of positive numbers.
* Author: AJ McDaniel
* Module: 11
* Project 01: Iterative Factorial
* Problem statement: This program calculates the factorial of positive numbers using a
* loop instead of recursion. It continues prompting the user for a new number until
* the user enters a negative value.
* 
*
* Algorithm:
* 1. Create a function called factorial that calculates the factorial using a loop.
 *    - Multiply values from 2 to n into a result variable initialized to 1.
 * 2. In main():
 *    - Prompt the user for a number.
 *    - If the number is negative, break the loop.
 *    - Call the factorial function and print the result.
 *    - Repeat until the user enters a negative number.
 */

#include <iostream>
using namespace std;

//Prototypes
unsigned long long factorial(int n);

int main() {
    int number;
    
    // Main program loop - continues until user enters a negative number
    while (true) {
        // Prompt user for input
        cout << "Enter a number to calculate its factorial (negative to exit): ";
        cin >> number;
        
        // Check if user wants to exit
        if (number < 0) {
            break; 
        }
        
        // Calculate factorial and display result
        unsigned long long result = factorial(number);
        cout << "Factorial of " << number << " is: " << result << endl;
    }
    
    return 0;
} 

// Function to calculate factorial iteratively
unsigned long long factorial(int n) {
    if (n < 0) {
        return 0; // Factorial is not defined for negative numbers
    }
    
    unsigned long long result = 1;
    
    // Loop from 2 to n, multiplying each number into the result
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}