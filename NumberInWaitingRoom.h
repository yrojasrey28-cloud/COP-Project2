#ifndef NUMBER_IN_WAITING_ROOM_H
#define NUMBER_IN_WAITING_ROOM_H

#include "waiting_room.h"

class NumberInWaitingRoom: public WaitingRoom {
    private:
        size_t capacity; //number of patients in the waiting room
    public:
        NumberInWaitingRoom(size_t waitingRoomCapacity);
    
        size_t getCapacity() const; //get the capacity of the waiting room
        void checkCapacity() const; //check the current capacity of the waiting room
        bool isFull() const; //check if the waiting room is full
        void checkAndRemoveIfOverCapacity(); //check if the waiting room is over capacity and remove patients from back
};

#endif