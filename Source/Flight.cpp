#include <iostream>
#include "../Header Files/Flight.h"
using namespace std;

vector<Flight*> Flight::allFlights;

Flight::Flight(string start, string end, Plane* servingPlane, string date) {
    this->start = start;
    this->end = end;
    this->date = date;

    vector<PlaneSeat*> planeSeat = servingPlane->getPlaneSeats();

    for (int i=0; i<planeSeat.size(); i++) {
        FlightSeat newFlightSeat(this, planeSeat[i]);
        this->seats.push_back(&newFlightSeat);
    }

    this->plane = servingPlane;
    allFlights.push_back(this);
};

void Flight::addBooking(Booking* book) {
    bookings.push_back(book);
};

string Flight::getStart() {
    return this->start;
}

string Flight::getEnd() {
    return this->end;
}

string Flight::getDate() {
    return this->date;
}

Plane* Flight::getPlane() {
    return this->plane;
}

void Flight::bookSeat(Passenger* booker) {

    cout << "Enter the desired seat:";
    string seatChoice;
    cin >> seatChoice;

    for (int i=0; i<this->seats.size(); i++) {
        cout << this->seats[i]->getSeat() << endl;

        if (this->seats[i]->getSeat()->getSeat() == seatChoice) {
            cout << "Hello";
        }
    }


    Booking newBooking(this, this->seats[0], booker);
}

FlightSeat* Flight::getSeat(string seatVal, seatType type) {
    
    cout << seatVal << endl;
    for (int i=0; i<this->seats.size(); i++) {
        cout << this->seats[i]->getSeat()->getSeat() << endl;
        if (this->seats[i]->getSeat()->getSeat() == seatVal and this->seats[i]->getSeat()->getSeatType() == type) {
            return this->seats[i];
        }
    }

    return this->seats[0];

}