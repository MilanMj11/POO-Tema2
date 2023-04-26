#ifndef OOP_DEPOT_H
#define OOP_DEPOT_H

#include <vector>
#include "Vehicle.h"
#include <string>


class Depot {
private:
    vector <Vehicle> VList;
    std::string location;
public:
    Depot(const vector <Vehicle> &vList, const std::string &location);

    const vector <Vehicle> &getVList() const;

    void setVList(const vector <Vehicle> &vList);

    const std::string &getLocation() const;

    void setLocation(const std::string &location);

    virtual ~Depot();
};


#endif //OOP_DEPOT_H
