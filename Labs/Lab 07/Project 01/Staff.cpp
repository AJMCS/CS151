/*
Staff.cpp - Implements the Staff.h class and showInfo method.
Author: AJ McDaniel
*/
#include "Staff.h"
#include <iostream>
using namespace std;

Staff::Staff(int id, string name, string address, string phone,
             string extension, string hireDate, double payRate)
    : personAtMCC(id, name, address, phone)
{
    this->extension = extension;
    this->hireDate = hireDate;
    this->payRate = payRate;
}

// Getters
string Staff::getExtension() const { return extension; }
string Staff::getHireDate() const { return hireDate; }
double Staff::getPayRate() const { return payRate; }

// Setters
void Staff::setExtension(const string& extension) { this->extension = extension; }
void Staff::setHireDate(const string& hireDate) { this->hireDate = hireDate; }
void Staff::setPayRate(double payRate) { this->payRate = payRate; }

void Staff::showInfo() const {
    cout << "ID: " << getId() << "  Name: " << getName()
         << "  Address: " << getAddress() << endl
         << "Phone: " << getPhone()
         << "  Extension: " << extension
         << "  Hire Date: " << hireDate
         << "  Pay Rate: " << payRate << endl;
}
