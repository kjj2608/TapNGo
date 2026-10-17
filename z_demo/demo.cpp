#include <iostream>
#include <vector>
using namespace std;

struct Passenger {
    int id;
    int tripId;
    double fare;
    bool paid;
};

struct Driver {
    int id;
    string name;
    string licenseNo;
};

struct Bus {
    int id;
    string route;
    int capacity;
};

struct Trip {
    int id;
    int busId;
    int driverId;
    string departureTime;
    vector<Passenger> passengers;
};

bool canDepart(const Trip &t) {
    for (auto &p : t.passengers) {
        if (!p.paid) {
            return false; // ek bhi unpaid passenger hai toh bus depart nahi hogi
        }
    }
    return true; // sab paid hain toh bus depart hogi
}

int main() {
    Driver d1 = {1, "Ravi", "DL123"};
    Bus b1 = {101, "Route 5", 40};
    Trip t1 = {1001, b1.id, d1.id, "08:00 AM"};

    Passenger p1 = {501, t1.id, 20.0, false}; // unpaid
    Passenger p2 = {502, t1.id, 15.0, true};  // paid

    t1.passengers.push_back(p1);
    t1.passengers.push_back(p2);

    cout << "Trip " << t1.id << " by Driver " << d1.name
         << " on Bus " << b1.route << " at " << t1.departureTime << endl;

    if (canDepart(t1)) {
        cout << "✅ Bus departed successfully!" << endl;
    } else {
        cout << "❌ Bus cannot depart. Unpaid passengers present." << endl;
    }

    return 0;
}
