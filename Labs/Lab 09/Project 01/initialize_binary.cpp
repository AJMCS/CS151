/* Name.cpp - description
* Author: AJ McDaniel
* Lab: 9
* Project 01: Initialize a binary file with 20 numbers
* Problem statement: This program creates a binary file named "array.dat" containing 20 values
* that are written directly in binary format.
* 
*
* Algorithm: 
* 1. Declare a constant string for the output file name ("array.dat").
 * 2. Open an `ofstream` in binary output mode.
 *    - If opening the file fails, print an error and exit with code 1.
 * 3. Write the integers 1 to 10 to the file using `write()` and `reinterpret_cast`.
 * 4. Compute and write the square root of each integer using `sqrt()` and store as `double`.
 * 5. Close the file and display a success message.
 */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    // Step 3: Create string constant for filename
    const string filename = "array.dat";

    // Step 4: Open binary output file
    ofstream data_file(filename, ios::binary | ios::out);
    if (!data_file) {
        cout << "Error: Could not open file " << filename << " for writing." << endl;
        return 1;
    }

    // Step 5: Write numbers 1-10 as integers
    for (int i = 1; i <= 10; i++) {
        data_file.write(reinterpret_cast<char*>(&i), sizeof(int));
    }

    // Step 6: Write square roots of numbers 1-10 as doubles
    for (int i = 1; i <= 10; i++) {
        double sqrt_value = sqrt(i);
        data_file.write(reinterpret_cast<char*>(&sqrt_value), sizeof(double));
    }

    // Step 7: Close the file
    data_file.close();

    cout << "Binary file has been created successfully!" << endl;
    return 0;
} 