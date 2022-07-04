#pragma once
#include <iostream>
#include <vector>
#include <string>

class Passenger;

using namespace std;

class Account {
    private:
        static int nextId;
        int id;
        string firstName;
        string secondName;
        string password;
    public:
        Account(string firstName, string secondName, string password, bool defaultAcc=false);
        int getId();
        string getName();
        string options();
        string getPassword();
        void bookFlight(Passenger* booker);
        static int login(int identifier, string password);
        static vector<Account*> allAccounts;

};


