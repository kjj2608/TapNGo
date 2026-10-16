#ifndef TAPNGO_DEPARTURE_CONTROLLER_H
#define TAPNGO_DEPARTURE_CONTROLLER_H

class SeatManager;

class DepartureController {
private:
    const SeatManager& seatManager;

public:
    explicit DepartureController(const SeatManager& manager);
    bool canDepart() const;
    bool requestDeparture() const;
};

#endif
