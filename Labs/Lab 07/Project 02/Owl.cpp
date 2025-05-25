/*
* Owl.cpp - Implements the Owl child class with owl-specific behavior
* Author: AJ McDaniel
*/

#include "Owl.h"
#include <iostream>
using namespace std;

Owl::Owl(string name, string breed) : Animal(name), breed(breed) {
    cout << "A Owl " << name << " of breed " << breed << " has been created." << endl;
}

string Owl::getBreed() const {
    return breed;
}

void Owl::setBreed(string breed) {
    this->breed = breed;
}

void Owl::makeNoise() {
    cout << "The Owl " << getName() << " is hooting." << endl;
}

void Owl::showInfo() {
    cout << "The Owl " << getName() << " of breed " << breed << endl;
} 