#include <iostream>
#include <string>
#include <vector>
#include "../Header Files/PlaneSeat.h"


vector<PlaneSeat> PlaneSeat::allPlaneSeats;

PlaneSeat::PlaneSeat(string seat, seatType seatClass) {
    this->seatValue = seat;
    
    this->type = seatClass;

}

bool PlaneSeat::seatCreator(string seat, seatType seatClass) {
    for (int i=0; i<allPlaneSeats.size(); i++) {
        if (seat == allPlaneSeats[i].getSeat() and seatClass == allPlaneSeats[i].getSeatType()) {
            return false;
        }
    }

    PlaneSeat newPlaneSeat(seat, seatClass);
    allPlaneSeats.push_back(newPlaneSeat);
    return true;
}

seatType PlaneSeat::getSeatType() {
    return this->type;
}

string PlaneSeat::getSeat() {
    return this->seatValue;
}
void PlaneSeat::setSeatType(bool economySeat) {
    if (economySeat) {
        this->type = economy;
    }
    else {
        this->type = business;
    }
}

void PlaneSeat::loadPlaneSeats(string seats, bool messageDisplay) {
    string seat;
    seatType seatClass = economy;
    for (auto i : seats) {
        if (i == ',') {
            bool seatExist = PlaneSeat::seatCreator(seat, seatClass);

            string seatStringType;
            if (seatClass == economy) {
                seatStringType = "economy";
            }
            else {
                seatStringType = "business";
            }

            if (seatExist == true and messageDisplay == true) {
                cout << seat + " in " + seatStringType + " class has been created." << endl;
            }
            else if (messageDisplay == true) {
                cout << seat + " in " + seatStringType + " already exists." << endl;
            }

            seat = "";
            seatClass = economy;

        }

        else if (i == '*') {
            seatClass = business;
        } 
        else {
            seat += i;
        }
            
    }
}

vector<PlaneSeat> PlaneSeat::loadSeatObjects(string seats) {

    vector<PlaneSeat> seatObjects;

    string seatBuffer;
    for (auto i : seats) {
        if (i == ',') {
    
            for (int i=0; i<allPlaneSeats.size(); i++) {
                if (seatBuffer == allPlaneSeats[i].getSeat()) {
                    seatObjects.push_back(allPlaneSeats[i]);
                    break;
                }
            }
        }
        else {
            seatBuffer += i;
        }
    }

    return seatObjects;
}