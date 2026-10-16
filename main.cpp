#include "CardPayment.h"
#include "DepartureController.h"
#include "DriverControl.h"
#include "Passenger.h"
#include "SeatManager.h"
#include "TransactionQueue.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <string>

using namespace std;

namespace {
int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if ( cin >> value) {
            cin.ignore( numeric_limits< streamsize>::max(), '\n');
            return value;
        }
        cout << "Enter a valid whole number.\n";
        cin.clear();
        cin.ignore( numeric_limits< streamsize>::max(), '\n');
    }
}

 string readText(const  string& prompt) {
    string value;
    cout << prompt;
    getline( cin, value);
    return value;
}
}

int main() {
    cout << "=== TapNGo Bus Fare Verification Prototype ===\n";
    int seatCount = readInt("Number of seats (1-100): ");
    if (seatCount < 1 || seatCount > 100) seatCount = 20;

    SeatManager seatManager(seatCount);
    DriverControl driver(seatManager);
    DepartureController departure(seatManager);
    unique_ptr<Payment> payment =  make_unique<CardPayment>();
    TransactionQueue transactions;
    unsigned long long nextTransactionId = 1;
    const double fare = 20.0;

    bool running = true;
    while (running) {
        cout << "\n1. Occupy seat\n"
                  << "2. Pay/verify fare by card (demo)\n"
                  << "3. Release seat\n"
                  << "4. Driver dashboard\n"
                  << "5. Check departure\n"
                  << "6. Show queued transactions\n"
                  << "0. Exit\n";
        int choice = readInt("Choose: ");

        if (choice == 1) {
            int seat = readInt("Seat number: ");
            string id = readText("Passenger ID: ");
            string name = readText("Passenger name: ");
            Passenger passenger(id, name);
            if (seatManager.assignPassenger(seat, passenger))
                cout << "Seat is now Occupied Unverified.\n";
            else
                cout << "Could not assign passenger. Check seat and passenger details.\n";
        } else if (choice == 2) {
            int seat = readInt("Seat number: ");
            const Seat* selectedSeat = seatManager.getSeat(seat);
            if (!selectedSeat || selectedSeat->getState() != SeatState::OccupiedUnverified) {
                cout << "Choose a valid occupied, unverified seat first.\n";
                continue;
            }
            string token = readText("Demo card ID (4-24 characters): ");
            Transaction transaction(nextTransactionId++, seat,
                                    selectedSeat->getPassengerId(), fare,
                                    payment->getMethodName());
            bool paid = payment->processPayment(fare, token);
            transaction.setStatus(paid ? TransactionStatus::Successful
                                       : TransactionStatus::Failed);
            transactions.enqueue(transaction);

            if (paid && seatManager.markFareVerified(seat))
                cout << "Demo payment accepted. Seat is now Occupied Verified.\n";
            else
                cout << "Demo payment failed; seat remains unverified.\n";
            cout << "Demo fare: " <<  fixed <<  setprecision(2) << fare << '\n';
        } else if (choice == 3) {
            int seat = readInt("Seat number: ");
            cout << (seatManager.releaseSeat(seat) ? "Seat released.\n"
                                                        : "Could not release seat.\n");
        } else if (choice == 4) {
            driver.showDashboard();
        } else if (choice == 5) {
            departure.requestDeparture();
        } else if (choice == 6) {
            cout << "Queued transactions: " << transactions.size() << '\n';
            Transaction transaction(0, 0, "", 0.0, "");
            while (transactions.dequeue(transaction)) {
                const char* status = transaction.getStatus() == TransactionStatus::Successful
                    ? "SUCCESS" : (transaction.getStatus() == TransactionStatus::Failed
                    ? "FAILED" : "PENDING");
                cout << "ID " << transaction.getId()
                          << " | Seat " << transaction.getSeatNumber()
                          << " | Passenger " << transaction.getPassengerId()
                          << " | Amount " << transaction.getAmount()
                          << " | " << status << '\n';
            }
        } else if (choice == 0) {
            running = false;
        } else {
            cout << "Invalid option.\n";
        }
    }

    cout << "TapNGo closed.\n";
    return 0;
}
