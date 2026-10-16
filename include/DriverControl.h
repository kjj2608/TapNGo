#ifndef TAPNGO_DRIVER_CONTROL_H
#define TAPNGO_DRIVER_CONTROL_H

class SeatManager;

class DriverControl {
private:
    const SeatManager& seatManager;

public:
    explicit DriverControl(const SeatManager& manager);
    void showDashboard() const;
};

#endif
