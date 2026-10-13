/*
Class WaitingRoom manages a collection of Patient objects using a deque data structure.
It provides methods to add patients to the front or back of the deque,
remove patients from the front or back, check if a patient with a specific ID exists,
display information about all patients, and get the current size of the waiting room.
*/
#include "waiting_room.h"
#include <iostream>
using namespace std;

void WaitingRoom::addFront(const Patient &p) { patients.push_front(p); } // add an urgent patient to the front of the waiting room
void WaitingRoom::addBack(const Patient &p) { patients.push_back(p); }   // add a non-urgent patient to the back of the waiting room

bool WaitingRoom::hasId(int id) const
{ // check if a patient with the given ID exists in the waiting room
    for (const auto &p : patients)
    {
        if (p.getId() == id)
        {
            return true;
        }
    }
    return false;
}

bool WaitingRoom::removeFront()
{ // remove the patient at the front of the waiting room if they have been treated and return true if successful
    if (patients.empty())
        return false; // retutn false if there is no patient in the waiting room
    cout << patients.front().getName() << " was treated and left.\n";
    patients.pop_front();
    return true;
}

bool WaitingRoom::removeBack()
{ // remove the patient at the back of the waiting room if they are being transferred to another hospital and return true if successful
    if (patients.empty())
        return false; // return false if there is no patient in the waiting room
    cout << patients.back().getName() << " was sent to another hospital.\n";
    patients.pop_back();
    return true;
}

void WaitingRoom::displayAll() const
{ // display information about all patients in the waiting room
    if (patients.empty())
    { // when there is no patient in the waiting room
        cout << "Waiting room is empty.\n";
        return;
    }
    for (const auto &p : patients)
    {
        p.displayInfo();
        cout << "\n";
    }
}

size_t WaitingRoom::size() const { return patients.size(); } // return the current number of patients in the waiting room
