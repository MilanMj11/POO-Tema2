#ifndef OOP_VEHICLE_H
#define OOP_VEHICLE_H

#include <iostream>
#include <string>

class Vehicle {
private:
    std::string name;
    int speed;
    int year;
    int capacity; /// no. people
public:
    Vehicle();
    Vehicle(const std::string &name, int speed, int year, int capacity);

    virtual ~Vehicle();

    const std::string &getName() const;
    int getSpeed() const;
    int getYear() const;
    int getCapacity() const;

    void setName(const std::string &name);
    void setSpeed(int speed);
    void setYear(int year);
    void setCapacity(int capacity);

    bool operator==(const Vehicle &rhs) const;
    bool operator!=(const Vehicle &rhs) const;

    friend std::ostream& operator << (std::ostream &os, const Vehicle &rhs);
};


#endif //OOP_VEHICLE_H
