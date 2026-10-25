#ifndef BUS_H
#define BUS_H

#include "Passenger.h"
#include <string>
#include <vector>

class Bus {
    private:
        int seatcount;
        std::vector<int> seats;
    public:
        Bus(int seatcount);
        int getSeatCount();
        bool assignPassenger(int seatNumber, Passenger& passenger);
        bool markVerified(int seatNumber);
        bool releaseSeat(int seatNumber);
        bool isoccupied(int seatNumber);
        int getStatus(int seatNumber);

        void showDashboard();
        bool checkDeparture();

};

#endif
