/* Name.cpp - tester for linked list class
* Author: AJ McDaniel
* Lab: 14
* Project 01: Linked List Enhancements
* Problem statement: This program tests the linked list class implementation
* 
*
* Algorithm:
* 1. Create an empty LinkedList and test display on empty list.
* 2. Use addLast function to insert values including duplicates for later tests.
* 3. Test remove function by deleting a middle node, display result.
* 4. Test removeAt function for a valid and invalid index, using try/catch.
* 5. Test lastIndexOf function where value appears multiple times.
* 6. Test contains functino on values that are present and not present.
* 7. Test set(index, value) to replace data and return original, and test on invalid index.
*/

#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Creating an empty linked list..." << endl;
    LinkedList<double> list;
    
    // Test display with empty list
    cout << "\nTesting display() with empty list:" << endl;
    list.display();
    
    // Add some elements
    cout << "\nAdding elements to the list..." << endl;
    list.addLast(10.5);
    list.addLast(25.0);
    list.addLast(15.7);
    list.addLast(25.0);  // Adding duplicate for lastIndexOf test
    list.addLast(30.2);
    
    cout << "List after adding elements:" << endl;
    list.display();
    
    // Test remove function
    cout << "\nTesting remove(25.0):" << endl;
    bool removed = list.remove(25.0);
    cout << "Element 25.0 was " << (removed ? "removed" : "not found") << endl;
    cout << "List after removal:" << endl;
    list.display();
    
    // Test removeAt function
    cout << "\nTesting removeAt(1):" << endl;
    try {
        double removedElement = list.removeAt(1);
        cout << "Removed element at index 1: " << removedElement << endl;
        cout << "List after removal:" << endl;
        list.display();
        
        cout << "\nTesting removeAt with invalid index:" << endl;
        list.removeAt(10);  // This should throw an exception
    } catch (const out_of_range& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    
    // Test lastIndexOf function
    cout << "\nTesting lastIndexOf(25.0):" << endl;
    int lastIndex = list.lastIndexOf(25.0);
    cout << "Last index of 25.0: " << lastIndex << endl;
    
    // Test contains function
    cout << "\nTesting contains():" << endl;
    cout << "Contains 15.7: " << (list.contains(15.7) ? "true" : "false") << endl;
    cout << "Contains 99.9: " << (list.contains(99.9) ? "true" : "false") << endl;
    
    // Test set function
    cout << "\nTesting set(0, 50.0):" << endl;
    double oldValue = list.set(0, 50.0);
    cout << "Old value at index 0: " << oldValue << endl;
    cout << "List after setting new value:" << endl;
    list.display();
    
    cout << "\nTesting set with invalid index:" << endl;
    double invalidSet = list.set(10, 100.0);
    cout << "Result of invalid set: " << invalidSet << endl;
    
    return 0;
} 