/*
Student.h - Declares the child class of a person at MiraCosta College with student specific data.
Author: AJ McDaniel
*/
#ifndef STUDENT_H
#define STUDENT_H

#include "personAtMCC.h"
#include <string>
using namespace std;

class Student : public personAtMCC {
private:
    string major;
    int credits;
    bool isFourYear;
    bool isVeteran;
public:
    Student(int id, string name, string address, string phone,
            string major, int credits, bool isFourYear, bool isVeteran);

    // Getters
    string getMajor() const;
    int getCredits() const;
    bool getIsFourYear() const;
    bool getIsVeteran() const;

    // Setters
    void setMajor(const string& major);
    void setCredits(int credits);
    void setIsFourYear(bool isFourYear);
    void setIsVeteran(bool isVeteran);

    void showInfo() const override;
};

#endif
