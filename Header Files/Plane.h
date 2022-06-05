#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/PlaneSeat.h"
#include "../Header Files/Flight.h"

using namespace std;



class Plane {

    private:
        int id;
        string name;
        vector<Flight> flights;
        vector<PlaneSeat> planeSeats;

    public:
        Plane(string name,string seats);
        void addFlight(Flight serveFlight);
        static vector<Plane> allPlanes;
        int getId();
        string getName();

};
