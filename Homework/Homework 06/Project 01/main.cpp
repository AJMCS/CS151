/* main.cpp - Demonstrates all features of the DayOfYear class.
 * Author: AJ McDaniel
 * Module: 6
 * Project 01: Day of the Year

 * Problem Statement:
 * This program uses the DayOfYear class to convert between integer day numbers (1 to 365)
 * and their corresponding month-day formats.

 * Algorithm:
 * 1. Create five DayOfYear objects using the integer-based constructor (15, 31, 59, 180, 360).
 *    - Print each one showing both the original number and the converted month-day format.
 * 2. Create four more DayOfYear objects using month and day: "January 1", "March 4", "July 25", and "December 31".
 *    - Print the corresponding day-of-year number for each.
 * 3. Demonstrate prefix -- on January 1 (wraps to December 31).
 * 4. Demonstrate prefix ++ on March 4 (becomes March 5).
 * 5. Demonstrate postfix -- on July 25 (prints July 25, then July 24).
 * 6. Demonstrate postfix ++ on December 31 (prints December 31, then wraps to January 1).
 * 7. Attempt to create an invalid date ("February 30") to show input validation via exceptions.
 * 8. Catch all exceptions and print user-friendly error messages.
 */

#include "DayOfYear.h"
#include <iostream>

using namespace std;

int main() {
    try {
        // Demonstrate first constructor
        cout << "First constructor:\n";
        int testDays[] = {15, 31, 59, 180, 360};
        for (int day : testDays) {
            DayOfYear date(day);
            cout << "Day " << day << " is " << date << endl;
        }
        cout << endl;

        // Demonstrate 2nd constructor
        cout << "Second construcotr:\n";
        DayOfYear date1("January", 1);
        DayOfYear date2("March", 4);
        DayOfYear date3("July", 25);
        DayOfYear date4("December", 31);

        cout << "January 1 is day " << date1.getDayOfYear() << endl;
        cout << "March 4 is day " << date2.getDayOfYear() << endl;
        cout << "July 25 is day " << date3.getDayOfYear() << endl;
        cout << "December 31 is day " << date4.getDayOfYear() << endl;
        cout << endl;

        // Demonstrate prefix -- operator
        cout << "Using January 1 (day 1):\n";
        cout << "The original value: " << date1 << endl;
        cout << "Using prefix--    : " << --date1 << endl;
        cout << "After prefix--    : " << date1 << endl;
        cout << endl;

        // Demonstrate prefix ++ operator
        cout << "Using March 4 (day " << date2.getDayOfYear() << "):\n";
        cout << "The original value: " << date2 << endl;
        cout << "Using prefix++    : " << ++date2 << endl;
        cout << "After prefix++    : " << date2 << endl;
        cout << endl;

        // Demonstrate postfix -- operator
        cout << "Using July 25 (day " << date3.getDayOfYear() << "):\n";
        cout << "The original value: " << date3 << endl;
        cout << "Using postfix--   : " << date3-- << endl;
        cout << "After postfix--   : " << date3 << endl;
        cout << endl;

        // Demonstrate postfix ++ operator
        cout << "Using December 31 (day " << date4.getDayOfYear() << "):\n";
        cout << "The original value: " << date4 << endl;
        cout << "Using postfix++   : " << date4++ << endl;
        cout << "After postfix++   : " << date4 << endl;
        cout << endl;

        // Demonstrate invalid input
        cout << "Invalid input example:\n";
        try {
            DayOfYear invalidDate("February", 30);
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
