#ifndef OOP_VEHICLE_H
#define OOP_VEHICLE_H

#include <string>

using namespace std;

class Vehicle {
private:
    string name;
    int speed;
    int year;
    int capacity; /// no. people
public:
    Vehicle();
    Vehicle(const string &name, int speed, int year, int capacity);

    virtual ~Vehicle();

    const string &getName() const;
    int getSpeed() const;
    int getYear() const;
    int getCapacity() const;

    void setName(const string &name);
    void setSpeed(int speed);
    void setYear(int year);
    void setCapacity(int capacity);

    bool operator==(const Vehicle &rhs) const;
    bool operator!=(const Vehicle &rhs) const;

    friend ostream& operator << (ostream &os, const Vehicle &rhs);
};


#endif //OOP_VEHICLE_H
