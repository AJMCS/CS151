/* main.cpp - Recursively searches for a value in an array.
* Author: AJ McDaniel
* Module: 11
* Project 02: Recursive Member Test
* Problem statement: This program demonstrates the use of a recursive function named isMember, which checks
* whether a given integer value exists in an array.
* 
*
* Algorithm:
* 1. Define a recursive function isMember():
 *    - If the array size is 0, return false.
 *    - If the last element matches the search value, return true.
 *    - Otherwise, call isMember() again with the size reduced by 1.
 * 2. In main():
 *    - Prompt the user to input 5 numbers into an array.
 *    - Prompt for 2 values that should exist in the array, and check with isMember().
 *    - Prompt for 2 values that should not exist in the array, and check again.
 *    - Print whether each value was found.
 */

#include <iostream>
using namespace std;

//Prototypes
bool isMember(const int arr[], int size, int value);

int main() {
    const int ARRAY_SIZE = 5;
    int numbers[ARRAY_SIZE];
    
    // Get numbers from user
    cout << "Enter " << ARRAY_SIZE << " numbers:\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cin >> numbers[i];
    }
    
    // Display the array
    cout << "\nYou entered: ";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n\n";
    
    // Search for two numbers that are in the array
    int searchValue;
    cout << "Enter a number to search for that is in the array: ";
    cin >> searchValue;
    if (isMember(numbers, ARRAY_SIZE, searchValue)) {
        cout << searchValue << " was found in the array.\n";
    } else {
        cout << searchValue << " was not found in the array.\n";
    }
    
    cout << "Enter another number to search for that's in the array: ";
    cin >> searchValue;
    if (isMember(numbers, ARRAY_SIZE, searchValue)) {
        cout << searchValue << " was found in the array.\n";
    } else {
        cout << searchValue << " was not found in the array.\n";
    }
    
    // Search for two numbers that are not in the array
    cout << "\nEnter a number to search for should not be in the array: ";
    cin >> searchValue;
    if (isMember(numbers, ARRAY_SIZE, searchValue)) {
        cout << searchValue << " was found in the array.\n";
    } else {
        cout << searchValue << " was not found in the array.\n";
    }
    
    cout << "Enter another number to search for that should not be in the array: ";
    cin >> searchValue;
    if (isMember(numbers, ARRAY_SIZE, searchValue)) {
        cout << searchValue << " was found in the array.\n";
    } else {
        cout << searchValue << " was not found in the array.\n";
    }
    
    return 0;
} 

// Recursive function to check if a value exists in an array
bool isMember(const int arr[], int size, int value) {
    // Base case: if size is 0, value not found
    if (size == 0) {
        return false;
    }
    
    // Base case: if last element matches value
    if (arr[size - 1] == value) {
        return true;
    }
    
    // Recursive case: check the rest of the array
    return isMember(arr, size - 1, value);
}