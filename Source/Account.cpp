#include <iostream>
#include <vector>
#include "../Header Files/Account.h"

int Account::nextId = 0;
vector<Account> allAccounts;


Account::Account(string firstName, string secondName, string password) {
    this->firstName = firstName;
    this->secondName = secondName;
    this->password = password;

    this->id = nextId;
    nextId += 1;
    
    this->allAccounts.push_back(*this);

    cout << "Your ID is ";
    cout << this->id << endl;

    cout << "Your Password is ";
    cout << this->password << endl;


}

int Account::getId() {
    return this->id;
}

string Account::getName() {
    return this->firstName + " " + this->secondName;
}

string Account::options() {

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


    }


    return "An Account was created.";
}

string Account::getPassword() {
    return this->password;
}

int Account::login(int identifier, string password) {

    for (int i=0; i<allAccounts.size(); i++) {
        if (allAccounts[i].getId() == identifier and allAccounts[i].getPassword() == password) {
            return i;
        }
    }

    return -1;
}