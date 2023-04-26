#include "Humvee.h"
#include <stdexcept>

Humvee::Humvee(const std::string &name, int speed, int year, int capacity, int storage, int occupied_storage,  bool bulletproof,
               bool weaponized) : Vehicle(name, speed, year, capacity), storage(storage), occupied_storage(occupied_storage) , bulletproof(bulletproof),
                                  weaponized(weaponized) {}

Humvee::~Humvee() {

}

int Humvee::getStorage() const {
    return storage;
}

void Humvee::setStorage(int storage) {
    Humvee::storage = storage;
}

bool Humvee::isBulletproof() const {
    return bulletproof;
}

void Humvee::setBulletproof(bool bulletproof) {
    Humvee::bulletproof = bulletproof;
}

bool Humvee::isWeaponized() const {
    return weaponized;
}

void Humvee::setWeaponized(bool weaponized) {
    Humvee::weaponized = weaponized;
}

bool Humvee::operator==(const Humvee &rhs) const {
    return static_cast<const Vehicle &>(*this) == static_cast<const Vehicle &>(rhs) &&
           storage == rhs.storage &&
           bulletproof == rhs.bulletproof &&
           weaponized == rhs.weaponized;
}

bool Humvee::operator!=(const Humvee &rhs) const {
    return !(rhs == *this);
}

void Humvee::AddStorage(int s) {
    if(Humvee::occupied_storage + s > Humvee::storage){
        throw std::logic_error("Error, you cannot add that much storage");
    }
    Humvee::occupied_storage += s;
    /// EXCEPTIE
}

void Humvee::RemoveStorage(int s) {
    Humvee::occupied_storage -= s;
}

int Humvee::getOccupiedStorage() const {
    return occupied_storage;
}

void Humvee::setOccupiedStorage(int occupiedStorage) {
    occupied_storage = occupiedStorage;
}

int Humvee::raw_speed() const {
    return Humvee::getSpeed() - Humvee::occupied_storage * 2;
}
