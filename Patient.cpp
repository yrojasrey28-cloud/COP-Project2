/* Patient.cpp implements the methods for the Patient class */
#include "Patient.h"
#include <iostream>
using namespace std;\

// Constructor implementation
Patient::Patient(int id, string name, int age, string status) 
    : id(id), name(name), age(age), status("Waiting") {} 

// Display patient information
void Patient::displayInfo() const {
    cout << "Patient ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Status: " << status << endl;
}

// Implementation of getter and setter methods
int Patient:: getId() const {
    return id;
}

string Patient::getName() const {
    return name;
}

void Patient:: setName (string newName) {
    name = newName;
}

string Patient:: setStatus(string newStatus) {
    status = newStatus;
    return status; //?
}



