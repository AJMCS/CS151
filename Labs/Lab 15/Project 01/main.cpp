/* main.cpp - Tester for Set operations
* Author: AJ McDaniel
* Lab: 15
* Project 01: Set Operations with Linked Lists
* Problem statement: Create and test a templated set class using linked lists
* 
*
* Algorithm:
* 1. Implement the Set class template with functions:
*    - minus() to return elements in A but not in B
*    - size() to return number of elements
*    - equals() to compare contents of two sets
*    - clear() to remove all elements from a set
* 2. Write runTests function to:
*    - Print A, B, A∩B, A–B, and (A–B)∪(A∩B)
*    - Use equals() to compare A with the result
*    - Use size() to count elements in A
* 3. In main, call test() with four different test cases:
*    - Two using string data
*    - Two using int data
*/

#include <iostream>
#include "SetLinkedList.h"
using namespace std;

//Prototype
template <typename T>
void test(initializer_list<T> a, initializer_list<T> b);

int main() {
    test<string>({"C", "G", "E", "A"}, {"E", "C", "F"});
    test<string>({"Carlos", "John", "Alice"}, {"John", "Henry", "Maria"});
    test<int>({15, 11, 13}, {11, 13, 15, 17, 19});
    test<int>({9}, {});
    return 0;
} 

template <typename T>
void test(initializer_list<T> a, initializer_list<T> b) {
    Set<T> A, B;
    for (const auto& x : a) A.insert(x);
    for (const auto& x : b) B.insert(x);

    cout << "A: "; A.display();
    cout << "B: "; B.display();
    cout << "A n B: "; A.setIntersect(B).display();
    cout << "A - B: "; A.minus(B).display();
    cout << "(A - B) U (A n B): "; A.minus(B).setUnion(A.setIntersect(B)).display();
    cout << "Equal? " << (A.equals(A.minus(B).setUnion(A.setIntersect(B))) ? "yes" : "no") << endl;
    cout << "A size: " << A.size() << endl << endl;
}