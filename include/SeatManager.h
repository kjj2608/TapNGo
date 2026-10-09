#ifndef SEAT_MANAGER_H
#define SEAT_MANAGER_H

#include "Seat.h"
#include <vector>

class SeatManager {
private:
    std::vector<Seat> seats;

public:
    SeatManager(int totalSeats);

    bool occupySeat(int seatNumber, int passengerId);
    bool verifySeat(int seatNumber);
    bool releaseSeat(int seatNumber);

    Seat* getSeat(int seatNumber);

    bool allSeatsVerified() const;
    bool hasUnverifiedSeats() const;

    void displaySeatMap() const;
    int getTotalSeats() const;
};

#endif