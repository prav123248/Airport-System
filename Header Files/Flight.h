#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/FlightSeat.h"
#include "../Header Files/Booking.h"

using namespace std;


class Plane;

class Flight {

    private:
        int id;
        Plane* plane;
        vector<Booking> bookings;
        vector<FlightSeat> seats;
        string start;
        string end;
        string date;

    public:
        Flight(string start, string end, vector<FlightSeat> seats);
        void addBooking(Booking book);
};
