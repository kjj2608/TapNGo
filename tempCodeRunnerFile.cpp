// main.cpp
#include "DepartureController.h"
#include <iostream>
using namespace std;

int main() {
    DepartureController dc;

    cout << "=== Departure Controller Testing ===" << endl;

    // Case 1: kuch seats unverified hain
    cout << "\nTest Case 1:" << endl;
    if (dc.canDepart(3)) {
        cout << "Bus can depart!" << endl;
    } else {
        cout << "Bus cannot depart. 3 seat(s) are still unverified." << endl;
    }

    // Case 2: sab seats verified hain
    cout << "\nTest Case 2:" << endl;
    if (dc.canDepart(0)) {
        cout << "Bus can depart!" << endl;
    } else {
        cout << "Bus cannot depart." << endl;
    }

    return 0;
}
