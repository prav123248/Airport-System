#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


enum seatType {economy, business};

class PlaneSeat {

    private:
        PlaneSeat(string seat, seatType seatClass);
        
        seatType type;

    public:
        seatType getSeatType();
        void setSeatType(bool economySeat);
        static bool seatCreator(string seat, seatType seatClass);
        static void loadPlaneSeats(string seats, bool messageDisplay);
        static vector<PlaneSeat> loadSeatObjects(string seats, vector<PlaneSeat> seatArray);
        string getSeat();
        static vector<PlaneSeat> allPlaneSeats;
        string seatValue;
        
        

};
