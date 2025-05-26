/* SimpleVector.h - Simple Vector with added functionality
* Author: AJ McDaniel
* Module: 13
* Project: 03
*/
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
using namespace std ;
template <class T>
class SimpleVector {
protected:
T *aptr ;
int size = 0 ; // number of elements in vector
int capacity = 0 ; // size of underlying array
public:
SimpleVector(int = 0) ; // Constructor
SimpleVector(const SimpleVector &) ; // Copy constructor
~SimpleVector() ; // Destructor
int getCapacity()
{ return capacity ; }
int getSize()
{ return size ; }
void push_back(const T& value);
T pop_back();
} ;
//*************************************************************
// Constructor for EnhancedSimpleVector class *
// Sets the size of the array and allocates memory for it. *
//*************************************************************
template <class T>
SimpleVector<T>::SimpleVector(int new_capacity) {
size = 0 ;
capacity = new_capacity ;
aptr = new T [capacity] ;
// Empty the contents of the array
for (int count = 0 ; count < capacity ; count++) {
*(aptr + count) = T() ;
}
}
//**************************************************
// Copy Constructor for SimpleVector class *
//**************************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj) {
capacity = obj.capacity ;
aptr = new T [capacity] ;
for(int count = 0 ; count < capacity ; count++) {
*(aptr + count) = *(obj.aptr + count) ;
}
}
//***********************************************
// Destructor for SimpleVector class *
//***********************************************
template <class T>
SimpleVector<T>::~SimpleVector() {
if (capacity > 0) {
delete [] aptr ;
}
}
// Implementation of push_back
// Adds an element to the end if not full, else throws exception

template <class T>
void SimpleVector<T>::push_back(const T& value) {
    if (size >= capacity) {
        throw runtime_error("Vector is full");
    }
    aptr[size] = value;
    size++;
}

// Implementation of pop_back
// Removes and returns the last element if not empty, else throws exception

template <class T>
T SimpleVector<T>::pop_back() {
    if (size == 0) {
        throw runtime_error("Vector is empty");
    }
    size--;
    return aptr[size];
}
#endif