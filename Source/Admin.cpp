#include <string>
#include <iostream>
#include "../Header Files/Account.h"
#include "../Header Files/Admin.h"
#include "../Header Files/PlaneSeat.h"
#include "../Header Files/Plane.h"

using namespace std;

Admin::Admin(string firstName, string secondName, string password) : Account(firstName, secondName, password){}

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
        cin.ignore(10000, '\n');
        if (choice == 1) {
            string seats;
            cout << "Enter the seat names (separated and conclude with commas, include * for business class seats):" << endl;
            cin >> seats;
            cin.ignore(10000, '\n');
            PlaneSeat::loadPlaneSeats(seats, true);



        }
        else if (choice == 2) {
            string planeName;
            string seats;
            cout << "Enter the plane name: "<< endl;
            cin >> planeName;
            cin.ignore(10000, '\n');
            cout << "Enter the seat names (separated and conclude with commas, include * for business class seats):" << endl;
            cin >> seats;
            cin.ignore(10000, '\n');
            Plane newPlane(planeName, seats); 
        
        
        }
        else if (choice == 3) {
            
            cout << "Enter the number beside the desired Plane:" << endl;
            
            for (int i=1; i<=Plane::allPlanes.size(); i++) {
                cout << i;
                cout << ".";
                cout << Plane::allPlanes[i-1]->getName() << endl;
            }

            cout << "Enter the number beside the desired Plane:" << endl;
            int chosenPlane;
            cin >> chosenPlane;
            chosenPlane -= 1;
            cin.ignore(10000, '\n');
            cin.clear();

            if (chosenPlane >= 0 and chosenPlane <= Plane::allPlanes.size()) {
                string start;
                string end;
                string date;

                cout << "Enter the Start location :" << endl;
                getline(cin, start);
                cout << "Enter the End location :" << endl;
                getline(cin,end);            
                
                cout << "Enter the Date of the Flight :" << endl;
                getline(cin, date);

                cout << start + " is the departure location" << endl;
                cout << end + " is the destination." << endl;
                cout << Plane::allPlanes[chosenPlane]->getName();
                cout << " is the plane." << endl;
               
                Flight newFlight(start, end, Plane::allPlanes[chosenPlane], date);
            }

            for (int i=0; i<Flight::allFlights.size(); i++) {
                cout << "From " << Flight::allFlights[i]->getStart() << " to " << Flight::allFlights[i]->getEnd() << " on "  << Flight::allFlights[i]->getDate() << " using Plane " << Flight::allFlights[i]->getPlane()->getName() << endl;
            }
        
        }
        else if (choice == 4) {
            cout << "Enter the number beside the desired plane." << endl;

            for (int i=1; i<=Plane::allPlanes.size(); i++) {
                cout << i;
                cout << ".";
                cout << Plane::allPlanes[i-1]->getName() << endl;
            }

            int planeChoice;
            cin >> planeChoice;
            planeChoice -= 1;

            cout << Plane::allPlanes[planeChoice]->getPlaneSeats().size();
            for (int k=0; k<Plane::allPlanes[planeChoice]->getPlaneSeats().size(); k++) {
                cout << "Seat ";
                cout << Plane::allPlanes[planeChoice]->getPlaneSeats()[k]->getSeat() << endl;
            }

            cout << "Enter the number beside desired choice." << endl;
            cout << "1. Add Planeseats" << endl;
            cout << "2. Remove Planeseats" << endl;

            int option;
            cin >> option;

            if (option == 1) {
                cout << "Enter the new seats to add (commas between each option and a * for business class :" << endl;
                string seats;
                cin >> seats;

                PlaneSeat::loadPlaneSeats(seats, true);
                Plane::allPlanes[planeChoice]->assignPlaneSeats(seats);
            }
            else if (option == 2) {
                cout << "Enter the seats to remove (commas between each option and a * for business class :" << endl;
                string seats;
                cin >> seats;

                Plane::allPlanes[planeChoice]->removePlaneSeats(seats);
            }

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
