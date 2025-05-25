/*
Staff.h - Declares the child class of a person at MiraCosta College with staff specific data.
Author: AJ McDaniel
*/
#ifndef STAFF_H
#define STAFF_H

#include "personAtMCC.h"
#include <string>
using namespace std;

class Staff : public personAtMCC {
private:
    string extension;
    string hireDate;
    double payRate;
public:
    Staff(int id, string name, string address, string phone,
          string extension, string hireDate, double payRate);

    // Getters
    string getExtension() const;
    string getHireDate() const;
    double getPayRate() const;

    // Setters
    void setExtension(const string& extension);
    void setHireDate(const string& hireDate);
    void setPayRate(double payRate);

    void showInfo() const override;
};

#endif
