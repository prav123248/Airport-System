#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


enum seatType {economy, business};

class PlaneSeat {

    private:
        PlaneSeat(string seat, seatType seatClass);
        string seatValue;
        static vector<PlaneSeat> allPlaneSeats;
        seatType type;

    public:
        seatType getSeatType();
        void setSeatType(bool economySeat);
        static bool seatCreator(string seat, seatType seatClass);
        static void loadPlaneSeats(string seats, bool messageDisplay);
        static vector<PlaneSeat> loadSeatObjects(string seats);
        string getSeat();
        

};
