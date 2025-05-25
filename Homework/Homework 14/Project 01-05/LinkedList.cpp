/* LinkedList.cpp - Implements all member functions of the LinkedList class
* Author: AJ McDaniel
* 
* 
* Algorithm:
* 1. Constructor initializes head to nullptr.
* 2. Destructor traverses and deletes all nodes to prevent memory leaks.
* add function:
*    - Create a new node with value = new_number and next = head.
*    - Update head to point to the new node.
* isMember function:
*    - Traverse list from head and return true if any node's value matches.
*    - If end is reached without match, return false.
* print function:
*    - If head is nullptr, print "(empty)".
*    - Else, traverse list printing each node's value.
* reverse function:
*    - Use three pointers (prev, current, next) to reverse links between nodes.
*    - Update head to point to last node.
* search function:
*    - Traverse from head, tracking position index.
*    - Return index if match found, else return -1.
* insert function:
*    - If pos == 0 or list is empty, call add().
*    - Else, traverse to position - 1 or end of list.
*    - Insert new node after current.
*/

#include "LinkedList.h"
#include <iostream>

using namespace std;

// Constructor
LinkedList::LinkedList() {
    head = nullptr;
}

// Destructor
LinkedList::~LinkedList() {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

// Add a new node at the front of the list
void LinkedList::add(double new_number) {
    head = new ListNode(new_number, head);
}

// Check if a number is in the list
bool LinkedList::isMember(double number) {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->value == number) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Print the contents of the list
void LinkedList::print() {
    if (head == nullptr) {
        cout << "(empty)" << endl;
        return;
    }
    
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

// Reverse the list
void LinkedList::reverse() {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}

// Search for a number and return its position
int LinkedList::search(double number) {
    int position = 0;
    ListNode* current = head;
    
    while (current != nullptr) {
        if (current->value == number) {
            return position;
        }
        current = current->next;
        position++;
    }
    
    return -1;
}

// Insert a new number at a specified position
void LinkedList::insert(double new_number, int pos) {
    if (pos == 0 || head == nullptr) {
        add(new_number);
        return;
    }
    
    ListNode* current = head;
    int currentPos = 0;
    
    // Traverse to the position before where we want to insert
    while (current->next != nullptr && currentPos < pos - 1) {
        current = current->next;
        currentPos++;
    }
    
    // Insert the new node
    current->next = new ListNode(new_number, current->next);
} 