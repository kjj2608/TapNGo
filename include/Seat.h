#ifndef TAPNGO_SEAT_H
#define TAPNGO_SEAT_H

#include <string>

enum class SeatState {
    Empty,
    OccupiedUnverified,
    OccupiedVerified
};

class Seat {
private:
    int seatNumber;
    SeatState state;
    std::string passengerId;

public:
    explicit Seat(int number = 0);

    int getSeatNumber() const;
    SeatState getState() const;
    const std::string& getPassengerId() const;

    bool assignPassenger(const std::string& passengerId);
    bool markVerified();
    bool clear();

    static std::string stateName(SeatState state);
    static std::string stateColor(SeatState state);
};

#endif
