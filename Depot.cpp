//
// Created by Milan on 4/26/2023.
//

#include "Depot.h"

Depot::Depot(const std::vector <Vehicle> &vList, const std::string &location) : VList(vList), location(location) {}
Depot::Depot(){}

Depot::~Depot() {

}

const std::vector <Vehicle> &Depot::getVList() const {
    return VList;
}

void Depot::setVList(const std::vector <Vehicle> &vList) {
    VList = vList;
}

const std::string &Depot::getLocation() const {
    return location;
}

void Depot::setLocation(const std::string &new_location) {
    Depot::location = new_location;
}

void Depot::addVehicle(Vehicle& v){
    this->VList.push_back(v);
}

void Depot::removeVehicle(Vehicle& v){
    for(int i=0;i<this->VList.size();i++){
        if(this->VList[i] == v){
            this->VList.erase(this->VList.begin() + i);
            break;
        }
    }
}