#include "DriverControl.h"   // DriverControl class header
#include "SeatManager.h"     // SeatManager class header
#include <iostream>          // For printing output

// Constructor: connects DriverControl with SeatManager
DriverControl::DriverControl(const SeatManager& manager) : seatManager(manager) {}

// showDashboard: displays seat map and departure readiness
void DriverControl::showDashboard() const {
    seatManager.displaySeatMap();   // Show current seat status

    // Print departure readiness based on unverified passengers
    std::cout << "Departure readiness: "
              << (seatManager.hasUnverifiedPassengers()
                      ? "BLOCKED - unverified passengers remain"
                      : "READY - no unverified occupied seats")
              << '\n';
}
