#include "Tank.h"

Tank::Tank(const std::string &name, int speed, int year, int capacity, int ammunition, int armor,int power) : Vehicle(name, speed, year, capacity),
                                                                                                    ammunition(ammunition),
                                                                                                    armor(armor),
                                                                                                    power(power){}

Tank::~Tank() {

}

int Tank::getAmmunition() const {
    return ammunition;
}

void Tank::setAmmunition(int ammunition) {
    Tank::ammunition = ammunition;
}

int Tank::getArmor() const {
    return armor;
}

void Tank::setArmor(int armor) {
    Tank::armor = armor;
}

void Tank::Shoot(){
    if(Tank::ammunition == 0){
        throw std::logic_error("Error, you cannot shoot, you have no more ammunition");
    }
    Tank::ammunition--;
}

void Tank::Repair(int procentage){
    Tank::armor = std::max ( Tank::armor + procentage , 100 );
}

void Tank::Damage(int procentage){
    Tank::armor = std::max ( 0, Tank::armor - procentage );
}

int Tank::getPower() const {
    return power;
}

void Tank::setPower(int power) {
    Tank::power = power;
}

bool Tank::operator==(const Tank &rhs) const {
    return static_cast<const Vehicle &>(*this) == static_cast<const Vehicle &>(rhs) &&
           ammunition == rhs.ammunition &&
           armor == rhs.armor &&
           power == rhs.power;
}

bool Tank::operator!=(const Tank &rhs) const {
    return !(rhs == *this);
}

int Tank::raw_speed() const {
    return Tank::getSpeed() - Tank::armor * 5;
}