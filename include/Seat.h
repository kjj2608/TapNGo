#ifndef SEAT_H
#define SEAT_H

#include <string>

enum class SeatState {
    EMPTY,
    OCCUPIED_UNVERIFIED,
    OCCUPIED_VERIFIED
};

class Seat {
private:
    int seatNumber;
    SeatState state;
    int passengerId;

public:
    Seat(int number);

    int getSeatNumber() const;
    SeatState getState() const;
    int getPassengerId() const;

    void occupy(int passengerId);
    void verify();
    void release();

    bool isEmpty() const;
    bool isVerified() const;
    std::string getStateString() const;
};

#endif