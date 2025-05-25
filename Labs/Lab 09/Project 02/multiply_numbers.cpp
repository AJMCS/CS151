/* main.cpp - Multiplies values in a binary file and rewrites them, displaying the results.
* Author: AJ McDaniel
* Lab: 9
* Project 02: Create a program to multiply numbers in the file
* Problem statement: This program opens an existing binary file created by Lab 09 Project 1, reads numbers
* stored in the file, multiplies each by a user-provided multiplier,and writes the new values back into their 
* original positions in the file.
* 
*
* Algorithm:
* 1. Prompt the user to enter the binary file name.
 * 2. Open the file using `fstream` with both input and output binary flags.
 * 3. Prompt the user to enter a multiplier (double).
 * 4. For each of the 10 integers:
 *    - Read the integer from the file.
 *    - Multiply it by the multiplier, round it to the nearest integer.
 *    - Seek back to the read position and write the new value.
 *    - Print the original and updated value.
 * 5. Repeat the same steps for the 10 doubles, but don't round them.
 *    - Print the original, updated value, and the square of the new value.
 * 6. Close the file.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    string file_name;
    cout << "Enter the name of the binary file: ";
    cin >> file_name;

    // Open file for both input and output in binary mode
    fstream data_file(file_name, ios::binary | ios::in | ios::out);
    if (!data_file) {
        cout << "Error opening file " << file_name << endl;
        return 1;
    }

    // Get multiplier from user
    double multiplier;
    cout << "Enter the multiplier: ";
    cin >> multiplier;

    // Process 10 integers
    cout << "\nReading and updating ints..." << endl;
    for (int i = 0; i < 10; i++) {
        // Store current position
        long long pos = data_file.tellg();
        
        // Read integer
        int num;
        data_file.read(reinterpret_cast<char*>(&num), sizeof(int));
        
        // Multiply and round
        int new_num = static_cast<int>(round(num * multiplier));
        
        // Go back to original position
        data_file.seekp(pos);
        
        // Write new number
        data_file.write(reinterpret_cast<char*>(&new_num), sizeof(int));
        
        // Display in required format
        cout << num << " -> " << new_num << endl;
    }

    // Process 10 doubles
    cout << "\nReading doubles..." << endl;
    cout << fixed << setprecision(5);
    for (int i = 0; i < 10; i++) {
        // Store current position
        long long pos = data_file.tellg();
        
        // Read double
        double num;
        data_file.read(reinterpret_cast<char*>(&num), sizeof(double));
        
        // Multiply
        double new_num = num * multiplier;
        double square = new_num * new_num;
        
        // Go back to original position
        data_file.seekp(pos);
        
        // Write new number
        data_file.write(reinterpret_cast<char*>(&new_num), sizeof(double));
        
        // Display in required format
        cout << num << " -> " << new_num << " (root of ";
        cout << defaultfloat << square << fixed << ")" << endl;
    }

    // Close file
    data_file.close();
    return 0;
}