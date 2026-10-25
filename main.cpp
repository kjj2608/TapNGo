#include <iostream>
#include "Passenger.h"
#include "Bus.h"
#include "Payment.h"

using namespace std;

#define fare 20

int main() {
    int seat_count;
    cout << "Number of seats(1-100): ";
    cin >> seat_count;
    Bus bus(seat_count);
    cout << "___\n";
    Payment payment;

    int choice = 1;
    while(choice) {
        cout << "\n1. Occupy Seat\n2. Pay\n3. Release Seat\n4. Dashboard\n5. Check Departure\n6. Transaction\n0. Exit\nChoose: " ;
        cin >> choice;
        
        switch (choice) {
            case 1:{
                int seat_no;
                string id, name;
                cout << "Seat number: ";
                cin >> seat_no;
                cout << "Passenger Id: ";
                cin >> id;
                cout << "Passenger Name: ";
                cin >> name;

                Passenger passenger(id, name);
                if(bus.assignPassenger(seat_no, passenger)){
                    cout << "Seat is not Occupied Unverified.\n";
                } else {
                    cout << "Seat Allocation Failed, Check details and try again.\n";
                }                
                break;
            }
            case 2:{
                int seat_no;
                long int cardno;
                cout << "Seat number: ";
                cin >> seat_no;
                if(bus.getStatus(seat_no) != 1){
                    cout << "Enter a valid seat no (Unverified).\n";
                    continue;
                }
                cout << "Card number: ";
                cin >> cardno;
                if(payment.isValidCard(cardno)) {
                    bus.markVerified(seat_no);
                    payment.addTransaction(seat_no, fare);
                } else {
                    cout << "Payment Failed. Invalid card!\n";
                }
                break;
            }

            case 3:{
                int seat_no;
                cout << "Seat number: ";
                cin >> seat_no;
                if (bus.releaseSeat(seat_no)){
                    cout << "Seat released.\n";
                }
            }

            case 4:{
                bus.showDashboard();
            }

            case 5:{
                if(bus.checkDeparture()){
                    cout << "\033[32m\nNo Unverified Passengers.\nBus is ready to depart.\n\033[0m";
                } else {
                    cout << "\033[31m\nUnverified Passengers Remains.\n\033[0m";
                }
                break;
            }

            case 6:{
                payment.displayTransaction();
                break;
            }

            case 0:{
                cout << "TAPnGO closed.\n" ;
                return 0;
            }
            
            default:
                break;
        }
    }

    return 0;
}
