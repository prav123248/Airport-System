#include <iostream>
#include "../Header Files/Flight.h"
using namespace std;


Flight::Flight(string start, string end, vector<FlightSeat> seats, Plane servingPlane) {
    this->start = start;
    this->end = end;
    this->seats = seats;
    this->plane = &servingPlane;
};

void Flight::addBooking(Booking book) {
    bookings.push_back(book);
};

