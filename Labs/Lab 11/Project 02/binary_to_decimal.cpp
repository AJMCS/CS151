/* binary_to_decimal.cpp - Converts decimal numbers to binary using recursive and iterative methods.
* Author: AJ McDaniel
* Lab: 11
* Project 02: Binary-to-decimal converter
* Problem Statement: This program defines two functions to convert a positive number into a binary string.
* One function uses recursion and the other uses iteration.
* 
*
* Algorithm:
* 1. Define decimalToBinaryRecursive function:
 *    - Base cases: return "0" or "1" if n is 0 or 1.
 *    - Recursive case: call the function on n/2 and append n % 2.
 * 2. Define decimalToBinaryIterative function:
 *    - Special case: return "0" if n == 0.
 *    - Use a loop: divide n by 2, prepend n % 2 to result.
 * 3. In main():
 *    - Test both functions on 6 required decimal values.
 *    - Print results in a table comparing both methods.
 */

#include <iostream>
#include <string>
using namespace std;

//Prototypes
int binary_to_decimal_recursive(string binary_str);
int binary_to_decimal_iterative(string binary_str);

int main() {
    // Test cases from Project 1
    string test_cases[] = {"0", "1", "101", "100000", "11110000", "1010101010"};
    int expected[] = {0, 1, 5, 32, 240, 682};
    
    cout << "Testing binary to decimal conversion:" << endl;
    cout << "----------------------------------------" << endl;
    
    //Print result table
    for (int i = 0; i < 6; i++) {
        string binary = test_cases[i];
        int expected_decimal = expected[i];
        
        int recursive_result = binary_to_decimal_recursive(binary);
        int iterative_result = binary_to_decimal_iterative(binary);
        
        cout << "Binary string: " << binary << endl;
        cout << "Decimal Value: " << expected_decimal << endl;
        cout << "Recursive result: " << recursive_result << endl;
        cout << "Iterative result: " << iterative_result << endl;
        cout << "----------------------------------------" << endl;
    }
    
    return 0;
} 

// Recursive function to convert binary string to decimal
int binary_to_decimal_recursive(string binary_str) {
    // Base case: empty string returns 0
    if (binary_str.empty()) {
        return 0;
    }
    
    // Get the last character and convert it to integer
    int last_digit = binary_str.back() - '0';
    
    // Remove the last character
    binary_str.pop_back();
    
    // Recursive case: multiply the result of the recursive call by 2 and add the last digit
    return binary_to_decimal_recursive(binary_str) * 2 + last_digit;
}

// Iterative function to convert binary string to decimal
int binary_to_decimal_iterative(string binary_str) {
    int sum = 0;
    for (char digit : binary_str) {
        // Convert character to integer and update sum
        sum = sum * 2 + (digit - '0');
    }
    return sum;
}