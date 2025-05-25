/*
* Owl.h - Declares the Owl child class that inherits from Animal
* Author: AJ McDaniel
*/

#ifndef OWL_H
#define OWL_H
#include "Animal.h"
using namespace std;

class Owl : public Animal {
private:
    string breed;

public:
    Owl(string name, string breed);
    string getBreed() const;
    void setBreed(string breed);
    void makeNoise() override;
    void showInfo() override;
};

#endif 