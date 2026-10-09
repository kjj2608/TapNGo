#ifndef DEPARTURE_CONTROLLER_H
#define DEPARTURE_CONTROLLER_H

#include "SeatManager.h"

class DepartureController {
private:
    SeatManager* seatManager;

public:
    DepartureController(SeatManager* manager);

    bool checkDeparture() const;
    void displayDepartureStatus() const;
};

#endif