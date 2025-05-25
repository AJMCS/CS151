/* EString.h - Header file for EString class
* Author: AJ McDaniel
* File Description: Defines the Estring class and its functionality
*/


#ifndef ESTRING_H
#define ESTRING_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class EString {
private:
    char* string;
    int size;

public:
    // Constructor
    EString(const char* str = "") {
        size = strlen(str);
        string = new char[size + 1];
        strcpy(string, str);
    }

    // Copy constructor
    EString(const EString& original) {
        size = original.size;
        string = new char[size + 1];
        strcpy(string, original.string);
    }

    // Destructor
    ~EString() {
        delete[] string;
    }

    // Getter for size
    int getSize() const { return size; }

    // Assignment operator
    EString& operator=(const EString& original);

    // Stream insertion operator
    friend ostream & operator<<(ostream &, const EString &) ;
    // Prefix ++ operator
    EString operator++();

    // Postfix ++ operator
    EString operator++(int);

    // [] operator
    char& operator[](int);

    // + operator
    friend EString operator+(const EString&, const EString&);
};

// Assignment operator definition
EString & EString::operator=(const EString &original) {  
       delete [] string ;  
       size = original.size ;  
       string = new char[size + 1] ;  
       strcpy(string, original.string) ;  
       return *this ; 
   }

// Stream insertion operator definition
ostream & operator<<(ostream &out, const EString &output_EString) {  
      out << output_EString.string ; 
      return out ; 
}

// Prefix ++ operator definition
EString EString::operator++() {
    for (int i = 0; i < size; i++) {
        if (islower(string[i])) {
            string[i] = toupper(string[i]);
        }
    }
    return *this;
}

// Postfix ++ operator definition
EString EString::operator++(int) {
    EString temp(*this);
    for (int i = 0; i < size; i++) {
        if (islower(string[i])) {
            string[i] = toupper(string[i]);
        }
    }
    return temp;
}

// [] operator definition
char& EString::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "Error: Index out of bounds" << endl;
        exit(1);
    }
    return string[index];
}

// + operator definition
EString operator+(const EString& str1, const EString& str2) {
    int newSize = str1.size + str2.size;
    char* newString = new char[newSize + 1];
    strcpy(newString, str1.string);
    strcat(newString, str2.string);
    EString result(newString);
    delete[] newString;
    return result;
}

#endif // ESTRING_H 