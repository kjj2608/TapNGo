#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
private:
    int passengerId;
    std::string name;
    int seatNumber;

public:
    Passenger(int id, const std::string& name);

    int getPassengerId() const;
    std::string getName() const;
    int getSeatNumber() const;

    void assignSeat(int seatNumber);
    void removeSeat();
};

#endif