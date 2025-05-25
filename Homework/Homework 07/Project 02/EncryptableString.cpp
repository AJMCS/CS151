/* EncryptableString.cpp - Implement the EncryptableString class.
* Author: AJ McDaniel
* Module: 07
* Project: 02
* file description: Implement the EncryptableString class.
* Algorthim:
* 1. Loop through each character in the string using a for loop.
* 2. For each character:
*    a. If it is a lowercase letter ('a' to 'z'):
*       - If the character is 'z', wrap around to 'a'.
*       - Otherwise, increment the character by 1.
*    b. If it is an uppercase letter ('A' to 'Z'):
*       - If the character is 'Z', wrap around to 'A'.
*       - Otherwise, increment the character by 1.
*    c. If it is a digit ('0' to '9'):
*       - If the character is '9', wrap around to '0'.
*       - Otherwise, increment the character by 1.
*    d. If it is not a letter or digit (e.g., space, punctuation), leave it unchanged.
* 3. The string is updated in-place, so no return value is needed.
*/

#include "EncryptableString.h"

void EncryptableString::encrypt() {
    for (size_t i = 0; i < this->length(); i++) {
        char& c = (*this)[i];
        
        // Handle lowercase letters
        if (c >= 'a' && c <= 'z') {
            c = (c == 'z') ? 'a' : c + 1;
        }
        // Handle uppercase letters
        else if (c >= 'A' && c <= 'Z') {
            c = (c == 'Z') ? 'A' : c + 1;
        }
        // Handle numbers
        else if (c >= '0' && c <= '9') {
            c = (c == '9') ? '0' : c + 1;
        }
        // Other characters remain unchanged
    }
} 