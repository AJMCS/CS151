/* word_counter.cpp - Count the number of words in a string
* Author: AJ McDaniel
* Module: 08
* Project 01: Word Counter
* Problem statement: Write a function that takes a C-string and returns the number of words it contains.
* Words are separated by spaces. Ignore leading, trailing, and multiple adjacent spaces.
* 
* Algorithm:
* 1. Define a function countWords that:
*    - Uses a loop to walk through the string character by character
*    - Increments the word count when entering a word
*    - Skips over spaces and only counts valid transitions
* 2. In main, define a fixed-size char array as input buffer
* 3. Prompt the user to enter strings for each of the following cases:
*    - A regular sentence with several words
*    - A sentence with leading blanks
*    - A sentence with multiple spaces between words
*    - An empty string
* 4. Call countWords on each and print the result
*/

#include <iostream>
#include <cctype>
using namespace std;

// Prototype
int countWords(const char* str);

int main() {
    const int MAX_LENGTH = 1000;
    char input[MAX_LENGTH];

    // Test case 1: Several words
    cout << "Test Case 1: Several words\n";
    cout << "Enter a string with several words: ";
    cin.getline(input, MAX_LENGTH);
    cout << "Number of words: " << countWords(input) << "\n\n";

    // Test case 2: Leading blanks
    cout << "Test Case 2: Leading blanks\n";
    cout << "Enter a string with leading blanks: ";
    cin.getline(input, MAX_LENGTH);
    cout << "Number of words: " << countWords(input) << "\n\n";

    // Test case 3: Adjacent blanks
    cout << "Test Case 3: Adjacent blanks\n";
    cout << "Enter a string with adjacent blanks: ";
    cin.getline(input, MAX_LENGTH);
    cout << "Number of words: " << countWords(input) << "\n\n";

    // Test case 4: Empty string
    cout << "Test Case 4: Empty string\n";
    cout << "Number of words: " << countWords("") << "\n\n";

    return 0;
} 

int countWords(const char* str) {
    int count = 0;
    bool inWord = false;

    // If string is empty
    if (str == nullptr || *str == '\0') {
        return 0;
    }

    // Iterate through the string
    while (*str != '\0') {
        // If current character is not a space and we're not in a word
        if (!isspace(*str) && !inWord) {
            inWord = true;
            count++;
        }
        // If current character is a space, mark that we're not in a word
        else if (isspace(*str)) {
            inWord = false;
        }
        str++;
    }

    return count;
}