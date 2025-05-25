/*
DayOfYear.cpp - Implements the logic for DayOfYear.h file.
Author: AJ McDaniel
*/

#include "DayOfYear.h"
#include <stdexcept>

using namespace std;

// Initialize static members
const string DayOfYear::monthNames[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

const int DayOfYear::daysInMonth[] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

const int DayOfYear::totalDays = 365;

// Constructor that takes day of year
DayOfYear::DayOfYear(int day) {
    if (day < 1 || day > totalDays) {
        throw invalid_argument("Day must be between 1 and 365");
    }
    dayOfYear = day;
}

// Constructor that takes month and day
DayOfYear::DayOfYear(const string& month, int day) {
    // Find the month index
    int monthIndex = -1;
    for (int i = 0; i < 12; i++) {
        if (monthNames[i] == month) {
            monthIndex = i;
            break;
        }
    }

    if (monthIndex == -1) {
        throw invalid_argument("Invalid month name");
    }

    if (day < 1 || day > daysInMonth[monthIndex]) {
        throw invalid_argument("Invalid day for the given month");
    }

    // Calculate the day of year
    dayOfYear = day;
    for (int i = 0; i < monthIndex; i++) {
        dayOfYear += daysInMonth[i];
    }
}

// Prefix increment operator
DayOfYear& DayOfYear::operator++() {
    dayOfYear = (dayOfYear % totalDays) + 1;
    return *this;
}

// Postfix increment operator
DayOfYear DayOfYear::operator++(int) {
    DayOfYear temp = *this;
    dayOfYear = (dayOfYear % totalDays) + 1;
    return temp;
}

// Prefix decrement operator
DayOfYear& DayOfYear::operator--() {
    dayOfYear = (dayOfYear - 2 + totalDays) % totalDays + 1;
    return *this;
}

// Postfix decrement operator
DayOfYear DayOfYear::operator--(int) {
    DayOfYear temp = *this;
    dayOfYear = (dayOfYear - 2 + totalDays) % totalDays + 1;
    return temp;
}

// Output operator
ostream& operator<<(ostream& out, const DayOfYear& day) {
    int remainingDays = day.dayOfYear;
    int monthIndex = 0;

    while (remainingDays > DayOfYear::daysInMonth[monthIndex]) {
        remainingDays -= DayOfYear::daysInMonth[monthIndex];
        monthIndex++;
    }

    out << DayOfYear::monthNames[monthIndex] << " " << remainingDays;
    return out;
}
