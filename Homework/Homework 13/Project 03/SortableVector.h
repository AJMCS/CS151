/* SortableVector.h - A derived class from SimpleVector that supports sorting and bounds-checking.
* Author: AJ McDaniel
* Module: 13
* Project 03: SortableVector
*/
#ifndef SORTABLEVECTOR_H
#define SORTABLEVECTOR_H

#include "SimpleVector.h"
#include <algorithm>

using namespace std;

template <class T>
class SortableVector : public SimpleVector<T> {
public:
    // Constructor
    SortableVector(int size) : SimpleVector<T>(size) {}

    // Sort the vector in ascending order using bubble sort
    void sort() {
        for (int i = 0; i < this->getSize() - 1; i++) {
            for (int j = 0; j < this->getSize() - i - 1; j++) {
                if (this->aptr[j] > this->aptr[j + 1]) {
                    // Swap elements
                    T temp = this->aptr[j];
                    this->aptr[j] = this->aptr[j + 1];
                    this->aptr[j + 1] = temp;
                }
            }
        }
    }

    // Overload the [] operator
    T& operator[](int index) {
        if (index < 0 || index >= this->getSize()) {
            throw runtime_error("Index out of bounds");
        }
        return this->aptr[index];
    }
};

#endif 