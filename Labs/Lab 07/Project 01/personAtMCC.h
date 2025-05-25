/*
PersonAtMCC.h - Declares the base class of a person at MiraCosta College.
Author: AJ McDaniel
*/
#ifndef PERSON_AT_MCC_H
#define PERSON_AT_MCC_H

#include <string>
using namespace std;

class personAtMCC {
private:
    int id;
    string name;
    string address;
    string phone;
public:
    personAtMCC();
    personAtMCC(int id, string name, string address, string phone);

    // Setters
    void setId(int id);
    void setName(const string& name);
    void setAddress(const string& address);
    void setPhone(const string& phone);

    // Getters
    int getId() const;
    string getName() const;
    string getAddress() const;
    string getPhone() const;

    virtual void showInfo() const;
};

#endif
