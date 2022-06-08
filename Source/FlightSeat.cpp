#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/FlightSeat.h"
using namespace std;


FlightSeat::FlightSeat(Flight* forFlight, PlaneSeat* forSeat) {
    this->forFlight = forFlight;
    this->forSeat = forSeat;
}


void FlightSeat::assignBooking(Booking* forBooking) {
    this->forBooking = forBooking;
}

PlaneSeat* FlightSeat::getSeat() {
    return this->forSeat;
}
