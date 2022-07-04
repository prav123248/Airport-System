#include <iostream>
#include "../Header Files/Plane.h"

using namespace std;

vector<Plane*> Plane::allPlanes;

Plane::Plane(string name,string seats) {

    this->name = name;

    this->planeSeats = PlaneSeat::loadSeatObjects(seats);

    if (allPlanes.size() == 0) {
        this->id = 1;
    }
    else {

        this->id = allPlanes.back()->id += 1;
    }

    allPlanes.push_back(this);



}

void Plane::addFlight(Flight* serveFlight) {
    flights.push_back(serveFlight);
}

int Plane::getId() {
    return this->id;
}

string Plane::getName() {
    return this->name;
}

vector<PlaneSeat*> Plane::getPlaneSeats() {
    return this->planeSeats;
}

void Plane::assignPlaneSeats(string seats) {

    string seat = "";
    seatType type = economy;
    for (auto i : seats) {
       
        if (i == ',') {
            bool exists = false;
            for (int k=0; k<this->planeSeats.size(); k++) {
                if (this->planeSeats[k]->getSeat() == seat and this->planeSeats[k]->getSeatType() == type) {
                    exists = true;
                    break;
                }
            }

            if (exists == false) {
                for (int k=0; k<PlaneSeat::allPlaneSeats.size(); k++) {
                    if (PlaneSeat::allPlaneSeats[k]->getSeat() == seat and PlaneSeat::allPlaneSeats[k]->getSeatType() == type) {
                        this->planeSeats.push_back(PlaneSeat::allPlaneSeats[k]);
                    }
                }
            }

            seat = "";
            type = economy;

        }
        else if (i == '*') {
            type = business;
        }
        else {
            seat += i;

        }
    }
     
}

 void Plane::removePlaneSeats(string seats) {

    string seat = "";
    seatType type = economy;
    for (auto i : seats) {
        if (i == ',') {
            for (int k=0; k<this->planeSeats.size(); k++) {
                if (this->planeSeats[k]->getSeat() == seat and this->planeSeats[k]->getSeatType() == type) {
                    this->planeSeats.erase(this->planeSeats.begin() + k);
                }
            }

            seat = "";
            type = economy;
        }
        else if (i == '*') {
            type = business;
        }
        else {
            seat += i;
        } 
    }

}