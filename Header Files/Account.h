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
        Account(string firstName, string secondName);
        int getId();
        string getName();
        string options();

};


