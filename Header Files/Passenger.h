#pragma once
#include "../Header Files/Account.h"
#include <iostream>
#include <string>
#include <vector>

class Booking;


using namespace std;

class Passenger : public Account{
    vector <Booking*> bookings;
    
    public:
        Passenger(string firstName, string secondName, string password);
        void book(Booking book);
        string options();
        

};
