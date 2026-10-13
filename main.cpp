#include <iostream>
#include <string>
#include "Patient.h"
#include "NumberInWaitingRoom.h"

using namespace std;

int main() {

    NumberInWaitingRoom waitingRoom(10);

    int choice;
    cout << "Welcome to the Patient Management System!" << endl <<endl;

    do{
        cout <<endl;
        cout<< "-------- MAIN MENU --------" << endl;
        cout<< "1. Add new patient"<< endl;
        cout<< "2. Have patients treated or transferred" << endl;
        cout<< "3. Display all patients" << endl;
        cout<< "4. Exit" << endl;

        cout<< "Enter the number of your choice: ";
        cin >> choice;
        cout << endl;

        switch(choice){


            //Add patient based on urgency (front if urgent & back if we can wait)
            case 1:{
                
                char choiceP;
                int id, age;
                string name;
                char urgency;

                do{
                    cout << endl;
                    cout<<"Enter patient ID: ";
                    cin >> id;

                    cout<< "Enter patient name: ";
                    getline(cin>> ws, name);

                    cout<< "Enter patient age: ";
                    cin>>age;

                    cout<< "Does this patient need to be admitted immediately? (y/n): ";
                    cin>> urgency;

                    if(urgency != 'y' && urgency != 'Y' && urgency != 'n' && urgency != 'N'){
                        cout << "Invalid urgency choice. Patient is not added.";

                        break;
                    }


                    Patient p(id, name, age, "Waiting");


                    if (urgency == 'y' || urgency == 'Y'){
                        waitingRoom.addFront(p);
                    }

                    if (urgency == 'n' || urgency == 'N'){
                        waitingRoom.addBack(p);
                    }

                    cout << endl;
                    cout<<"Are there more patients to be admitted? (y/n): ";
                    cin>> choiceP;

                    if(choiceP != 'y' && choiceP != 'Y' && choiceP != 'n' && choiceP != 'N'){
                        cout << "Invalid choice. No more patients are added" << endl;

                        break;
                    }
                    
                } while(choiceP == 'y' || choiceP == 'Y');


                cout << endl;

                waitingRoom.checkAndRemoveIfOverCapacity();

                waitingRoom.checkCapacity();

                cout << endl;

                break;
            }

            //Remove patient by treating them (front) or transferring them (back)
            case 2: {
                int remove;

                cout<< endl;
                cout << "1. Treat patient in the front of the line" << endl;
                cout << "2. Transfer patient at end of the line" << endl;
                cout <<"Enter the number of your action: ";
                cin >> remove;

                if (remove != 1 && remove != 2){
                    cout << "Invalid choice. No patients have been removed"<< endl << endl;
                    break;
                }

                if(remove == 1){
                    if(!waitingRoom.removeFront()){
                        cout<< "Waiting room is empty" << endl;
                    }
                }

                if(remove == 2){
                    if(!waitingRoom.removeBack()){
                        cout<< "Waiting room is empty" << endl;
                    }
                }

                cout <<endl;

                break;
            }

            //Display the patients in waiting room
            case 3: {
                cout<< "Patients in Waiting Room: " << endl;
                waitingRoom.displayAll();
                cout <<endl;
                break;
            }

            //Exiting
            case 4: {
                cout << "Exiting Patient Waiting Room." << endl;
                break;
            }

            default: {
                cout << "Invalid choice. Please try again" << endl;
            }
        }
    }while(choice != 4);

    return 0;
}