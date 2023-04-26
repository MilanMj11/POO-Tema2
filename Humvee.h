#ifndef OOP_HUMVEE_H
#define OOP_HUMVEE_H

#include "Vehicle.h"

class Humvee : public Vehicle {
private:
    int storage;
    int occupied_storage;
    bool bulletproof;
    bool weaponized;
public:
    Humvee(const std::string &name, int speed, int year, int capacity, int storage, int occupied_storage, bool bulletproof, bool weaponized);

    ~Humvee() override;

    int getStorage() const;
    void setStorage(int storage);

    bool isBulletproof() const;
    void setBulletproof(bool bulletproof);

    bool isWeaponized() const;
    void setWeaponized(bool weaponized);

    bool operator==(const Humvee &rhs) const;
    bool operator!=(const Humvee &rhs) const;

    void AddStorage(int s);
    void RemoveStorage(int s);

};


#endif //OOP_HUMVEE_H
