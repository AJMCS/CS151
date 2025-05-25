/*
BCheckString.h - Header file for BCheckString class
Author: AJ McDaniel
*/

#ifndef BCHECKSTRING_H
#define BCHECKSTRING_H

#include <string>
#include <stdexcept>
using namespace std;

// Custom exception class for out-of-bounds access
class BoundsException : public exception {
private:
    string message;
public:
    BoundsException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// BCheckString class derived from string
class BCheckString : public string {
public:
    // Constructor that passes string to base class
    BCheckString(const string& s) : string(s) {}
    
    // Overloaded operator[] with bounds checking
    char operator[](int k) const {
        if (k < 0 || k >= static_cast<int>(length())) {
            throw BoundsException("Index " + to_string(k) + " is out of bounds");
        }
        return string::operator[](k);
    }
};

#endif 