/* Numbers.cpp - Implementation file for Numbers class
 * Author: AJ McDaniel
 * Module: 5
 * Project: 1
 */

#include "Numbers.h"
#include <iostream>
using namespace std;

// Initialize static member variables
const string Numbers::lessThan20[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
    "seventeen", "eighteen", "nineteen"
};

const string Numbers::tens[] = {
    "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

const string Numbers::hundred = "hundred";
const string Numbers::thousand = "thousand";

// Constructor
Numbers::Numbers(int num) {
    number = num;
}

// Print function to display the English description of the number
//Handles them in order of thousands, hundreds, tens, and ones using only if statements so
//All numbers are handles as they break down into smaller components of how we say them in English.
void Numbers::print() const {
    int num = number;
    
    if (num == 0) {
        cout << lessThan20[0];
        return;
    }

    // Handle thousands
    if (num >= 1000) {
        //divide num by 1000 to get how many thousand there are
        int thousands = num / 1000;
        //print the number of thousands in english
        cout << lessThan20[thousands] << " " << thousand << " ";
        //use modulo to remove the thousands from num
        num %= 1000;
    }

    // Handle hundreds
    if (num >= 100) {
        //divide num by 100 to get how many hundreds there are
        int hundreds = num / 100;
        //print the number of hundreds in english
        cout << lessThan20[hundreds] << " " << hundred << " ";
        //use modulo to remove the hundreds from num
        num %= 100;
    }

    // Handle tens and ones
    if (num > 0) {
        //if num is less than 20, print the number in english
        if (num < 20) {
            cout << lessThan20[num];
        } else {
            //if num is 20 or greater, print the number in english
            int tensDigit = num / 10;
            int onesDigit = num % 10;
            cout << tens[tensDigit - 1];
            if (onesDigit > 0) {
                cout << " " << lessThan20[onesDigit];
            }
        }
    }
} 