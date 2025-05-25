/* Name.cpp - This program demonstrates a custom LinkedList class
* Author: AJ McDaniel
* Module: 14
* Project 01 - 05: Linked List Operations
* Problem statement: This program demonstrates a custom LinkedList class
* 
*
* Algorithm:
* 1. Define a ListNode structure with a double value and a pointer to the next node.
* 2. Create a LinkedList class that maintains a pointer to the head of the list.
* 3. Implement the following functions:
*    - add: Inserts a new node at the front of the list.
*    - isMember: Returns true if a value exists in the list.
*    - print: Displays all values in the list or (empty) if none.
*    - reverse: Reverses the list in place by adjusting pointers.
*    - search: Returns the index of a value or -1 if not found.
*    - insert: Inserts a value at a specified index or at the end.
* 4. Test all operations in main with clear section labels and output results.
*/

#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
    // Create a LinkedList object
    LinkedList list;
    
    // Test 1: Basic List Operations
    cout << "~Testing Basic Operations~" << endl;
    cout << "Adding numbers 7.0, 8.0, and 9.0 to the list..." << endl;
    list.add(7.0);
    list.add(8.0);
    list.add(9.0);
    
    cout << "Testing isMember function:" << endl;
    cout << "Is 9.0 in the list? " << (list.isMember(9.0) ? "Yes" : "No") << endl;
    cout << "Is 7.0 in the list? " << (list.isMember(7.0) ? "Yes" : "No") << endl;
    cout << "Is 5.0 in the list? " << (list.isMember(5.0) ? "Yes" : "No") << endl;
    
    // Test 2: Print Function
    cout << "\n~Testing Print Function~" << endl;
    cout << "Current list contents: ";
    list.print();
    
    // Test 3: Reverse Function
    cout << "\n~Testing Reverse Function~" << endl;
    cout << "Reversing the list..." << endl;
    list.reverse();
    cout << "List after reversal: ";
    list.print();
    
    // Test 4: Search Function
    cout << "\n~Testing Search Function~" << endl;
    cout << "Searching for 7.0: Position " << list.search(7.0) << endl;
    cout << "Searching for 9.0: Position " << list.search(9.0) << endl;
    cout << "Searching for 5.0: Position " << list.search(5.0) << endl;
    
    // Test 5: Insert Function
    cout << "\n~Testing Insert Function~" << endl;
    cout << "Inserting 6.0 at position 1..." << endl;
    list.insert(6.0, 1);
    cout << "List after insertion: ";
    list.print();
    
    cout << "Inserting 10.0 at position 0 (head)..." << endl;
    list.insert(10.0, 0);
    cout << "List after insertion: ";
    list.print();
    
    cout << "Inserting 11.0 at position 10 (beyond list length)..." << endl;
    list.insert(11.0, 10);
    cout << "List after insertion: ";
    list.print();
    
    return 0;
} 