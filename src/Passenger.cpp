#include "Passenger.h"

Passenger::Passenger(const std::string& id, const std::string& passengerName)
    : passengerId(id), name(passengerName) {}

const std::string& Passenger::getId() const { return passengerId; }
const std::string& Passenger::getName() const { return name; }

bool Passenger::isValid() const {
    return !passengerId.empty() && !name.empty();
}
