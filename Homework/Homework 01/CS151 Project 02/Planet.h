/*
This file is responsible for defining the characteristics and functionality of this class. It contains no implementation, but a high-level overview.
Author: AJ McDaniel
*/
#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Planet {
    private: //contains member variables
    string name;
    long long distance; //kilometers
    long long diameter; //kilometers

    public: //Contains constructor, getters, and setters.
    Planet(string initialName, long long initialDistance, long long initialDiameter);
    string getName() const;
    long long getDistance() const;
    long long getDiameter() const;
    void setName(string newName);
    void setDistance(long long newDistance);
    void setDiameter(long long newDiameter);
};
#endif