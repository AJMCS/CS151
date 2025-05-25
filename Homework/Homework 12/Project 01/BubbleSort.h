/*
BubbleSort.h – Concrete subclass implementing bubble sort logic using AbstractSort.
Author: AJ McDaniel
*/

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "AbstractSort.h"

using namespace std;

class BubbleSort : public AbstractSort {
public:
    void sort(int arr[], int size) override {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (compare(arr, j, j + 1) > 0) {
                    // Swap elements
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

#endif