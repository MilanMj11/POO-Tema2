#ifndef OOP_TANK_H
#define OOP_TANK_H

#include "Vehicle.h"

class Tank : public Vehicle {
private:
    int ammunition;
    int armor;
public:
    Tank(const std::string &name, int speed, int year, int capacity, int ammunition, int armor);
};


#endif //OOP_TANK_H
