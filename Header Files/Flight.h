#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/FlightSeat.h"
#include "../Header Files/Booking.h"
#include "../Header Files/Plane.h"
using namespace std;

class Plane;

class Flight {

    private:
        int id;
        Plane* plane;
        vector<Booking*> bookings;
        vector<FlightSeat*> seats;
        string start;
        string end;
        string date;

    public:
        Flight(string start, string end,Plane* servedPlane, string date);
        void addBooking(Booking* book);
        static vector<Flight*> allFlights;
        string getStart();
        string getEnd();
        string getDate();
        FlightSeat* getSeat(string seatVal, seatType type);
        Plane* getPlane();
        void bookSeat(Passenger* booker);
};
