/* seq_acc.cpp - Uses a template function to accumulate and return the total num of elements in a vector.
* Author: AJ McDaniel
* Lab: 13
* Project 02: Sequence Accumulation
* Problem statement: This program defines accum which is a template function that returns the total sum for numbers
* or concatenation for strings in a vector. Because it's using generics, it actually supports any data that supports
* the += operator.
* 
*
* Algorithm:
* 1. Create three vectors: one for int, one for double, and one for string.
    2. Print the contents of each vector to the console.
    3. Call the template function accum() to calculate the sum (or concatenation) of elements.
    4. Display the results of the accumulation for each vector.
    5. The template function:
        a. Initializes a result variable of type T using T().
        b. Iterates through the vector using a range-based for loop.
        c. Adds each item to the result using +=.
        d. Returns the result.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Template function prototype
template<typename T>
T accum(vector<T> v);

int main() {
    
    vector<int> intVec = {1, 2, 3, 4, 5};
    vector<double> doubleVec = {1.1, 2.2, 3.3, 4.4, 5.5};
    vector<string> stringVec = {"Hello", " ", "World", "!", "!"};

    // Integers
    cout << "Integer vector: ";
    for (int num : intVec) {
        cout << num << " ";
    }
    cout << "\nSum: " << accum(intVec) << endl << endl;

    // Doubles
    cout << "Double vector: ";
    for (double num : doubleVec) {
        cout << num << " ";
    }
    cout << "\nSum: " << accum(doubleVec) << endl << endl;

    // Strings
    cout << "String vector: ";
    for (const string& str : stringVec) {
        cout << str << " ";
    }
    cout << "\nConcatenation: " << accum(stringVec) << endl;

    return 0;
}

// Template function to accumulate values in a vector
template<typename T>
T accum(vector<T> v) {
    // Initialize result with default constructor
    T result = T();
    
    // Accumulate all values in the vector
    for (const T& item : v) {
        result += item;
    }
    
    return result;
} 