/*
PersonAtMCC.cpp - Implements the base class of a person at MiraCosta College.
Author: AJ McDaniel
*/
#include "personAtMCC.h"
#include <iostream>
using namespace std;

personAtMCC::personAtMCC() : id(0), name(""), address(""), phone("") {}

personAtMCC::personAtMCC(int id, string name, string address, string phone) {
    setId(id);
    setName(name);
    setAddress(address);
    setPhone(phone);
}

void personAtMCC::setId(int id) { this->id = id; }
void personAtMCC::setName(const string& name) { this->name = name; }
void personAtMCC::setAddress(const string& address) { this->address = address; }
void personAtMCC::setPhone(const string& phone) { this->phone = phone; }

int personAtMCC::getId() const { return id; }
string personAtMCC::getName() const { return name; }
string personAtMCC::getAddress() const { return address; }
string personAtMCC::getPhone() const { return phone; }

void personAtMCC::showInfo() const {
    cout << "ID: " << id << "  Name: " << name << "  Address: " << address << endl;
    cout << "Phone: " << phone << endl;
}