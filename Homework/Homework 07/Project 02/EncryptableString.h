/* EncryptableString.h - Declare the EncryptableString class.
* Author: AJ McDaniel
* Module: 07
* Project: 02
* file description: Declares the EncryptableString class and defines the public and private members.
*/

#ifndef ENCRYPTABLESTRING_H
#define ENCRYPTABLESTRING_H

#include <string>
using namespace std;

class EncryptableString : public string {
public:
    // Constructor that takes a string
    EncryptableString(const string& str) : string(str) {}
    
    // Constructor that takes a C-string
    EncryptableString(const char* str) : string(str) {}
    
    // Encryption function
    void encrypt();
};

#endif