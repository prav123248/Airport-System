#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/Passenger.h"
#include "../Header Files/FlightSeat.h"


using namespace std;

class Flight;

class Booking {

    private:
        int id;
        Passenger* bookedPassenger;
        Flight* bookedFlight;
        FlightSeat* bookedSeat;

    public:
        Booking(Flight* flight, FlightSeat* seat);
        string getPassenger();
        void assignPassenger(Passenger* person);
};
