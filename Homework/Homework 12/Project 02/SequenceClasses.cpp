/*
 * SequenceClasses.cpp - Implementation of sequence classes
 * Author: AJ McDaniel
 */

#include "SequenceClasses.h"

// Returns the nth even number (0, 2, 4, 6, ...)
int EvenSequence::fun(int value) {
    return 2 * value;
}

// Returns the factorial of value (n!)
int FactorialSequence::fun(int value) {
    if (value == 0 || value == 1) {
        return 1;
    }
    int result = 1;
    for (int i = 2; i <= value; i++) {
        result *= i;
    }
    return result;
} 