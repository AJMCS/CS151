#ifndef PLANET_H
#define PLANET_H

#include <iostream>

using namespace std;

class planet {
    private:
    string name;
    long long distance; //kilometers
    long long diameter; //kilometers

    public:
    string getName();
    long long getDistance();
    long long getDiameter();
    void setName();
    void setDistance();
    void setDiameter();
};
#endif
