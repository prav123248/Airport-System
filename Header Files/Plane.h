#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/Flight.h"
#include "../Header Files/PlaneSeat.h"

using namespace std;

class Plane {

    private:
        int id;
        vector<Flight> flights;
        vector<PlaneSeat> planeSeats;

    public:
        Plane(vector<PlaneSeat> seats);
        void addFlight(Flight serveFlight);
};
