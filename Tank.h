#ifndef OOP_TANK_H
#define OOP_TANK_H

#include "Vehicle.h"

class Tank : public Vehicle {
private:
    int ammunition;
    int armor; /// max 100%
public:
    Tank(const std::string &name, int speed, int year, int capacity, int ammunition, int armor);

    ~Tank() override;

    int getAmmunition() const;
    void setAmmunition(int ammunition);

    int getArmor() const;
    void setArmor(int armor);

    void Shoot();
    void Repair(int procentage);

};


#endif //OOP_TANK_H
