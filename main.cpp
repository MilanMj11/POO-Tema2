#include <bits/stdc++.h>
#include "Vehicle.h"
#include "Depot.h"

using namespace std;


int main() {
    Vehicle Tank("Panzer",20,1988,4);
    Vehicle RRR("ASDASD",1,2,3);
    Depot depozit;
    depozit.addVehicle(Tank);
    depozit.addVehicle(RRR);
    depozit.addVehicle(Tank);
    vector<Vehicle> my_list = depozit.getVList();
    for(int i=0;i<int(my_list.size());i++){
        cout << my_list[i] << '\n';
    }

    return 0;
}
