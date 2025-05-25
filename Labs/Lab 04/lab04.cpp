/* Lab04.cpp - using time variable to print today's date in various formats
* Author: AJ McDaniel
* Module: 4
* Lab 04: Using Time
* Problem statement: This lab is to manipulate a time variable and corresponding structure, 
* print today's date and time in various formats, and determine how to adjust the internal form 
* of other dates.
* 
*
* Algorithm:
* 1. Include necessary headers (iostream, ctime, iomanip, string) and use the standard namespace.
* 2. Declare arrays for the names of the days of the week and months of the year.
* 3. Set the timezone to Pacific Time using setenv or _putenv_s depending on the platform.
* 4. Get the current time using time_t and localtime(), store in a tm struct pointer.
* 5. Print today’s date using three formats:
*    a. Numeric format (m/d/yy)
*    b. Full month name format (e.g., April 1, 2023)
*    c. Abbreviated format (e.g., 1-Apr-2023)
* 6. Repeat the same three formats using the strftime() function.
* 7. Print the current time in both 24-hour and 12-hour formats using strftime().
* 8. Create a tm struct for an important event and populate the fields (year, month, day, time, etc.).
* 9. Use mktime() to convert the event time to seconds since epoch.
* 10. Print the date and time of the event using ctime(), along with the number of seconds since epoch.
* 11. Calculate the number of seconds in one week by multiplying days, hours, minutes, and seconds.
* 12. Subtract one week’s worth of seconds from the event time and print the result using ctime().
* 13. Use strftime() and the earlier day name array to print the weekday and day-of-year of the event.
*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    // Arrays for days of week and months
    string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string months[] = {"January", "February", "March", "April", "May", "June", 
                      "July", "August", "September", "October", "November", "December"};

    // Set timezone to Pacific Time
    #ifdef _WIN32
        _putenv_s("TZ", "PST8PDT");
    #else
        setenv("TZ", "PST8PDT", 1);
    #endif
    tzset();

    // Get current time
    time_t now = time(NULL);
    tm* local = localtime(&now);

    // Print today's date in various formats using structure elements
    cout << "\nToday's date in various formats:" << endl;
    cout << "        Format:                Today:    " << endl;
    cout << "   m/d/yy:              " << local->tm_mon + 1 << "/" 
         << local->tm_mday << "/" << (local->tm_year + 1900) % 100 << endl;
    cout << "   January 1, 2000:     " << months[local->tm_mon] << " " 
         << local->tm_mday << ", " << local->tm_year + 1900 << endl;
    cout << "   d-mmm-year:          " << local->tm_mday << "-" 
         << months[local->tm_mon].substr(0, 3) << "-" << local->tm_year + 1900 << endl;

    // Print same information using strftime
    char buffer[100];
    cout << "\nToday's date using the strftime function:" << endl;
    cout << "        Format:                Today:    " << endl;
    strftime(buffer, sizeof(buffer), "%m/%d/%y", local);
    cout << "   m/d/yy:              " << buffer << endl;
    strftime(buffer, sizeof(buffer), "%B %d, %Y", local);
    cout << "   January 1, 2000:     " << buffer << endl;
    strftime(buffer, sizeof(buffer), "%d-%b-%Y", local);
    cout << "   d-mmm-year:          " << buffer << endl;

    // Print current time in 24-hour and 12-hour formats
    cout << "\nHere's the current time in two formats:" << endl;
    strftime(buffer, sizeof(buffer), "%H:%M", local);
    cout << "   " << buffer << "     <24-hour>" << endl;
    strftime(buffer, sizeof(buffer), "%I:%M%p", local);
    cout << "   " << buffer << "    <12-hour>" << endl;

    // Create a tm structure for an event
    tm event;
    event.tm_year = 2024 - 1900;  
    event.tm_mon = 5;             
    event.tm_mday = 15;           
    event.tm_hour = 10;           
    event.tm_min = 0;             
    event.tm_sec = 0;             
    event.tm_isdst = -1;         

    // Convert event time to time_t
    time_t time_of_event = mktime(&event);

    // Print event information
    cout << "\nMy cousin's birthday occurred on " << ctime(&time_of_event);
    cout << "and occurred " << time_of_event << " seconds after epoch!" << endl;

    // Calculate seconds in a week
    const int SECONDS_IN_WEEK = 7 * 24 * 60 * 60;
    cout << "There are " << SECONDS_IN_WEEK << " seconds in a week" << endl;

    // Calculate and print time one week before event
    time_t week_before = time_of_event - SECONDS_IN_WEEK;
    cout << "The week before was " << ctime(&week_before);

    // Print day of week and day of year for the event
    tm* event_local = localtime(&time_of_event);
    cout << "The event was on a " << days[event_local->tm_wday] 
         << ", day of the year: " << event_local->tm_yday + 1 << endl;

    return 0;
} 