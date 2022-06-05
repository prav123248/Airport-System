#include <iostream>
#include "../Header Files/Plane.h"

using namespace std;

vector<Plane> Plane::allPlanes;

Plane::Plane(string name,string seats) {
    this->name = name;
    this->planeSeats = PlaneSeat::loadSeatObjects(seats);


    if (allPlanes.size() == 0) {
        this->id = 1;
    }
    else {
        this->id = allPlanes.back().id += 1;
    }

    allPlanes.push_back(*this);

}

void Plane::addFlight(Flight serveFlight) {
    flights.push_back(serveFlight);
}

int Plane::getId() {
    return this->id;
}

string Plane::getName() {
    return this->name;
}
