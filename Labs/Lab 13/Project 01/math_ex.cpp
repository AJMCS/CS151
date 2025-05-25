/* math_ex.cpp – Using a custom exception class to throw exceptions for non-perfect squares.
* Author: AJ McDaniel
* Lab: 13
* Project 01: Arithmetic Exception
* Problem statement: This program defines a function that calculates the integer square root of a number
* only if the number is a perfect square.
* 
*
* Algorithm:
* 1. Create a custom exception class NotPerfectSquareException that stores the
*    invalid input number and returns an error message when thrown.
* 2. Implement the function squareRoot that:
*    a. Calculates the square root using sqrt(n).
*    b. Checks whether the square root is a whole number (perfect square).
*    c. If not, throws the custom exception.
* 3. In main():
*    a. Loop through numbers 0 to 25.
*    b. Call squareRoot(i) for each number.
*    c. If it succeeds, print the square root.
*    d. If it throws, catch NotPerfectSquareException and print a message 
*/

#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

// Custom exception class for non-perfect squares
class NotPerfectSquareException : public exception {
private:
    int number;
public:
    NotPerfectSquareException(int n) : number(n) {}
    const char* what() const noexcept override {
        return "Number is not a perfect square";
    }
    int getNumber() const { return number; }
};

// Function prototype
int squareRoot(int n);

int main() {
    // Test numbers from 0 to 25
    for (int i = 0; i <= 25; i++) {
        try {
            int root = squareRoot(i);
            cout << i << " is a perfect square with root: " << root << endl;
        }
        catch (const NotPerfectSquareException& e) {
            cout << i << " is not a perfect square" << endl;
        }
    }
    return 0;
}

// Calculate square root if it exists
int squareRoot(int n) {
    // Calculate the square root
    double sqrt_n = sqrt(n);
    
    // Check if it's a perfect square by comparing with its integer part
    if (sqrt_n != static_cast<int>(sqrt_n)) {
        throw NotPerfectSquareException(n);
    }
    
    return static_cast<int>(sqrt_n);
} 