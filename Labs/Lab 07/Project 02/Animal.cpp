/*
* Animal.cpp - Implements the Animal class
* Author: AJ McDaniel
*/

#include "Animal.h"
#include <iostream>
using namespace std;

Animal::Animal(string name) : name(name) {
    cout << "The Animal " << name << " has been created." << endl;
}

string Animal::getName() const {
    return name;
}

void Animal::setName(string name) {
    this->name = name;
}

void Animal::sleep() {
    cout << "The Animal " << name << " is sleeping." << endl;
}

void Animal::makeNoise() {
    cout << "The Animal " << name << " is making a noise." << endl;
}

void Animal::showInfo() {
    cout << "The Animal " << name << endl;
} 