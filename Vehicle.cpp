#include "Vehicle.h"

Vehicle::Vehicle(const std::string &name, int speed, int year, int capacity) : name(name), speed(speed), year(year),
                                                                          capacity(capacity) {}
Vehicle::Vehicle(){
    this->name = "";
    speed = 0;
    year = 0;
    capacity = 0;
}

Vehicle::~Vehicle() {

}

const std::string &Vehicle::getName() const {
    return name;
}

int Vehicle::getSpeed() const {
    return speed;
}

int Vehicle::getYear() const {
    return year;
}

int Vehicle::getCapacity() const {
    return capacity;
}

void Vehicle::setName(const std::string &new_name) {
    Vehicle::name = new_name;
}

void Vehicle::setSpeed(int new_speed) {
    Vehicle::speed = new_speed;
}

void Vehicle::setYear(int new_year) {
    Vehicle::year = new_year;
}

void Vehicle::setCapacity(int new_capacity) {
    Vehicle::capacity = new_capacity;
}

bool Vehicle::operator==(const Vehicle &rhs) const {
    return name == rhs.name &&
           speed == rhs.speed &&
           year == rhs.year &&
           capacity == rhs.capacity;
}

bool Vehicle::operator!=(const Vehicle &rhs) const {
    return !(rhs == *this);
}

std::ostream& operator << (std::ostream &os, const Vehicle &rhs){
    os << rhs.getName() << ", ";
    os << rhs.getCapacity() << " Capacitiy, ";
    os << rhs.getSpeed() << " Speed, ";
    os << "Year " << rhs.getYear();
    return os;
}

std::istream& operator >> (std::istream &is,Vehicle &rhs){
    is >> rhs.name >> rhs.speed >> rhs.year >> rhs.capacity;
    return is;
}