/* Patient.cpp implements the methods for the Patient class */
#include "Patient.h"
#include <iostream>
using namespace std;

// Constructor holds patients objects with their information, and sets the default status to "non-urgent"
Patient::Patient(int id, string name, int age, string status)
    : id(id), name(name), age(age), status("non-urgent") {}

// Display patient information
void Patient::displayInfo() const
{
    cout << "Patient ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Status: " << status << endl;
}

// Implementation of getter and setter methods
int Patient::getId() const
{ // Gets the patient ID
    return id;
}

string Patient::getName() const
{ // Gets the patient name
    return name;
}

void Patient::setName(string newName)
{ // Sets the patient name
    name = newName;
}

string Patient::setStatus(string newStatus)
{ // Sets the patient status and updates the status to the new value
    status = newStatus;
    return status; //?
}

Patient::~Patient() = default; // Destructor for the Patient class
