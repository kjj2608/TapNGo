#ifndef TAPNGO_PASSENGER_H
#define TAPNGO_PASSENGER_H

#include <string>

class Passenger {
private:
    std::string passengerId;
    std::string name;

public:
    Passenger(const std::string& id = "", const std::string& passengerName = "");

    const std::string& getId() const;
    const std::string& getName() const;
    bool isValid() const;
};

#endif
