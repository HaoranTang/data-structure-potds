// Pet.h
#pragma once
#include <string>
#include "Animal.h"
using namespace std;
class Pet : public Animal {
public:
    string getName();
    void setName(string name);
    string getOwnerName();
    void setOwnerName(string owner_name);
    string print();
    Pet();
    Pet(string type, string food, string name, string owner_name);
private:
    string name_;
    string owner_name_;
};
