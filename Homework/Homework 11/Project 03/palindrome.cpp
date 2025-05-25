/* main.cpp - Checks if a string is a palindrome using recursion
* Author: AJ McDaniel
* Module: 11
* Project 03: Palindrome Test
* Problem statement: This program checks whether a string is a palindrome using a recursive function.
* 
*
* Algorithm:
* 1. Define a helper function isAlphanumeric using isalnum.
 * 2. Define the recursive function isPalindrome:
 *    - Base case: return true if lower >= upper.
 *    - Skip non-alphanumeric characters from both ends using while.
 *    - Compare characters using tolower.
 *    - Recur on the substring with bounds moved inward.
 * 3. In main():
 *    - Prompt the user to enter strings.
 *    - If input is empty, exit.
 *    - Otherwise, call isPalindrome and print whether the input is a palindrome.
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//Prototypes
bool isAlphanumeric(char c);

int main() {
    string input;
    
    cout << "Enter strings to check for palindromes (press Enter to quit):" << endl;
    
    while (true) {
        cout << "\nEnter a string: ";
        getline(cin, input);
        
        // Exit if empty string is entered
        if (input.empty()) {
            break;
        }
        
        // Check if the string is a palindrome
        bool result = isPalindrome(input, 0, input.length() - 1);
        
        cout << "\"" << input << "\" is " 
             << (result ? "a palindrome" : "not a palindrome") 
             << endl;
    }
    
    return 0;
} 


// Function to check if a character is alphanumeric
bool isAlphanumeric(char c) {
    return isalnum(c);
}

// Recursive function to check if a string is a palindrome
bool isPalindrome(string str, int lower, int upper) {
    // Base case: empty string or single character
    if (lower >= upper) {
        return true;
    }

    // Skip non-alphanumeric characters from the left
    while (lower < upper && !isAlphanumeric(str[lower])) {
        lower++;
    }

    // Skip non-alphanumeric characters from the right
    while (lower < upper && !isAlphanumeric(str[upper])) {
        upper--;
    }

    // Compare characters (case-insensitive)
    if (tolower(str[lower]) != tolower(str[upper])) {
        return false;
    }

    // Recursive call for the remaining substring
    return isPalindrome(str, lower + 1, upper - 1);
}