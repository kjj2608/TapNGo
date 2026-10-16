#include "SeatManager.h"
#include <iostream>

SeatManager::SeatManager(int count) {
    if (count < 1) count = 1;
    if (count > 100) count = 100;
    seats.reserve(static_cast<std::size_t>(count));
    for (int i = 1; i <= count; ++i) seats.emplace_back(i);
}

int SeatManager::getSeatCount() const { return static_cast<int>(seats.size()); }

bool SeatManager::assignPassenger(int number, const Passenger& passenger) {
    if (!passenger.isValid() || number < 1 || number > getSeatCount()) return false;
    return seats[static_cast<std::size_t>(number - 1)].assignPassenger(passenger.getId());
}

bool SeatManager::markFareVerified(int number) {
    if (number < 1 || number > getSeatCount()) return false;
    return seats[static_cast<std::size_t>(number - 1)].markVerified();
}

bool SeatManager::releaseSeat(int number) {
    if (number < 1 || number > getSeatCount()) return false;
    return seats[static_cast<std::size_t>(number - 1)].clear();
}

const Seat* SeatManager::getSeat(int number) const {
    if (number < 1 || number > getSeatCount()) return nullptr;
    return &seats[static_cast<std::size_t>(number - 1)];
}

int SeatManager::countByState(SeatState state) const {
    int count = 0;
    for (const Seat& seat : seats) if (seat.getState() == state) ++count;
    return count;
}

bool SeatManager::hasUnverifiedPassengers() const {
    return countByState(SeatState::OccupiedUnverified) > 0;
}

void SeatManager::displaySeatMap() const {
    std::cout << "\n--- Driver Seat Map ---\n";
    for (const Seat& seat : seats) {
        std::cout << "Seat " << seat.getSeatNumber() << ": "
                  << Seat::stateName(seat.getState()) << " ["
                  << Seat::stateColor(seat.getState()) << "]\n";
    }
    std::cout << "Empty: " << countByState(SeatState::Empty)
              << " | Unverified: " << countByState(SeatState::OccupiedUnverified)
              << " | Verified: " << countByState(SeatState::OccupiedVerified) << "\n";
}
