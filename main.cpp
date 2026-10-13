#include <iostream>
#include <string>
#include "Patient.h"
#include "NumberInWaitingRoom.h"
#include <limits>

/*In main.cpp user can create and manipulate the waiting room using the methods from waiting_room and NumberInWaitingRoom*/

using namespace std;

int main()
{

    // Creates the waiting room with a max capacity of 10 patients
    NumberInWaitingRoom waitingRoom(10);

    int choice;
    cout << "Welcome to the Patient Management System!" << endl
         << endl;

    // Displays the menu until the user chooses to exit
    do
    {
        cout << endl;
        cout << "-------- MAIN MENU --------" << endl;
        cout << "1. Add new patient" << endl;
        cout << "2. Have patients treated or transferred" << endl;
        cout << "3. Display all patients" << endl;
        cout << "4. Exit" << endl;

        // Get user's menu selection (HAS TO BE A NUMBER that matches the menu list)
        cout << "Enter the number of your choice: ";
        while (!(cin >> choice)) // check if user type choice which is not an integer 
        { // check if user dont type integer
            cout << "Invalid choice. Please enter a number: ";
            cin.clear();                                         // reset the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // throw away the bad input
        }
        cout << endl;

        // Preforms the action based on the user choice
        switch (choice)
        {

        // Add patient based on urgency (front if urgent & back if we can wait)
        case 1:
        {

            char choiceP;
            int id, age;
            string name;
            string urgency;

            // Gets the patient details and user can add patients continuously as long as the user enters 'y' or 'Y'
            do
            {

                cout << endl;
                cout << "Enter patient ID: ";
                while (!(cin >> id))
                { // check if user dont type integer
                    cout << "Invalid ID. Please enter a number: ";
                    cin.clear();                                         // reset the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // throw away the bad input
                }

                // If the patient id is already in the system then a new patient cant be created
                if (waitingRoom.hasId(id))
                {
                    cout << "Error: a patient with ID " << id << " is already in the waiting room." << endl;
                    choiceP = 'y';
                    continue;
                }

                cout << "Enter patient name: ";
                getline(cin >> ws, name);

                cout << "Enter patient age: ";
                while (!(cin >> age))
                { // check if user dont type integer
                    cout << "Invalid ID. Please enter a number: ";
                    cin.clear();                                         // reset the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // throw away the bad input
                }

                cout << "Does this patient need to be admitted immediately? (urgent/non-urgent): ";
                cin >> urgency;

                // Makes sure that the correct urgency value is entered by user
                if (urgency != "urgent" && urgency != "non-urgent")
                {
                    cout << "Invalid urgency choice. Patient is not added.";
                    break;
                }

                // creates patient
                Patient p(id, name, age, urgency);

                // Patient is added to front of waiting room if the staus is urgent
                if (urgency == "urgent")
                {
                    waitingRoom.addFront(p);
                }

                // Patient is added to back of waiting room if the status is not urgent
                if (urgency == "non-urgent")
                {
                    waitingRoom.addBack(p);
                }

                cout << endl;
                // Asks user if they want to admit another patient
                cout << "Are there more patients to be admitted? (y/n): ";
                cin >> choiceP;

                // Validates the user's choice
                if (choiceP != 'y' && choiceP != 'Y' && choiceP != 'n' && choiceP != 'N')
                {
                    cout << "Invalid choice. No more patients are added" << endl;

                    break;
                }

            } while (choiceP == 'y' || choiceP == 'Y');

            cout << endl;

            // Checks if the waiting room exceeds its max capacity and removes the last patient if required
            waitingRoom.checkAndRemoveIfOverCapacity();

            // Displays the capacity of waiting room
            waitingRoom.checkCapacity();

            cout << endl;

            break;
        }

        // Remove patient by treating them (front) or transferring them (back)
        case 2:
        {
            int remove;

            cout << endl;
            cout << "1. Treat patient in the front of the line" << endl;
            cout << "2. Transfer patient at end of the line" << endl;
            cout << "Enter the number of your action: ";
            cin >> remove;

            // Checks that the user selected the valid choices available
            if (remove != 1 && remove != 2)
            {
                cout << "Invalid choice. No patients have been removed" << endl
                     << endl;
                break;
            }

            // Treat the patient at front of waiting room and removes them
            if (remove == 1)
            {
                if (!waitingRoom.removeFront())
                {
                    cout << "Waiting room is empty" << endl;
                }
            }

            // Transfer the patient at the back of waiting room  and removes them
            if (remove == 2)
            {
                if (!waitingRoom.removeBack())
                {
                    cout << "Waiting room is empty" << endl;
                }
            }

            cout << endl;

            break;
        }

        // Display the patients in waiting room
        case 3:
        {
            cout << "Patients in Waiting Room: " << endl;
            waitingRoom.displayAll();
            cout << endl;
            break;
        }

        // Exiting
        case 4:
        {
            cout << "Exiting Patient Waiting Room." << endl;
            break;
        }

        // If user enters a value that its not part of the menu this will handle those situations
        default:
        {
            cout << "Invalid choice. Please try again" << endl;
        }
        }
    } while (choice != 4);

    return 0;
}
