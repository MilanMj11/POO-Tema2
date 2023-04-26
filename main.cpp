#include <bits/stdc++.h>
#include "Vehicle.h"
#include "Depot.h"
#include "Tank.h"
#include "Humvee.h"
#include "Exception.h"

using namespace std;

int main() {
    Humvee OK("asdasd",1,21,2,7,2,1,1);
    Tank NU("asdasd",1,2,3,1,2,3);
    OK.AddStorage(3);

    cout << NU << '\n';
    cin >> OK;
    cout << OK;

    return 0;
}
