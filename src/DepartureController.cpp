#include "DepartureController.h"   // DepartureController class header
#include "SeatManager.h"           // SeatManager class header
#include <iostream>                // For printing messages

// Constructor: links DepartureController with SeatManager
DepartureController::DepartureController(const SeatManager& manager)
    : seatManager(manager) {}

// Checks if bus can depart (true if no unverified passengers)
bool DepartureController::canDepart() const {
    return !seatManager.hasUnverifiedPassengers();
}

// Handles departure request: prints result and returns true/false
bool DepartureController::requestDeparture() const {
    if (!canDepart()) {
        std::cout << "Departure denied: at least one occupied seat is unverified.\n";
        return false;   // Not allowed
    }
    std::cout << "Departure check passed.\n";
    return true;        // Allowed
}
