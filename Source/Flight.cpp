#include <iostream>
#include "../Header Files/Flight.h"
using namespace std;


Flight::Flight(string start, string end, vector<FlightSeat> seats) {
    this->start = start;
    this->end = end;
    this->seats = seats;
};

void Flight::addBooking(Booking book) {
    bookings.push_back(book);
};

