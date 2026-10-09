#ifndef DRIVER_CONTROL_H
#define DRIVER_CONTROL_H

#include "SeatManager.h"

class DriverControl {
private:
    SeatManager* seatManager;

public:
    DriverControl(SeatManager* manager);

    void displayStatus() const;
    bool canBusDepart() const;

    void showUnverifiedSeats() const;
};

#endif