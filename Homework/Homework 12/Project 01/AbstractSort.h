/*
AbstractSort.h – Abstract base class with compare tracking and pure virtual sort().
Author: AJ McDaniel
*/

#ifndef ABSTRACTSORT_H
#define ABSTRACTSORT_H

using namespace std;

class AbstractSort {
protected:
    int comparisonCount;

public:
    AbstractSort() : comparisonCount(0) {}
    virtual ~AbstractSort() {}

    // Compare function that tracks comparisons and returns appropriate values
    int compare(int arr[], int k, int m) {
        comparisonCount++;
        return arr[k] - arr[m];
    }

    // Pure virtual sort function
    virtual void sort(int arr[], int size) = 0;

    // Get the number of comparisons performed
    int getComparisonCount() const {
        return comparisonCount;
    }
};

#endif