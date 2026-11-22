#include <iostream>
#include <ctime>
#include <fstream>
#include "Passenger.h"
#include "Bus.h"
#include "Payment.h"
#include "exception.h"

using namespace std;

int main() {
    int seat_count;
    cout << "Number of seats(1-100): ";
    cin >> seat_count;
    Bus bus(seat_count);
    cout << "___\n";
    Payment payment;

    ofstream records("records.txt", ios::app);
    try{
        if(records.is_open()){
            time_t now = std::time(nullptr);
            tm* localTime = std::localtime(&now);
            char buffer[80];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
            records << "Trip Starting Time: " << buffer << '\n';
        } else {
            throw close_file_exception("Couldnt Open the Record file in Append mode");
        }
    }
    catch(close_file_exception &e){
        cout << "File Error! : " << e.what() << endl; 
    }
    int choice = 1;
    while(choice){
        User_Selection:
        cout << "\n1. Passenger\n2. Driver/Conductor\n0. Exit\nChoose: " ;
        cin >> choice;

        switch (choice) {
            case 1:{
                while(choice) {
                    cout << "\n1. Occupy Seat\n2. Pay\n3. Release Seat\n4. Show Stops\n0. Back\nChoose: " ;
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
            
                            bus.showMap();
                            int start, stop;
                            cout << "Starting Stop: ";
                            cin >> start;
                            cout << "Ending Stop: ";
                            cin >> stop;
            
                            Passenger passenger(id, name);
                            if(bus.assignPassenger(seat_no, passenger) && start != stop){
                                bus.setFare(seat_no, start, stop);
                                cout << "Seat is now Occupied Unverified.\n";
                            } else {
                                if(start == stop){
                                    cout << "start and stop can not be same!\n";
                                }
                                cout << "Seat Allocation Failed, Check details and try again.\n";
                            }                
                            break;
                        }
                        case 2:{
                            int seat_no;
                            string cardno;
                            cout << "Seat number: ";
                            cin >> seat_no;
                            if(bus.getStatus(seat_no) != 1){
                                cout << "Enter a valid seat no (Unverified).\n";
                                continue;
                            }
                            cin.ignore();
                            cout << "Card number: ";
                            getline(cin, cardno);
                            cout << "Checking card...\n";
                            if(payment.isValidCard(cardno)) {
                                cout << "Card valid\n";
                                bus.markVerified(seat_no);
                                cout << "Seat verified\n";
                                int fare = bus.getFare(seat_no);
                                cout << "Fare obtained: " << fare << endl;
                                payment.addTransaction(seat_no, fare);
                                cout << "Transaction added\n";
                                try{
                                    if(records.is_open()){
                                        records << "Seat " << seat_no << " | Amount " << fare << " | " << "Success" << endl;
                                    } else {
                                        throw close_file_exception("file is not opened");
                                    }
                                }
                                catch(close_file_exception &e){
                                    cout << "File Error! : " << e.what() << endl; 
                                }
                                cout << "Payment Successful : Rs " << fare << endl;
                            } else {
                                cout << "Payment Failed. Invalid card!\n";
                            }
                            break;
                        }
            
                        case 3:{
                            int seat_no;
                            cout << "Seat number: ";
                            cin >> seat_no;
                            if (bus.releaseSeat(seat_no, payment)){
                                cout << "Seat released.\n";
                                if(bus.isPaid(seat_no)){
                                    payment.removeTransaction(seat_no);
                                }
                            }
                            break;
                        }
            
                        case 4:{
                            bus.showMap();
                            break;
                        }
            
                        case 0:{
                            goto User_Selection;
                        }
                        
                        default:
                            cout << "Invalid Choice!\n";
                            break;
                    }
                }
                break;
            }
            case 2:{
                while(choice) {
                    cout << "\n1. Release Seat\n2. Dashboard\n3. Check Departure\n4. Transaction\n5. Show Stops\n0. Back\nChoose: " ;
                    cin >> choice;
                    
                    switch (choice) {
                        case 1:{
                            int seat_no;
                            cout << "Seat number: ";
                            cin >> seat_no;
                            if (bus.releaseSeat(seat_no, payment)){
                                cout << "Seat released.\n";
                                if(bus.isPaid(seat_no)){
                                    payment.removeTransaction(seat_no);
                                }
                            }
                            break;
                        }
            
                        case 2:{
                            bus.showDashboard();
                        }
            
                        case 3:{
                            if(bus.checkDeparture()){
                                cout << "\033[32m\nNo Unverified Passengers.\nBus is ready to depart.\n\033[0m";
                            } else {
                                cout << "\033[31m\nUnverified Passengers Remains.\n\033[0m";
                            }
                            break;
                        }
            
                        case 4:{
                            payment.displayTransaction();
                            break;
                        }
            
                        case 5:{
                            bus.showMap();
                            break;
                        }
            
                        case 0:{
                            goto User_Selection;
                        }
                        
                        default:
                            cout << "Invalid Choice!\n";
                            break;
                    }
                }
                break;
            }
            case 0:{
                try{
                    if(records.is_open()){
                        time_t now = std::time(nullptr);
                        tm* localTime = std::localtime(&now);
                        char buffer[80];
                        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
                        records << "Trip Ending Time: " << buffer << "\n\n";
                    } else {
                        throw close_file_exception("Couldnt Open the Record file in Append mode");
                    }
                }
                catch(close_file_exception &e){
                    cout << "File Error! : " << e.what() << endl; 
                }
                cout << "TAPnGO closed.\n" ;
                return 0;
            }    
            default:
                cout << "Invalid choice!\n";
                break;
            
        }
    }

    return 0;
}
