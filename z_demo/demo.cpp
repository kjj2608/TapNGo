#include <iostream>
#include <vector>
using namespace std;

// Passenger structure: stores passenger details
struct Passenger {
    int id;
    int tripId;
    double fare;
    bool paid;   // true if fare is paid
};

// Driver structure: stores driver details
struct Driver {
    int id;
    string name;
    string licenseNo;
};

// Bus structure: stores bus details
struct Bus {
    int id;
    string route;
    int capacity;
};

// Trip structure: links bus, driver, and passengers
struct Trip {
    int id;
    int busId;
    int driverId;
    string departureTime;
    vector<Passenger> passengers;  // list of passengers
};

// Checks if all passengers have paid before departure
bool canDepart(const Trip &t) {
    for (auto &p : t.passengers) {
        if (!p.paid) {
            return false; // one unpaid passenger → cannot depart
        }
    }
    return true; // all paid → can depart
}

int main() {
    // Create driver and bus
    Driver d1 = {1, "Ravi", "DL123"};
    Bus b1 = {101, "Route 5", 40};

    // Create trip with driver and bus
    Trip t1 = {1001, b1.id, d1.id, "08:00 AM"};

    // Add passengers (one unpaid, one paid)
    Passenger p1 = {501, t1.id, 20.0, false}; // unpaid
    Passenger p2 = {502, t1.id, 15.0, true};  // paid
    t1.passengers.push_back(p1);
    t1.passengers.push_back(p2);

    // Show trip details
    cout << "Trip " << t1.id << " by Driver " << d1.name
         << " on Bus " << b1.route << " at " << t1.departureTime << endl;

    // Departure check
    if (canDepart(t1)) {
        cout << "✅ Bus departed successfully!" << endl;
    } else {
        cout << "❌ Bus cannot depart. Unpaid passengers present." << endl;
    }

    return 0;
}
