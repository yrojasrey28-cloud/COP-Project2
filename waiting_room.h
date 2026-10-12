#ifndef WAITING_ROOM_H
#define WAITING_ROOM_H

#include "patient.h"
#include <deque>

class WaitingRoom {
protected:
    std::deque<Patient> patients;

public:
    void addFront(const Patient& p);   // critical patient
    void addBack(const Patient& p);    // non-urgent patient
    bool removeFront();                // treated, leaves hospital
    bool removeBack();                 // goes to another hospital
    void displayAll() const;
    std::size_t size() const;
};


#endif