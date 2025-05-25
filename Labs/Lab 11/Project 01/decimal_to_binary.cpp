/* decimal_to_binary.cpp - Converts decimal numbers to binary using both recursive and iterative methods.
* Author: AJ McDaniel
* Lab: 11
* Project 01: Decimal-to-binary converter
* Problem statement: This program defines two functions to convert a positive number into a binary string.
* One function using recursion and the other uses normal iteration.
* 
*
* Algorithm: (replace)
* 1. Define decimalToBinaryRecursive() function:
 *    - Base cases: return "0" or "1" if n is 0 or 1.
 *    - Recursive case: call the function on n/2 and append n % 2.
 * 2. Define decimalToBinaryIterative(int n) function:
 *    - Special case: return "0" if n == 0.
 *    - Use a loop: divide n by 2, prepend n % 2 to result.
 * 3. In main():
 *    - Test both functions on 6 required decimal values.
 *    - Print results in a table comparing both methods.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Prototypes
string decimalToBinaryRecursive(int n);
string decimalToBinaryIterative(int n);


int main() {
    // Test cases
    int testNumbers[] = {0, 1, 5, 32, 240, 682};
    
    cout << "Decimal to Binary Conversions\n\n";
    cout << "Decimal |  Recursive  |  Iterative\n";
    cout << "--------|-------------|-------------\n";
    
    for (int num : testNumbers) {
        cout << setw(7) << num << " | "
             << setw(11) << decimalToBinaryRecursive(num) << " | "
             << setw(11) << decimalToBinaryIterative(num) << endl;
    }
    
    return 0;
} 

// Recursive function to convert decimal to binary
string decimalToBinaryRecursive(int n) {
    // Base case: if n is 0, return "0"
    if (n == 0) {
        return "0";
    }
    // Base case: if n is 1, return "1"
    if (n == 1) {
        return "1";
    }
    // Recursive case: get binary of n/2 and append the remainder
    return decimalToBinaryRecursive(n / 2) + to_string(n % 2);
}

// Iterative function to convert decimal to binary
string decimalToBinaryIterative(int n) {
    // Handle special case of 0
    if (n == 0) {
        return "0";
    }
    
    string result = "";
    while (n > 0) {
        // Prepend the remainder to the result string
        result = to_string(n % 2) + result;
        n = n / 2;
    }
    return result;
}