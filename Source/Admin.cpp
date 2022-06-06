#include <string>
#include <iostream>
#include "../Header Files/Admin.h"
#include "../Header Files/PlaneSeat.h"
#include "../Header Files/Plane.h"

using namespace std;

Admin::Admin(string firstName, string secondName) : Account(firstName, secondName){}

string Admin::options() {

    int choice;

    while (true) {
        cout << "Enter the number beside desired choice." << endl;

        cout << "1. Create Plane Seats" << endl;
        cout << "2. Create Plane" << endl;
        cout << "3. Schedule Flight" << endl;
        cout << "4. Modify Plane" << endl;
        cout << "5. Logout" << endl;

        cin >> choice;

        if (choice == 1) {
            string seats;
            cout << "Enter the seat names (separated and conclude with commas, include * for business class seats):" << endl;
            cin >> seats;

            PlaneSeat::loadPlaneSeats(seats, true);



        }
        else if (choice == 2) {
            string planeName;
            string seats;
            cout << "Enter the plane name: "<< endl;
            cin >> planeName;

            cout << "Enter the seat names (separated and conclude with commas, include * for business class seats):" << endl;
            cin >> seats;

            Plane newPlane(planeName, seats); 
        
        
        }
        else if (choice == 3) {
            
            cout << "Enter the number beside the desired Plane:" << endl;
            cout << Plane::allPlanes.size() << endl;
            for (int i=1; i<=Plane::allPlanes.size(); i++) {
                cout << i;
                cout << ".";
                cout << Plane::allPlanes[i-1].getName() << endl;
            }

            cout << "Enter the number beside the desired Plane:" << endl;
            int chosenPlane;
            cin >> chosenPlane;
            
            cout << chosenPlane;

            if (chosenPlane >= 0 and chosenPlane <= Plane::allPlanes.size()) {
                string start;
                string end;
               
                cout << "Enter the Start location :" << endl;
                //getline(cin, start);
                cin >> start;

                cout << "Enter the End location :" << endl;
                cin >> end;               
               
                //getline(cin,end);

                cout << start + " is the departure location" << endl;
                cout << end + " is the destination." << endl;
                cout << Plane::allPlanes[chosenPlane-1].getName();
                cout << " is the plane.";
               
            }

            /*
            cout << "Enter the number beside the desired Plane:" << endl;
            string chosenPlane;
            getline(cin, chosenPlane);
            int chosenPlaneNum = stoi(chosenPlane);
            chosenPlaneNum -= 1;


            */
        
        }
        else if (choice == 4) {
        }
        else if (choice == 5) {
            break;
        }
        else {
            cout << "Please enter a valid value.";
        }


    }

    return "Successfully logged out";
}
