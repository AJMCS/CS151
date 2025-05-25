/*
* Fox.h - Declares the Fox child class that inherits from Animal
* Author: AJ McDaniel
*/

#ifndef FOX_H
#define FOX_H
#include "Animal.h"
using namespace std;

class Fox : public Animal {
public:
    Fox(string name);
    void makeNoise() override;
    void showInfo() override;
};

#endif 