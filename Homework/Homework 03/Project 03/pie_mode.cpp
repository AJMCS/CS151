/* PieMode.cpp - Determine how many pieces of pie most people eat in a year by finding the mode.
* Author: AJ McDaniel
* Module: 3
* Project 03: Pie à la "Mode"
* Problem statement: This program gathers input from 15 people about how many slices of pie they eat per year. It dynamically allocates an array
 * sorts them, and calculates and displays the "mode" which si the number that appears most frequently.
 * 
* 
*
* Algorithm:
* 1. 
*/
#include <iostream>
using namespace std;

// Function to find the mode of an array
int findMode(int* arr, int size) {
    int currentValue = arr[0];
    int currentCount = 1;
    int maxCount = 1;
    int mode = arr[0];
    
    // Scan through sorted array to find mode
    for (int i = 1; i < size; i++) {
        if (*(arr + i) == currentValue) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                mode = currentValue;
            }
            currentValue = *(arr + i);
            currentCount = 1;
        }
    }
    
    // Check last group
    if (currentCount > maxCount) {
        mode = currentValue;
    }
    
    return mode;
}

// Function to sort array uisng bubble sort
void sortArray(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                // Swap elements
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    const int NUM_RESPONSES = 15;
    int* responses = new int[NUM_RESPONSES];
    
    // Get responses from users
    cout << "Enter the number of pie slices eaten per year for " << NUM_RESPONSES << " people:\n";
    for (int i = 0; i < NUM_RESPONSES; i++) {
        do {
            cout << "Person " << (i + 1) << ": ";
            cin >> *(responses + i);
            if (*(responses + i) < 0) {
                cout << "Please enter a non-negative number.\n";
            }
        } while (*(responses + i) < 0);
    }
    
    // Sort the array
    sortArray(responses, NUM_RESPONSES);
    
    // Print sorted responses
    cout << "\nSorted responses:\n";
    for (int i = 0; i < NUM_RESPONSES; i++) {
        cout << *(responses + i) << " ";
    }
    cout << "\n\n";
    
    // Find and display the mode
    int mode = findMode(responses, NUM_RESPONSES);
    cout << "The mode is: " << mode << endl;
    
    // Clean up dynamically allocated memory
    delete[] responses;
    
    return 0;
} 