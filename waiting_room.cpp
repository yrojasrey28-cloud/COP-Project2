#include "waiting_room.h"
#include <iostream>
using namespace std;

void WaitingRoom::addFront(const Patient& p) { patients.push_front(p); }
void WaitingRoom::addBack(const Patient& p)  { patients.push_back(p); }

bool WaitingRoom::removeFront() {
    if (patients.empty()) return false;
    cout << patients.front().getName() << " was treated and left.\n";
    patients.pop_front();
    return true;
}

bool WaitingRoom::removeBack() {
    if (patients.empty()) return false;
    cout << patients.back().getName() << " was sent to another hospital.\n";
    patients.pop_back();
    return true;
}

void WaitingRoom::displayAll() const {
    if (patients.empty()) {
        cout << "Waiting room is empty.\n";
        return;
    }
    for (const auto& p : patients) {
        p.displayInfo();
        cout << "\n";
    }
}

size_t WaitingRoom::size() const { return patients.size(); }


