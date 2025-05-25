/* LinkedList.h - Generic class allowing representation of a linked list
* Author: Chris Merrill
* Module: 14
* Project: Lab
* Problem statement: This file contains the definition for a generic
* Node class and a generic LinkedList class. Enhance an generic LinkedList.h
* class with several functions to make the class more usable.
*
* Functions should throw a run-time exception if there would be confusion
between
* what is returned (successful) and something couldn't be returned.
*
* Algorithm:
* Classes already included are Node<T> and LinkedList<T>
* Functions already given are: full constructor, addFirst, addLast, add,
* getFirst, getLast(), get, indexOf, getSize, isEmpty, removeFirst,
* removeLast, and clear
*
* Functions to be written are:
* display, remove, removeAt, lastIndexOf, contains, and set
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <stdexcept> // catch run-time errors
using namespace std ;

/******************************
* *
* Template for Node class *
* *
******************************/

template<class T>

class Node {
public:
T data ; // value or object stored in the node
Node<T> *next ; // pointer to the next nod

// No-arg constructor
Node() {
this->data = T() ;
next = nullptr ;
}

// Constructor with one parameter
Node(T myData) {
this->data = myData ; // stores value in node's data field
next = nullptr ;
}
} ;

/*****************************************
* *
* Template for the LinkedList class *
* *
*****************************************/
template<class T>

class LinkedList {
private:
    Node<T> *head;
    int size;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    // Display function
    void display() const {
        if (isEmpty()) {
            cout << "(null)" << endl;
            return;
        }
        Node<T> *current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Remove function
    bool remove(T myData) {
        if (isEmpty()) return false;
        
        Node<T> *current = head;
        Node<T> *previous = nullptr;
        
        while (current != nullptr) {
            if (current->data == myData) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                size--;
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;
    }

    // Remove at index function
    T removeAt(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        
        Node<T> *current = head;
        Node<T> *previous = nullptr;
        T removedData;
        
        if (index == 0) {
            removedData = head->data;
            head = head->next;
            delete current;
        } else {
            for (int i = 0; i < index; i++) {
                previous = current;
                current = current->next;
            }
            removedData = current->data;
            previous->next = current->next;
            delete current;
        }
        size--;
        return removedData;
    }

    // Last index of function
    int lastIndexOf(T myData) const {
        if (isEmpty()) return -1;
        
        int lastIndex = -1;
        int currentIndex = 0;
        Node<T> *current = head;
        
        while (current != nullptr) {
            if (current->data == myData) {
                lastIndex = currentIndex;
            }
            current = current->next;
            currentIndex++;
        }
        return lastIndex;
    }

    // Contains function
    bool contains(T myData) const {
        Node<T> *current = head;
        while (current != nullptr) {
            if (current->data == myData) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Set function
    T set(int index, T myData) {
        if (index < 0 || index >= size) {
            return T();
        }
        
        Node<T> *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        
        T oldData = current->data;
        current->data = myData;
        return oldData;
    }

    // Helper functions
    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    // Add element to the end of the list
    void addLast(T myData) {
        Node<T> *newNode = new Node<T>(myData);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node<T> *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }
};

#endif
