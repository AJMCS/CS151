/*
Instructor.cpp - Implements the Instructor.h class and showInfo method.
Author: AJ McDaniel
*/
#include "Instructor.h"
#include <iostream>
using namespace std;

Instructor::Instructor(int id, string name, string address, string phone,
                       string department, bool isPermanent, double payRate, int hours)
    : personAtMCC(id, name, address, phone)
{
    this->department = department;
    this->isPermanent = isPermanent;
    this->payRate = payRate;
    this->hours = hours;
}

// Getters
string Instructor::getDepartment() const { return department; }
bool Instructor::getIsPermanent() const { return isPermanent; }
double Instructor::getPayRate() const { return payRate; }
int Instructor::getHours() const { return hours; }

// Setters
void Instructor::setDepartment(const string& department) { this->department = department; }
void Instructor::setIsPermanent(bool isPermanent) { this->isPermanent = isPermanent; }
void Instructor::setPayRate(double payRate) { this->payRate = payRate; }
void Instructor::setHours(int hours) { this->hours = hours; }

void Instructor::showInfo() const {
    cout << "ID: " << getId() << "  Name: " << getName()
              << "  Address: " << getAddress() << endl
              << "Phone: " << getPhone() << endl
              << "Department: " << department
              << "  Permanent?: " << (isPermanent ? "yes" : "no")
              << "  Pay-Rate: " << payRate
              << "  Hours: " << hours << endl;
}
