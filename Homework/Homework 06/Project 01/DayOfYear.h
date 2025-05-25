/*
DayOfYear.h - Declares the DayOfYear class and its public interface for converting between day numbers and month-day format.
Author: AJ McDaniel
*/
#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <string>
#include <iostream>

using namespace std;

class DayOfYear {
private:
    int dayOfYear;

    // Static constants for month names and days in each month
    static const string monthNames[];
    static const int daysInMonth[];
    static const int totalDays;

public:
    // Constructors
    DayOfYear(int day);
    DayOfYear(const string& month, int day);

    // Getter
    int getDayOfYear() const { return dayOfYear; }

    // Overloaded operators
    DayOfYear& operator++();    // Prefix increment
    DayOfYear operator++(int);  // Postfix increment
    DayOfYear& operator--();    // Prefix decrement
    DayOfYear operator--(int);  // Postfix decrement

    // Friend function for output
    friend ostream& operator<<(ostream& out, const DayOfYear& day);
};

#endif
