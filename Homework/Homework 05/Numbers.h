/* Numbers.h - Header file for Numbers class
 * Author: AJ McDaniel
 * Module: 5
 * Project: 1
 * 
 * Purpose: This class translates whole dollar amounts (0-9999) into English words.
 * 
 * Instance Variables:
 * - number: integer value to be translated
 * - lessThan20: static array of strings for numbers 0-19
 * - tens: static array of strings for tens (20, 30, etc.)
 * - hundred: static string for "hundred"
 * - thousand: static string for "thousand"
 */

#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>
using namespace std;

class Numbers {
private:
    int number;
    static const string lessThan20[];
    static const string tens[];
    static const string hundred;
    static const string thousand;

public:
    Numbers(int num = 0);
    void print() const;
};

#endif 