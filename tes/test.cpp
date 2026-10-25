#include <iostream>
#include "Bus.h"

using namespace std;

int main() {
    Bus bus(5);
    cout << bus.getSeatCount() <<endl;
    cout << bus.getStatus(1) <<endl;
    bus.showDashboard();
    // Write C++ code here
    cout << "Hello\n";
    cout << "\033[31m";
    cout << "Hello\n";
    cout << "\033[32m";
    cout << "Hello\n";
    cout << "\033[0m";
    cout << "Hello\n";
    return 0;
}
