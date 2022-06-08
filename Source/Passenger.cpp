#include <string>
#include <iostream>
#include "../Header Files/Account.h"
#include "../Header Files/Passenger.h"
#include "../Header Files/Booking.h"

using namespace std;

Passenger::Passenger(string firstName, string secondName, string password) : Account(firstName, secondName, password){
}


void Passenger::book(Booking book) {
    this->bookings.push_back(&book);

}

string Passenger::options() {
    return "A Passenger was created.";
}
