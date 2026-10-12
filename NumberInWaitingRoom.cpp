/*
Class NumberInWaitingRoom inherits from Class WaitingRoom.
It adds functionality to manage the capacity of the waiting room with methods 
to get the current capacity, check the current capacity, check if the waiting room is full, 
and remove patients from the back of Deque if the waiting room exceeds its capacity.
*/
#include "NumberInWaitingRoom.h"
#include <iostream>
using namespace std;

NumberInWaitingRoom::NumberInWaitingRoom(size_t waitingRoomCapacity) : capacity(waitingRoomCapacity) {
    capacity = waitingRoomCapacity;
}

size_t NumberInWaitingRoom::getCapacity() const { 
    return capacity; //return the capacity of the waiting room
}
void NumberInWaitingRoom::checkCapacity() const {
    cout << "Current number of patients: " << size() << endl; //return the current number of patients in the waiting room
    cout << "Maximum capacity: " << capacity << endl; //return the maximum capacity of the waiting room
}

bool NumberInWaitingRoom::isFull() const {
    return size() >= capacity; //return true if the waiting room is full, false otherwise
}
void NumberInWaitingRoom::checkAndRemoveIfOverCapacity() {
    while (size() > capacity) {
        cout << "Hospital is over capacity. ";
        removeBack(); //remove patients from the back of the waiting room Deque until it is no longer over capacity
    }
}