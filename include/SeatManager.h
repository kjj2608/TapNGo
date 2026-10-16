#ifndef TAPNGO_SEAT_MANAGER_H
#define TAPNGO_SEAT_MANAGER_H

#include "Seat.h"
#include "Passenger.h"
#include <vector>

class SeatManager {
private:
    std::vector<Seat> seats;

public:
    explicit SeatManager(int seatCount);

    int getSeatCount() const;
    bool assignPassenger(int seatNumber, const Passenger& passenger);
    bool markFareVerified(int seatNumber);
    bool releaseSeat(int seatNumber);

    const Seat* getSeat(int seatNumber) const;
    int countByState(SeatState state) const;
    bool hasUnverifiedPassengers() const;
    void displaySeatMap() const;
};

#endif
