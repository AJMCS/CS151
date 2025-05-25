/*
Instructor.h - Declares the child class of a person at MiraCosta College with instructor specific data.
Author: AJ McDaniel
*/
#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "personAtMCC.h"
#include <string>
using namespace std;

class Instructor : public personAtMCC {
private:
    string department;
    bool isPermanent;
    double payRate;
    int hours;
public:
    Instructor(int id, string name, string address, string phone,
               string department, bool isPermanent, double payRate, int hours);

    // Getters
    string getDepartment() const;
    bool getIsPermanent() const;
    double getPayRate() const;
    int getHours() const;

    // Setters
    void setDepartment(const string& department);
    void setIsPermanent(bool isPermanent);
    void setPayRate(double payRate);
    void setHours(int hours);

    void showInfo() const override;
};

#endif
