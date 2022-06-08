#pragma once
#include "Account.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Admin : public Account{
    
    public:
        Admin(string firstName, string secondName, string password);
        string options();
        

};
