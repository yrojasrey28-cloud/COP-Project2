/* Patient.h holds the declaration of base class for patient objects,
    with methods for managing patient information */
#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

class Patient { 
    protected: // Protected members can be accessed by derived classes
        int id; // Patient Id to keep track of the patient
        string name; // Patient name
        int age; // Patient age
        string status; // Patient status

    public:
        // Constructor
        Patient(int id, string name, int age, string status);

        // Set and Get Methods 
        virtual void displayInfo() const; // Displays the patient information
        int getId() const; // Gets the patient ID
        string getName() const; // Gets the patients name
        int getAge() const; // Gets the patients age
        string getStatus() const; // Gets the patients status
        void setName(string newName); // Sets the patients name
        string setStatus(string newStatus); // Set the patients status

        // Destructor
        virtual ~Patient();
};

#endif 