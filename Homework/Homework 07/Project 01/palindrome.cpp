/* palindrome.cpp - Check if a string is a palindrome
* Author: AJ McDaniel
* Module: 07
* Project: 01
* Problem statement: Check if a string is a palindrome.
* 
* Algorthim:
* 1. Define a class PString that publicly inherits from the C++ string class.
2. Add a constructor that takes either a std::string or C-string and passes it to the base class.
3. Implement a method isPalindrome() that:
   a. Uses two indices (left and right) to traverse the string from both ends.
   b. Skips characters that are not letters or digits.
   c. Compares characters in a case-insensitive manner.
   d. Returns false if any mismatch is found; otherwise, returns true.
4. In main, define an array of test strings.
5. For each test string:
   a. Create a PString object.
   b. Call isPalindrome() and print the result along with the original string.
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class PString : public string {
public:
    // Constructor that takes a string
    PString(const string& str) : string(str) {}
    
    // Constructor that takes a C-string
    PString(const char* str) : string(str) {}
    
    bool isPalindrome() {
        int left = 0;
        int right = length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from left
            while (left < right && !isalnum((*this)[left])) {
                left++;
            }
            
            // Skip non-alphanumeric characters from right
            while (left < right && !isalnum((*this)[right])) {
                right--;
            }
            
            // Compare characters (case-insensitive)
            if (tolower((*this)[left]) != tolower((*this)[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};

int main() {
    // Test cases
    const char* testCases[] = {
        "Chic",
        "Book",
        "Kayak",
        "1x2x3x4x5",
        "25  ABC 9cba52",
        "No lemons, no melon",
        "Not even close!",
        "A man, a plan, a canal -- Panama"
    };
    
    // Test each case
    for (const char* testStr : testCases) {
        PString pstr(testStr);
        cout << "Test string: \"" << testStr << "\"" << endl;
        cout << "Is palindrome? " << (pstr.isPalindrome() ? "yes" : "no") << endl;
        cout << endl;
    }
    
    return 0;
} 