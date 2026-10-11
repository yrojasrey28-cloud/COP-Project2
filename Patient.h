/* Patient.h holds the declaration of base class for patient objects,
    with methods for managing patient information */
#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

class Patient { 
    protected: // Protected members can be accessed by derived classes
        int id; // Patient ID for the patient keep or delete?
        string name; 
        int age;
        string status;

    public:
        // Constructor
        Patient(int id, string name, int age, string status);

        // Set and Get Methods
        virtual void displayInfo() const;
        int getId() const;
        string getName() const; //
        int getAge() const; //
        string getStatus() const;
        void setName(string newName);
        string setStatus(string newStatus);

        // Destructor
        virtual ~Patient();
};

#endif 


