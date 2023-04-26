#include "Humvee.h"

Humvee::Humvee(const std::string &name, int speed, int year, int capacity, int storage, bool bulletproof,
               bool weaponized) : Vehicle(name, speed, year, capacity), storage(storage), bulletproof(bulletproof),
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
    Humvee::storage += s;
}

void Humvee::RemoveStorage(int s) {
    Humvee::storage -= s;
}