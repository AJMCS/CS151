/* main.cpp – Demonstrates AbstractSeq with even and factorial sequences.
* Author: AJ McDaniel
* Module: 12
* Project 02: Sequence Sum
* Problem statement: This program uses an abstract base class to represent two different sequences of numbers
* and then prints terms and calculates the sum of terms in each sequence.
*
* Algorithm:
* 1. Create instances of EvenSequence and FactorialSequence.
2. Call printSeq(3, 12) on EvenSequence and display its sum from 7 to 10.
3. Call printSeq(1, 10) on FactorialSequence and display its sum from 4 to 6.
4. All output should label values of n and fun(n) and clearly state the summed ranges.
*/

#include <iostream>
#include "SequenceClasses.h"
using namespace std;

int main() {
    // Create instances of both sequence classes
    EvenSequence evenSeq;
    FactorialSequence factSeq;

    // Demonstrate EvenSequence
    cout << "Even numbers 3 to 12 are:\n";
    evenSeq.printSeq(3, 12);
    cout << "\nThe sum of 7 to 10 is " 
         << evenSeq.sumSeq(7, 10) << endl;

    // Demonstrate FactorialSequence
    cout << "\nFactorials 1 to 10 are:\n";
    factSeq.printSeq(1, 10);
    cout << "\nThe sum of 4 to 6 is " 
         << factSeq.sumSeq(4, 6) << endl;

    return 0;
} 