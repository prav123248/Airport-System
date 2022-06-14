#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/PlaneSeat.h"



using namespace std;

class Booking;
class Flight;

class FlightSeat {

    private:
        Flight* forFlight;
        Booking* forBooking;
        PlaneSeat* forSeat;

    public:
        FlightSeat(Flight* forFlight, PlaneSeat* forSeat);
        void assignBooking(Booking* forBooking);
        PlaneSeat* getSeat();
        string getSeatString();
};
