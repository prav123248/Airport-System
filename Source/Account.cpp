#include <iostream>
#include "../Header Files/Account.h"

Account::Account(string firstName, string secondName) {
    this->firstName = firstName;
    this->secondName = secondName;
}

int Account::getId() {
    return this->id;
}

string Account::getName() {
    return this->firstName + " " + this->secondName;
}

string Account::options() {
    return "An Account was created.";
}

