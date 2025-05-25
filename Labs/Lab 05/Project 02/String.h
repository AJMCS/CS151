/*
* String.h - Defines the String class with dynamic memory and deep copy support.
* Author: AJ McDaniel
*/

#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>
using namespace std;

class String {
private:
    char *string;
    int size;

public:
    String(const char *s = "");       // constructor
    String(const String &);           // copy constructor
    ~String();                        // destructor
    void change(const char *);        // reassign string

    friend void print(const String &);   // friend function
};

// Constructor
String::String(const char *original) {
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

// Copy constructor which creates a new string
String::String(const String &original) {
    size = original.size;
    string = new char[size + 1];
    strcpy(string, original.string);
}

// Destructor
String::~String() {
    delete[] string;
    size = 0;
}

// Replace with another String object
void String::change(const char *original) {
    delete[] string;
    size = strlen(original);
    string = new char[size + 1];
    strcpy(string, original);
}

// Display a String on the console
void print(const String &ptr) {
    cout << ptr.string << endl;
}

#endif // STRING_H 