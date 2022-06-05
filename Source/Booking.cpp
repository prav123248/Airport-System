#include <iostream>
#include "../Header Files/Booking.h"
using namespace std;

Booking::Booking(Flight* flight, FlightSeat* seat) {
    this->bookedFlight = flight;
    this->bookedSeat = seat;
    cout << this->bookedPassenger->getName() + " booked a flight.";
}

string Booking::getPassenger() {
    return this->bookedPassenger->getName();
}

void Booking::assignPassenger(Passenger* person) {
    this->bookedPassenger = person;
    cout << this->bookedPassenger->getName() + "booked a flight.";
}