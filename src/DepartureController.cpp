#include "DepartureController.h"
#include "SeatManager.h"
#include <iostream>

DepartureController::DepartureController(const SeatManager& manager)
    : seatManager(manager) {}

bool DepartureController::canDepart() const {
    return !seatManager.hasUnverifiedPassengers();
}

bool DepartureController::requestDeparture() const {
    if (!canDepart()) {
        std::cout << "Departure denied: at least one occupied seat is unverified.\n";
        return false;
    }
    std::cout << "Departure check passed.\n";
    return true;
}
