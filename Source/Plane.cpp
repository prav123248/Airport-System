#include <iostream>
#include "../Header Files/Plane.h"

using namespace std;

Plane::Plane(vector<PlaneSeat> seats) {
    this->planeSeats = seats;
}

void Plane::addFlight(Flight serveFlight) {
    flights.push_back(serveFlight);
}

