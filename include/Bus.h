#ifndef BUS_H
#define BUS_H

#include "Passenger.h"
#include "Payment.h"
#include <string>
#include <vector>

class Bus {
    private:
        // List of locations corresponding to the matrix rows and columns
        std::string locations[12] = {
            "ISBT", "Majra", "Sabzi Mandi", "Railway Stn.", "Prince Chowk", 
            "Clock Tower", "Gandhi Park", "Dilaram Chowk", "Survey of India", 
            "Jakhan", "Pacific Mall", "Rajpur"
        };
        // 12x12 Matrix representing the data
        const int fare_map[12][12] = {
            { 0, 10, 10, 20, 20, 25, 25, 30, 35, 35, 40, 45 }, // ISBT
            { 10, 0, 10, 15, 20, 20, 25, 30, 30, 35, 40, 45 }, // Majra
            { 10, 10, 0, 15, 15, 20, 25, 25, 30, 35, 40, 45 }, // Sabzi Mandi
            { 20, 15, 15, 0, 10, 15, 15, 20, 25, 30, 35, 40 }, // Railway Stn.
            { 20, 20, 15, 10, 0, 10, 10, 15, 20, 25, 30, 35 }, // Prince Chowk
            { 25, 20, 20, 15, 10, 0, 10, 10, 15, 20, 25, 30 }, // Clock Tower
            { 25, 25, 25, 15, 10, 10, 0, 10, 15, 20, 25, 30 }, // Gandhi Park
            { 30, 30, 25, 20, 15, 10, 10, 0, 10, 15, 20, 25 }, // Dilaram Chowk
            { 35, 30, 30, 25, 20, 15, 15, 10, 0, 10, 15, 20 }, // Survey of India
            { 35, 35, 35, 30, 25, 20, 20, 15, 10, 0, 10, 15 }, // Jakhan
            { 40, 40, 40, 35, 30, 25, 25, 20, 15, 10, 0, 10 }, // Pacific Mall
            { 45, 45, 45, 40, 35, 30, 30, 25, 20, 15, 10, 0 }  // Rajpur
        };
        int seatcount;
        std::vector<int> seats;
        std::vector<int> fare;
    public:
        Bus(int seatcount);
        int getSeatCount();
        bool assignPassenger(int seatNumber, Passenger& passenger);
        bool markVerified(int seatNumber);
        bool releaseSeat(int seatNumber, Payment& payment);
        bool isoccupied(int seatNumber);
        int getStatus(int seatNumber);
        void setFare(int seatNumber, int start, int stop);
        int getFare(int seatNumber){
            return fare[seatNumber];
        }

        void showDashboard();
        bool checkDeparture();
        void showMap();
};

#endif
