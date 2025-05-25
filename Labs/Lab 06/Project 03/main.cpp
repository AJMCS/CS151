/* main.cpp - Create a TimeDate class "owned" by an Event class.
* Author: AJ McDaniel
* Module: 06
* Project: 03
* Problem statement: Create a program that will read in a list of events from a file,
* and then display them in a sorted order by the start time.
*
* Algorithm:
* 1. Create a TimeDate class that will store the start and end times of an event.
* 2. Create an Event class that will store the start and end times of an event,
*    and the description of the event.
* 3. Create a main function that will read in a list of events from a file,
*    and then display them in a sorted order by the start time.
*/

#include <iostream>
#include <string>
using namespace std;

class TimeDate {
private:
    int hour, minute, day;
    string month;

public:
    // Constructor using member initializer list
    TimeDate(int hour, int minute, int day, string month) :
        hour(hour), minute(minute), day(day), month(month) {}

    // Function to return TimeDate as a formatted string
    string getTimeDate() {
        string print_hour = to_string(hour);
        string am_pm = (hour < 12 ? "am" : "pm");
        
        if (hour == 0)
            print_hour = "12";
        else if (hour > 12)
            print_hour = to_string(hour - 12);
            
        return month + " " + to_string(day) + 
               " at " + print_hour + ":" + 
               (minute < 10 ? "0" : "") + to_string(minute) + am_pm;
    }
};

class Event {
private:
    TimeDate start_time, end_time;
    string description;

public:
    // Constructor using member initializer list
    Event(int start_hour, int start_minute, int start_day, string start_month,
          int end_hour, int end_minute, int end_day, string end_month,
          string description) :
        start_time(start_hour, start_minute, start_day, start_month),
        end_time(end_hour, end_minute, end_day, end_month),
        description(description) {}

    // Function to return event information
    string getEvent() {
        return description + " starts at " + 
               start_time.getTimeDate() +
               ", ends at " +
               end_time.getTimeDate();
    }
};

int main() {
    // Create and display first event
    Event party(17, 30, 26, "Jan.", 20, 30, 26, "Jan.", 
                "My Birthday Party");
    cout << party.getEvent() << endl;

    // Create and display second event
    Event thanksgiving(12, 0, 28, "Nov.", 16, 0, 28, "Nov.",
                      "Thanksgiving Dinner");
    cout << thanksgiving.getEvent() << endl;

    return 0;
} 