#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger {
    private:
        int seatnumber, state;
        std::string passengerid, name;
    public:
        Passenger(std::string id = "", std::string name = "");
        void setseat(int seatno);
        std::string getId();
        std::string getName();
        bool isValid();
};

#endif