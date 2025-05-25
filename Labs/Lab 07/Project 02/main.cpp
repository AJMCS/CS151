/* main.cpp - Tests the Animal class and its derived Fox and Owl classes with sample output.
* Author: AJ McDaniel
* Lab: 7
* Project 02: Animal Inheritance

* Problem Statement:
* This program demonstrates inheritance by modeling animals.
*
* Algorithm:
* 1. Create an Animal object named Oscar.
* 2. Create an Owl object named Errol of breed "Great Grey".
* 3. Create a Fox object named Foxy.
* 4. Call showInfo() for all three animals to display their details.
* 5. Call makeNoise() for all three to demonstrate behavior-specific sound output.
* 6. Call sleep() for all three animals to demonstrate inherited behavior.
*/
#include "Animal.h"
#include "Fox.h"
#include "Owl.h"
#include <iostream>
using namespace std;

int main() {
    // Create objects
    Animal oscar("Oscar");
    Owl errol("Errol", "Great Grey");
    Fox foxy("Foxy");

    // Show info for all animals
    cout << "\nShowing info for all animals:" << endl;
    oscar.showInfo();
    errol.showInfo();
    foxy.showInfo();

    // Make noise
    cout << "\nMaking noise:" << endl;
    oscar.makeNoise();
    errol.makeNoise();
    foxy.makeNoise();

    // Sleep
    cout << "\nSleeping:" << endl;
    oscar.sleep();
    errol.sleep();
    foxy.sleep();

    return 0;
} 