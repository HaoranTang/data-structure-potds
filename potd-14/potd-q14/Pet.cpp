// Pet.cpp
#include "Pet.h"
#include "Animal.h"
#include <string>
#include <iostream>
using namespace std;
string Pet::getName(){
    return name_;
}

void Pet::setName(string name){
    name_ = name;
}

string Pet::getOwnerName(){
    return owner_name_;
}

void Pet::setOwnerName(string owner_name){
    owner_name_ = owner_name;
}

string Pet::print(){
    return "My name is "+name_;
}

Pet::Pet():Animal("cat","fish"){
    name_ = "Fluffy";
    owner_name_ = "Cinda";
}
Pet::Pet(string type, string food, string name, string owner_name):Animal(type,food){
    name_ = name;
    owner_name_ = owner_name;
}
