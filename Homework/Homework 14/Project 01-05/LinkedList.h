/* LinkedList.h - Defines the LinkedList class
* Author: AJ McDaniel
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

// Structure for a node in the linked list
struct ListNode {
    double value;
    ListNode* next;
    
    // Constructor
    ListNode(double val, ListNode* nextNode = nullptr) {
        value = val;
        next = nextNode;
    }
};

class LinkedList {
private:
    ListNode* head;  // Pointer to the first node in the list

public:
    // Constructor
    LinkedList();
    
    // Destructor
    ~LinkedList();
    
    // Member functions
    void add(double new_number);
    bool isMember(double number);
    void print();
    void reverse();
    int search(double number);
    void insert(double new_number, int pos);
};

#endif 