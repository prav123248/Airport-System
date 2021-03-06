#include <iostream>
#include <string>
#include <fstream>
#include "../Header Files/Account.h"
#include "../Header Files/Admin.h"
#include "../Header Files/Passenger.h"
#include "../Header Files/Booking.h"
#include "../Header Files/Plane.h"
using namespace std;

void loadFile() {

    //Generate Plane Seats
    string planeseats = "A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B1*,B2*,B3*,B4*,B5*,B6*,B7*,B8*,B9*,B10*,B11*,B12*,B13*,B14*,C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11*,C12*,C13*,C14*,A1*,A2*,A3*,A4*,A5*,A6*,A7*,A8*,A9*,A10*,A11*,A12*,A13*,A14*,C1*,C2*,C3*,C4*,C5*,C6*,C7*,C8*,C9*,C10*,D1,D2,D3,D4,D5,D6,D7,D8,D9,D10,D11,D12,D13,D14,";
    PlaneSeat::loadPlaneSeats(planeseats,false);

    //Generate Planes

    Plane Sparrow("Sparrow", "A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B1*,B2*,B3*,B4*,B5*,B6*,B7*,B8*,B9*,B10*,B11*,B12*,B13*,B14*,C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11*,C12*,C13*,C14*,");
    Plane Hawk("Hawk", "A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,B1*,B2*,B3*,B4*,B5*,B6*,B7*,B8*,B9*,B10*,B11*,B12*,B13*,B14*,C1,C2,C3,C4,C5,C6,C7,C8,C9,C10,C11*,C12*,C13*,C14*,");
    Plane Eagle("Eagle","A1*,A2*,A3*,A4*,A5*,A6*,A7*,A8*,A9*,A10*,A11*,A12*,A13*,A14*,B1*,B2*,B3*,B4*,B5*,B6*,B7*,B8*,B9*,B10*,B11*,B12*,B13*,B14*,C1*,C2*,C3*,C4*,C5*,C6*,C7*,C8*,C9*,C10*,C11*,C12*,C13*,C14*,D1,D2,D3,D4,D5,D6,D7,D8,D9,D10,D11,D12,D13,D14,");


    //Generate Flights
    Flight flight1("UK", "Spain", &Sparrow, "18/09/2001");
    Flight flight2("UK", "Germany", &Hawk, "15/03/2003");
    Flight flight3("UK", "Sri Lanka", &Eagle, "29/12/2002");
    Flight flight4("Japan", "France", &Eagle, "03/01/2000");
    Flight flight5("Norway", "Egypt", &Eagle, "22/04/2001");

    //Generate Passengers
    Passenger pass1("Kazuo", "Nakamura", "pass");
    Passenger pass2("Kira", "Chrollo", "pass");
    Passenger pass3("Atlas", "Okita", "pass");
    Passenger pass4("Amani", "Ishigami", "pass");
    Passenger pass5("Hisoka", "Miyaisui", "pass");
    Passenger pass6("Ajoin", "Yasumoto", "pass");

    //Generate Bookings
    //FlightSeat seat1 = flight1.getSeat("A3", economy);
    //FlightSeat seat2 = flight2.getSeat("B1", business);
    //FlightSeat seat3 = flight2.getSeat("B2", business);
    //FlightSeat seat4 = flight5.getSeat("D1", economy);

    //Booking book1(&flight1, &seat1, &pass1);
    //Booking book2(&flight2, &seat2, &pass1);
    //Booking book3(&flight2, &seat3, &pass1);
    //Booking book4(&flight5, &seat4, &pass1);
        
    

    return;
}


int main() {  
    
    loadFile();

    Account acc("default", "account", "pass", true);
    acc.options();



    //Admin adminAcc("The","Doctor", "sht");

    //cout << adminAcc.options();
    cout << PlaneSeat::allPlaneSeats[0]->seatValue;
    return 0;
}





