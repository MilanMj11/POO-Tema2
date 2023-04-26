#include <bits/stdc++.h>
#include "Vehicle.h"
#include "Depot.h"
#include "Tank.h"
#include "Humvee.h"
#include "Exception.h"

using namespace std;

int main() {
    vector<Humvee> Humvee_list;
    Depot depozit;
    int n,nr;
    cout << "Cate vehicule doriti sa introduceti ?\n";
    cin >> n;
    for(int i=1;i<=n;i++){
        cout << "Vehiculul " << i << " doriti sa fie Tank(1) sau Humvee(2) ? ";
        cin >> nr;
        if(nr == 1) {
            std::shared_ptr<Tank> aux(new Tank("",0,0,0,0,0,0));
            cin >> *aux;
            depozit.addVehicle(aux);
        } else {
            std::shared_ptr<Humvee> aux(new Humvee("",0,0,0,0,0,0,0));
            cin >> *aux;
            depozit.addVehicle(aux);
        }
    }
    std::vector<std::shared_ptr<Vehicle>> Lista = depozit.getVList();
    for(auto it: Lista){
        cout << *it << '\n';
    }
    return 0;
}
