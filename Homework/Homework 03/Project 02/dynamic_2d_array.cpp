/* dynamic_2d_array.cpp - Demonstration of dynamically allocating a 2D array
* Author: AJ McDaniel
* Module: 3
* Project 02: Dynamic Allocation of Two-Dimensional
* Problem statement: The programs demonstrates two different techniques for 
* creating a 2D array in C++.
* 
*
* Algorithm:
* 1. Define constants for HEIGHT (4), WIDTH (5), and SIZE (20).
 * 2. Dynamically allocate a 1D array of integers of size 20.
 * 3. Populate the array with random integers between 1 and 99 using `rand()`.
 * 4. Print the entire array, its total sum, and average.
 * 5. Interpret the 1D array as a 4x5 2D array using pointer arithmetic:
 *    a. Loop through each row.
 *    b. Print all 5 values for that row.
 *    c. Compute and display the row’s total and average.
 * 6. Print the grand total and average from the 2D interpretation.
 * 7. Dynamically allocate a 2D "array-of-arrays" (int**), allocating each row individually.
 * 8. Copy the values from the 1D array to the corresponding positions in the new 2D array.
 * 9. Print the new 2D array row by row with totals and averages just as before.
 * 10. Print the grand total and average again to confirm they match.
 * 11. Deallocate memory:
 *     a. Delete the 1D array with `delete[]`.
 *     b. Loop through each row in the 2D array and delete them.
 *     c. Delete the outer array of pointers.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to print a row of numbers with total and average
void printRow(const int* row, int width, int rowNum) {
    cout << "Row " << rowNum << ": ";
    int total = 0;
    
    // Print numbers
    for (int i = 0; i < width; i++) {
        cout << setw(4) << row[i] << " ";
        total += row[i];
    }
    
    // Print total and average
    double average = static_cast<double>(total) / width;
    cout << " Total: " << setw(4) << total << "  Average: " << fixed << setprecision(2) << average << endl;
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(nullptr)));
    
    const int HEIGHT = 4;
    const int WIDTH = 5;
    const int SIZE = HEIGHT * WIDTH;
    
    // Step 1: Create and fill 1D array
    int* arr1D = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr1D[i] = rand() % 99 + 1;  // Random numbers 1-99
    }
    
    // Step 2: Print original array
    cout << "              Original array of 20 numbers " << endl;
    int total1D = 0;
    for (int i = 0; i < SIZE; i++) {
        cout << setw(4) << arr1D[i] << " ";
        total1D += arr1D[i];
    }
    cout << endl;
    cout << "                Total: " << setw(4) << total1D 
         << "  Average: " << fixed << setprecision(2) << static_cast<double>(total1D) / SIZE << endl << endl;
    
    // Step 3 & 4: Print as 2D array using first technique
    cout << "           Using a 4 x 5 array " << endl;
    int total2D = 0;
    for (int row = 0; row < HEIGHT; row++) {
        printRow(&arr1D[row * WIDTH], WIDTH, row);
        // Calculate row total
        int rowTotal = 0;
        for (int col = 0; col < WIDTH; col++) {
            rowTotal += arr1D[row * WIDTH + col];
        }
        total2D += rowTotal;
    }
    cout << "                         Grand Total: " << setw(4) << total2D 
         << "  Average: " << fixed << setprecision(2) << static_cast<double>(total2D) / SIZE << endl << endl;
    
    // Step 5: Create array-of-arrays
    int** arr2D = new int*[HEIGHT];
    for (int i = 0; i < HEIGHT; i++) {
        arr2D[i] = new int[WIDTH];
    }
    
    // Copy values from 1D array to 2D array
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            arr2D[row][col] = arr1D[row * WIDTH + col];
        }
    }
    
    // Step 6: Print array-of-arrays
    cout << "                Using an array-of-arrays " << endl;
    int total2DArray = 0;
    for (int row = 0; row < HEIGHT; row++) {
        printRow(arr2D[row], WIDTH, row);
        // Calculate row total
        int rowTotal = 0;
        for (int col = 0; col < WIDTH; col++) {
            rowTotal += arr2D[row][col];
        }
        total2DArray += rowTotal;
    }
    cout << "                         Grand Total: " << setw(4) << total2DArray 
         << "  Average: " << fixed << setprecision(2) << static_cast<double>(total2DArray) / SIZE << endl;
    
    // Step 7: Deallocate arrays
    delete[] arr1D;
    
    for (int i = 0; i < HEIGHT; i++) {
        delete[] arr2D[i];
    }
    delete[] arr2D;
    
    return 0;
} 