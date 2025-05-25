/*
* Animal.h - Declares the Animal base class with basic behavior
* Author: AJ McDaniel
*/

#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using namespace std;

class Animal {
private:
    string name;

public:
    Animal(string name);
    string getName() const;
    void setName(string name);
    void sleep();
    virtual void makeNoise();
    virtual void showInfo();
};

#endif 