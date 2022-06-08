#pragma once
#include <iostream>
#include <string>

using namespace std;

class Account {

    private:
        static int nextId;
        int id;
        string firstName;
        string secondName;
        string password;
    public:
        Account(string firstName, string secondName, string password);
        int getId();
        string getName();
        string options();
        string getPassword();
        static int login(int identifier, string password);
        static vector<Account> allAccounts;

};


