#include "DriverControl.h"
#include "SeatManager.h"
#include <iostream>

DriverControl::DriverControl(const SeatManager& manager) : seatManager(manager) {}

void DriverControl::showDashboard() const {
    seatManager.displaySeatMap();
    std::cout << "Departure readiness: "
              << (seatManager.hasUnverifiedPassengers()
                      ? "BLOCKED - unverified passengers remain"
                      : "READY - no unverified occupied seats")
              << '\n';
}
