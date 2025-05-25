/*
Student.cpp - Implements the Student.h class and showInfo method.
Author: AJ McDaniel
*/

#include <iostream>
#include "Student.h"
#include "Instructor.h"
#include "Staff.h"
#include "personAtMCC.h"
using namespace std;

Student::Student(int id, string name, string address, string phone,
                 string major, int credits, bool isFourYear, bool isVeteran)
    : personAtMCC(id, name, address, phone)
{
    this->major = major;
    this->credits = credits;
    this->isFourYear = isFourYear;
    this->isVeteran = isVeteran;
}

// Getters
string Student::getMajor() const { return major; }
int Student::getCredits() const { return credits; }
bool Student::getIsFourYear() const { return isFourYear; }
bool Student::getIsVeteran() const { return isVeteran; }

// Setters
void Student::setMajor(const string& major) { this->major = major; }
void Student::setCredits(int credits) { this->credits = credits; }
void Student::setIsFourYear(bool isFourYear) { this->isFourYear = isFourYear; }
void Student::setIsVeteran(bool isVeteran) { this->isVeteran = isVeteran; }

void Student::showInfo() const {
    cout << "ID: " << getId() << "  Name: " << getName()
              << "  Address: " << getAddress() << endl
              << "Phone: " << getPhone() << endl
              << "Major: " << major << "  Credits: " << credits
              << "  4-year? " << (isFourYear ? "yes" : "no")
              << "  Veteran? " << (isVeteran ? "yes" : "no") << endl;
}
