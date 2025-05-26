/* main.cpp - Sorting and bounds checking using the SortableVector template class.
* Author: AJ McDaniel
* Module: 13
* Project 03: SortableVector
* Problem statement: Create a derived class named SortableVector from SimpleVector that supports sorting 
* and adds bounds-checking to the overloaded [] operator.
* 
*
* Algorithm: (replace)
* 1. Derive SortableVector from SimpleVector.
 * 2. Implement a sort() function using bubble sort to sort aptr[] in ascending order.
 * 3. Override operator[] to throw an exception when index is invalid.
 * 4. In main:
 *    - Create a SortableVector<int> of size 20 and fill with random numbers.
 *    - Create a SortableVector<string> and fill with names.
 *    - Sort and print both before and after.
 *    - Test [] with invalid indices (-1 and size) and catch exceptions.
 */
#include "SortableVector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    cout << "Demonstrating SortableVector with integers:\n";
    cout << "----------------------------------------\n";
    
    // Create a vector of 20 random integers between 1 and 10
    SortableVector<int> intVector(20);
    for (int i = 0; i < 20; i++) {
        intVector.push_back(rand() % 10 + 1);
    }

    // Display the initial vector
    cout << "Initial vector of integers:\n";
    for (int i = 0; i < intVector.getSize(); i++) {
        cout << intVector[i] << " ";
    }
    cout << "\n\n";

    // Sort and display the sorted vector
    intVector.sort();
    cout << "Sorted vector of integers:\n";
    for (int i = 0; i < intVector.getSize(); i++) {
        cout << intVector[i] << " ";
    }
    cout << "\n\n";

    cout << "Demonstrating SortableVector with strings:\n";
    cout << "----------------------------------------\n";
    
    // Create a vector of names
    SortableVector<string> nameVector(10);
    string names[] = {"John", "Alice", "Bob", "Emma", "David", 
                     "Sarah", "Michael", "Lisa", "Tom", "Mary"};
    
    for (int i = 0; i < 10; i++) {
        nameVector.push_back(names[i]);
    }

    // Display the initial vector
    cout << "Initial vector of names:\n";
    for (int i = 0; i < nameVector.getSize(); i++) {
        cout << nameVector[i] << " ";
    }
    cout << "\n\n";

    // Sort and display the sorted vector
    nameVector.sort();
    cout << "Sorted vector of names:\n";
    for (int i = 0; i < nameVector.getSize(); i++) {
        cout << nameVector[i] << " ";
    }
    cout << "\n\n";

    cout << "Demonstrating exception handling with [] operator:\n";
    cout << "----------------------------------------\n";
    
    // Test with negative index
    try {
        cout << "Attempting to access element at index -1: ";
        intVector[-1];
    } catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << "\n";
    }

    // Test with index equal to size
    try {
        cout << "Attempting to access element at index " << intVector.getSize() << ": ";
        intVector[intVector.getSize()];
    } catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << "\n";
    }

    return 0;
} 