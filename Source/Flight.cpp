#include <iostream>
#include "../Header Files/Flight.h"
using namespace std;

vector<Flight> Flight::allFlights;

Flight::Flight(string start, string end, Plane servingPlane, string date) {
    this->start = start;
    this->end = end;
    this->date = date;

    vector<PlaneSeat> planeSeat = servingPlane.getPlaneSeats();

    vector<FlightSeat> seatsArray;
    for (int i=0; i<planeSeat.size(); i++) {
        FlightSeat newFlightSeat(this, &planeSeat[i]);
        seatsArray.push_back(newFlightSeat);
    }

    this->seats = seatsArray;
    this->plane = &servingPlane;
    allFlights.push_back(*this);
};

void Flight::addBooking(Booking book) {
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

Plane Flight::getPlane() {
    return *this->plane;
}

void Flight::bookSeat(Passenger* booker) {
    for (int i=0; i<this->seats.size(); i++) {
        cout << i;
        cout << " : ";
        cout << this->seats[i].getSeat()->getSeat();

        if (this->seats[i].getSeat()->getSeatType() == economy) {
            cout << " - Economy";
        }
        else {
            cout << " - Business";
        }

    }

    cout << "Enter the number of the desired seat:";
    int seatChoice;
    cin >> seatChoice;

    Booking newBooking(this, & this->seats[seatChoice], booker);
}