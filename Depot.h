#ifndef OOP_DEPOT_H
#define OOP_DEPOT_H

#include <vector>
#include "Vehicle.h"
#include <string>
#include <memory>

class Depot {
    static std::vector<std::shared_ptr<Vehicle>> VList;
private:
    Depot();
    std::string location;
public:
    Depot(const std::vector <Vehicle> &vList, const std::string &location);

    const std::vector <Vehicle> &getVList() const;
    void setVList(const std::vector <Vehicle> &vList);

    const std::string &getLocation() const;
    void setLocation(const std::string &location);

    static void addVehicle(std::shared_ptr<Vehicle>);

    virtual ~Depot();
};


#endif //OOP_DEPOT_H
