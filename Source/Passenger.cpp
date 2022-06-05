#include <string>
#include <iostream>
#include "../Header Files/Passenger.h"
#include "../Header Files/Booking.h"

using namespace std;

Passenger::Passenger(string firstName, string secondName, Booking* book) : Account(firstName, secondName){
    this->bookings.push_back(book);
}


void Passenger::book(Booking book) {
    book.assignPassenger(this);
    this->bookings.push_back(&book);

}

string Passenger::options() {
    return "A Passenger was created.";
}
