#include "Seat.h"

Seat::Seat(int number)
    : seatNumber(number), state(SeatState::Empty), passengerId() {}

int Seat::getSeatNumber() const { return seatNumber; }
SeatState Seat::getState() const { return state; }
const std::string& Seat::getPassengerId() const { return passengerId; }

bool Seat::assignPassenger(const std::string& id) {
    if (state != SeatState::Empty || id.empty()) return false;
    passengerId = id;
    state = SeatState::OccupiedUnverified;
    return true;
}

bool Seat::markVerified() {
    if (state != SeatState::OccupiedUnverified) return false;
    state = SeatState::OccupiedVerified;
    return true;
}

bool Seat::clear() {
    if (state == SeatState::Empty) return false;
    passengerId.clear();
    state = SeatState::Empty;
    return true;
}

std::string Seat::stateName(SeatState value) {
    switch (value) {
        case SeatState::Empty: return "Empty";
        case SeatState::OccupiedUnverified: return "Occupied Unverified";
        case SeatState::OccupiedVerified: return "Occupied Verified";
    }
    return "Unknown";
}

std::string Seat::stateColor(SeatState value) {
    switch (value) {
        case SeatState::Empty: return "GREY";
        case SeatState::OccupiedUnverified: return "RED";
        case SeatState::OccupiedVerified: return "GREEN";
    }
    return "UNKNOWN";
}
