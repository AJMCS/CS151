#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


int main(){
    double average_temp = 0;
    int sum = 0;
    int max_temp_loc = 0;
    int min_temp_loc = 0;
    int max_temp = -1000;
    int min_temp = 1000;

    double temperature[] = {38, 42, 50, 61, 72, 79, 84, 83, 75, 64, 54, 43};
    string month_name[] = {
    "January", 
    "February", 
    "March", 
    "April", 
    "May", 
    "June", 
    "July", 
    "August", 
    "September", 
    "October", 
    "November", 
    "December"};


    for(int i = 0; i < sizeof(temperature); i++)
    {

        if (max_temp < temperature[i]){
            max_temp = temperature[i];
            max_temp_loc = i;
        }

        if (min_temp > temperature[i]){
            min_temp = temperature[i];
            min_temp_loc = i;
        }

        sum += temperature[i];
    }

    average_temp = sum / 12.0;

    cout << "The warmest month is " << month_name[max_temp_loc] << "with a temperature of " << temperature[max_temp_loc] << "F" << endl;
    cout << "The coolest month is " << month_name[min_temp_loc] << "with a temperature of " << temperature[min_temp_loc] << "F" << endl;
    cout << "The average termpature in new york throughout the year is: " << setprecision(2) << average_temp << "F" << endl;
}