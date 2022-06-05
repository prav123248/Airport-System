#include <string>
#include <iostream>
#include "../Header Files/Admin.h"
#include "../Header Files/PlaneSeat.h"

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

        }
        else if (choice == 3) {

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
