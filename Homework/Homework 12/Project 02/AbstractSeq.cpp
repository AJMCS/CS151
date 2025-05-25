/*
 * AbstractSeq.cpp - Implements printSeq and sumSeq using virtual fun()
 * Author: AJ McDaniel
 */

#include "AbstractSeq.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Prints sequence terms in a formatted table from low to high
void AbstractSeq::printSeq(int low, int high) {
    cout << "\n      n      fun(n)\n";
    cout << "    -----  ----------\n";
    
    for (int i = low; i <= high; i++) {
        cout << setw(8) << i << setw(10) << fun(i) << endl;
    }
}

// Returns sum of sequence terms from low to high
int AbstractSeq::sumSeq(int low, int high) {
    int sum = 0;
    for (int i = low; i <= high; i++) {
        sum += fun(i);
    }
    return sum;
} 