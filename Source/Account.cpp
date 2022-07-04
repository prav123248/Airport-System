#include <iostream>
#include <vector>
#include "../Header Files/Account.h"
#include "../Header Files/Passenger.h"
#include "../Header Files/Admin.h"
#include "../Header Files/Flight.h"

int Account::nextId = 0;
vector<Account*> Account::allAccounts;


Account::Account(string firstName, string secondName, string password, bool defaultAcc) {
    this->firstName = firstName;
    this->secondName = secondName;
    this->password = password;

    this->id = nextId;
    nextId += 1;
    
    Account::allAccounts.push_back(this);

    if (defaultAcc == false) {
        cout << "Your ID is ";
        cout << this->id << endl;

        cout << "Your Password is ";
        cout << this->password << endl;
    }

}

int Account::getId() {
    return this->id;
}

string Account::getName() {
    return this->firstName + " " + this->secondName;
}

string Account::options() {

    while (true) {
        cout << "Enter the number beside desired choice." << endl;

        cout << "1. Login" << endl;
        cout << "2. Create Booking" << endl;
            
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter ID : " << endl;
            int identifier;
            cin >> identifier;

            cout <<"Enter password :" << endl;
            string pass;
            cin >> pass;

            int loginVal = Account::login(identifier, pass);

            if (loginVal == -1) {
                cout << "Incorrect login details" << endl;
            }
            else {
                Account::allAccounts[loginVal]->options();
            }
        }
        else if (choice == 2) {
            this->bookFlight(nullptr);
        }
    }

    return "";
}

void Account::bookFlight(Passenger* booker) {

    cout << "Enter the ID of the flight you wish to book" << endl;
    for (int i=0; i<Flight::allFlights.size(); i++) {
        cout << i;
        cout << " : From ";
        cout << Flight::allFlights[i]->getStart();
        cout << " to ";
        cout << Flight::allFlights[i]->getEnd();
        cout << " on ";
        cout << Flight::allFlights[i]->getDate() << endl;
    }

    



    int flightChoice;
    cin >> flightChoice;

    if (booker == NULL) {
        string fname;
        string sname;
        string pass;
        
        cout << "Enter your First name :" << endl;
        cin >> fname;

        cout << "Enter your Second name :" << endl;
        cin >> sname;

        cout << "Enter a password :" << endl;
        cin >> pass;

        Passenger newPassenger(fname, sname, pass);
                    
        Flight::allFlights[flightChoice]->bookSeat(&newPassenger);
    }
    else {
        Flight::allFlights[flightChoice]->bookSeat(booker);
    }
}


string Account::getPassword() {
    return this->password;
}

int Account::login(int identifier, string password) {

    for (int i=0; i<allAccounts.size(); i++) {
        if (allAccounts[i]->getId() == identifier and allAccounts[i]->getPassword() == password) {
            return i;
        }
    }

    return -1;
}