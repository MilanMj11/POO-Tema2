#ifndef OOP_DEPOT_H
#define OOP_DEPOT_H

#include <vector>
#include "Vehicle.h"
#include <string>
#include <memory>

class Depot {
    static std::vector<std::shared_ptr<Vehicle>> VList;
    static int capacity;
private:
    std::string location;
public:
    Depot(const std::vector <Vehicle> &vList, const std::string &location);
    Depot();

    const std::string &getLocation() const;
    void setLocation(const std::string &location);

    void setCapacity(const int new_cap);
    int getCapacity();

    static const std::vector<std::shared_ptr<Vehicle>> &getVList();

    static void addVehicle(std::shared_ptr<Vehicle>);

    virtual ~Depot();
};


#endif //OOP_DEPOT_H
