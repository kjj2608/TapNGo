#include "Bus.h"
#include <iostream>
#include <stdlib.h>

Bus::Bus(int sc){
    seatcount = sc;
    seats.resize(seatcount);
    for(int i = 0; i < seatcount; i++){
        seats[i] = 0;
    }
};

int Bus::getSeatCount() {
    return seatcount;
}

bool Bus::assignPassenger(int seatno, Passenger& passenger){
    seatno--;
    if(passenger.isValid() && seatno >= 0 && seatno < Bus::getSeatCount() &&  seats[seatno] == 0){
        seats[seatno] = 1;
        passenger.setseat(seatno);
        return true;
    }
    return false;
}

bool Bus::markVerified(int seatno){
    seatno--;
    if(seats[seatno] == 1){
        seats[seatno] = 2;
        return true;
    }
    return false;
}

bool Bus::releaseSeat(int seatno){
    seatno--;
    if(seats[seatno] != 0){
        seats[seatno] = 0;
        return true;
    }
    std::cout << "Already Empty\n";
    return false;
}

bool Bus::isoccupied(int seatno){
    seatno--;
    return ( seats[seatno] != 0 );
}

int Bus::getStatus(int seatno){
    seatno--;
    return (seats[seatno]);
}

void Bus::showDashboard() {
    std::cout << "\n-- Driver Dashboard -- \n";
    int i , e = 0, u = 0, v = 0, s;
    std::string st;
    for(i = 1; i <= Bus::getSeatCount(); i++){
        s = Bus::getStatus(i);
        switch(s){
            case 0: std::cout << "\033[0m";
            st = "EMPTY";
            e++;
            break;
            case 1: std::cout << "\033[31m";
            st = "UNVERIFIED";
            u++;
            break;
            case 2: std::cout << "\033[32m";
            st = "VERIFIED";
            v++;
            break;
        }
        std::cout << "Seat " << i << ": " << st << std::endl;
    }
    std::cout << "\033[0m";
    std::cout << "Empty: " << e << " | Unverified: " << u << " | Verified: " << v << std::endl;
}

bool Bus::checkDeparture(){
    for(int i = 1; i <= Bus::getSeatCount(); i++){
        if(Bus::getStatus(i) == 1){
            return false;
        }
    }
    return true;
}
