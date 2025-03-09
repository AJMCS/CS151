/*
This file is the implementation of the Planet.h file and is responsible for articulating how each function should behave.
Author: AJ McDaniel
*/
#include <iostream>
#include <vector>
#include "Planet.h"

using namespace std;

	
Planet::Planet(string initialName, long long initialDistance, long long initialDiameter) {
	setName(initialName);
	setDistance(initialDistance);
	setDiameter(initialDiameter);
}

string Planet::getName() const {
	return name;
}

long long Planet::getDistance() const {
	return distance;
}
long long Planet::getDiameter() const {
	return diameter;
}

void Planet::setName(string newName) {
	name = newName;
}

void Planet::setDistance(long long newDistance) {
	if(newDistance > 0) {
		distance = newDistance;
	}else {
		cout << "Distance entered is invalid. Please enter a number greater than 0." << endl;
	}
}

void Planet::setDiameter(long long newDiameter) {
	if(newDiameter > 0) {
		diameter = newDiameter;
	}else {
		cout << "Diameter entered is invalid. Please enter a number greater than 0." << endl;
	}
}