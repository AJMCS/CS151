/* Name.cpp - Demonstrates BubbleSort using an abstract base class.
* Author: AJ McDaniel
* Module: 12
* Project 01: Analysis of Sorting Algorithms
* Problem Statement: Runs tests on two arrays using the BubbleSort class to sort values
* and report the number of comparisons made during sorting.
* 
*
* Algorithm:
* 1. Create two arrays of different sizes.
2. Fill both arrays with randomly generated integers ranging from -100 to 99.
3. Print the contents of each array before sorting.
4. Sort each array using a BubbleSort object, which uses an inherited compare() method that tracks comparisons.
5. Print the contents of each array after sorting.
6. Display the total number of comparisons used during each sorting process.
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BubbleSort.h"

using namespace std;

//Prototypes
void printArray(int arr[], int size);
void fillArrayWithRandomNumbers(int arr[], int size);

int main() {
    const int SIZE1 = 20;
    const int SIZE2 = 15;
    
    int arr1[SIZE1];
    int arr2[SIZE2];
    
    // Fill arrays with random numbers
    fillArrayWithRandomNumbers(arr1, SIZE1);
    fillArrayWithRandomNumbers(arr2, SIZE2);
    
    // Create sorting object
    BubbleSort sorter;
    
    // Sort and display first array
    cout << "Array before sorting:" << endl;
    printArray(arr1, SIZE1);
    
    sorter.sort(arr1, SIZE1);
    
    cout << "\nAfter sorting:" << endl;
    printArray(arr1, SIZE1);
    cout << "\n" << sorter.getComparisonCount() << " comparisonsto sort " 
              << SIZE1 << " items" << endl;
    
    // Reset comparison count and sort second array
    BubbleSort sorter2;
    
    cout << "\nSecond array before sorting:" << endl;
    printArray(arr2, SIZE2);
    
    sorter2.sort(arr2, SIZE2);
    
    cout << "\nAfter sorting:" << endl;
    printArray(arr2, SIZE2);
    cout << "\n" << sorter2.getComparisonCount() << " comparisons to sort " 
              << SIZE2 << " items" << endl;
    
    return 0;
} 

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fillArrayWithRandomNumbers(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 200 - 100; // Random numbers between -100 and 99
    }
}