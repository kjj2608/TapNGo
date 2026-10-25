#include "Passenger.h"

Passenger::Passenger(std::string id, std::string nm){
    passengerid = id;
    name = nm;
}

bool Passenger::isValid() {
    if(! passengerid.empty() && !name.empty())
        return true;
    return false;
}

void Passenger::setseat(int seatno){
    seatnumber = seatno;
    state = 1;
}

std::string Passenger::getId() {
    return passengerid;
}

std::string Passenger::getName() {
    return name;
}
