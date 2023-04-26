#ifndef OOP_TANK_H
#define OOP_TANK_H

#include "Vehicle.h"

class Tank : public Vehicle {
private:
    int ammunition;
    int armor; /// max 100%
    int power;
public:
    Tank(const std::string &name, int speed, int year, int capacity, int ammunition, int armor,int power);

    ~Tank() override;

    int getAmmunition() const;
    void setAmmunition(int ammunition);

    int getArmor() const;
    void setArmor(int armor);

    int getPower() const;
    void setPower(int power);

    bool operator==(const Tank &rhs) const;
    bool operator!=(const Tank &rhs) const;

    void Shoot();
    void Repair(int procentage);
    void Damage(int procentage);
};


#endif //OOP_TANK_H
