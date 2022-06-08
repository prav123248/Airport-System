#include <iostream>
#include "../Header Files/Booking.h"
#include "../Header Files/Account.h"
using namespace std;

Booking::Booking(Flight* flight, FlightSeat* seat, Passenger* booker) {
    this->bookedFlight = flight;
    this->bookedSeat = seat;
    this->bookedPassenger = booker;
    cout << this->bookedPassenger->getName() + " booked a flight.";
}

string Booking::getPassenger() {
    return this->bookedPassenger->getName();
}

