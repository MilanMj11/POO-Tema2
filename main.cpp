#include <bits/stdc++.h>
#include "Vehicle.h"
#include "Depot.h"
#include "Tank.h"
#include "Humvee.h"
#include "Exception.h"

using namespace std;

int main() {
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

    /// AICI PUTEM SA LUCRAM CU VEHICULELE , ADAUGAM ATRIBUTE , BLA BLA

    /// ________________________________________________________________

    cout << "Depozitul de vehicule contine: \n";
    for(auto it: Lista){
        cout << *it << '\n';
    }
    cout << '\n';
    /// pentru exceptie , demonstratie ca merge :
    Humvee MyH("M220 TOW",70,2016,3,10,5,1,0);
    MyH.AddStorage(4); /// pot sa adaug 4 , pentru ca 5+4 = 9 < 10
    MyH.AddStorage(2); /// nu mai pot sa adaug , pentru ca 9+2 = 11 > 10
    /// asa ca arunca exceptie;
    return 0;
}
