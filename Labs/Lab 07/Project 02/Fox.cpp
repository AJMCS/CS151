/*
* Fox.cpp - Implements the Fox child class with fox-specific behavior
* Author: AJ McDaniel
*/

#include "Fox.h"
#include <iostream>
using namespace std;

Fox::Fox(string name) : Animal(name) {
    cout << "A Fox " << name << " has been created." << endl;
}

void Fox::makeNoise() {
    cout << "The Fox " << getName() << " is yelping." << endl;
}

void Fox::showInfo() {
    cout << "The Fox " << getName() << endl;
} 