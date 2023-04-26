#include "Tank.h"

Tank::Tank(const std::string &name, int speed, int year, int capacity, int ammunition, int armor) : Vehicle(name, speed, year, capacity),
                                                                                                    ammunition(ammunition),
                                                                                                    armor(armor) {}

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
    Tank::ammunition--;
}

void Tank::Repair(int procentage){
    Tank::armor = std::max ( Tank::armor + procentage , 100 );
}