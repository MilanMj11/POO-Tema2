#ifndef OOP_DEPOT_H
#define OOP_DEPOT_H

#include <vector>
#include "Vehicle.h"
#include <string>



class Depot {
private:
    std::vector <Vehicle> VList;
    std::string location;
public:
    Depot(const std::vector <Vehicle> &vList, const std::string &location);
    Depot();

    const std::vector <Vehicle> &getVList() const;
    void setVList(const std::vector <Vehicle> &vList);

    const std::string &getLocation() const;
    void setLocation(const std::string &location);

    void addVehicle(Vehicle& v);
    void removeVehicle(Vehicle& v);

    virtual ~Depot();
};


#endif //OOP_DEPOT_H
