#include <iostream>
#include <string>

#include "SeatManager.h"
#include "Passenger.h"
#include "CardPayment.h"
#include "CardVerifier.h"
#include "Transaction.h"
#include "TransactionQueue.h"
#include "DriverControl.h"
#include "DepartureController.h"

using namespace std;

void displayWelcome()
{
    cout << "\n";
    cout << "==============================================\n";
    cout << "              TAPNGo BUS SYSTEM              \n";
    cout << "       Bus Fare Verification System           \n";
    cout << "==============================================\n";
}

void displayMenu()
{
    cout << "\n--------------- MAIN MENU --------------------\n";
    cout << "1. Display Seat Map\n";
    cout << "2. Occupy a Seat\n";
    cout << "3. Verify Fare / Tap Card\n";
    cout << "4. Release a Seat\n";
    cout << "5. Display Driver Status\n";
    cout << "6. Check Departure\n";
    cout << "7. Display Transaction Queue\n";
    cout << "8. Exit\n";
    cout << "----------------------------------------------\n";
    cout << "Enter your choice: ";
}

int main()
{
    displayWelcome();

    // SYSTEM INITIALIZATION
    const int TOTAL_SEATS = 20;
    const double STANDARD_FARE = 30.0;

    // Seat management module
    SeatManager seatManager(TOTAL_SEATS);

    // Fare verification module
    CardVerifier cardVerifier(STANDARD_FARE);

    // Transaction management module
    TransactionQueue transactionQueue;

    // Driver control module
    DriverControl driverControl(&seatManager);

    // Departure control module
    DepartureController departureController(&seatManager);

    // DEMONSTRATION DATA
    int nextPassengerId = 101;
    int nextTransactionId = 1;

    bool running = true;

    // MAIN SYSTEM LOOP
    while (running)
    {
        displayMenu();

        int choice;
        cin >> choice;

        // 1. DISPLAY SEAT MAP
        if (choice == 1)
        {
            cout << "\n";
            cout << "========== CURRENT SEAT MAP ==========\n";

            seatManager.displaySeatMap();

            cout << "======================================\n";
        }

        // 2. OCCUPY A SEAT
        else if (choice == 2)
        {
            int seatNumber;
            string passengerName;

            cout << "\nEnter passenger name: ";
            cin.ignore();
            getline(cin, passengerName);

            cout << "Enter seat number: ";
            cin >> seatNumber;

            Passenger passenger(
                nextPassengerId,
                passengerName
            );

            passenger.assignSeat(seatNumber);


            // Attempt to occupy the seat
            bool success = seatManager.occupySeat(
                passenger.getSeatNumber(),
                passenger.getPassengerId()
            );


            if (success)
            {
                cout << "\nSeat occupied successfully.\n";
                cout << "Passenger ID : "
                     << passenger.getPassengerId() << "\n";
                cout << "Passenger    : "
                     << passenger.getName() << "\n";
                cout << "Seat Number  : "
                     << passenger.getSeatNumber() << "\n";

                cout << "Status       : OCCUPIED - UNVERIFIED\n";

                nextPassengerId++;
            }
            else
            {
                cout << "\nUnable to occupy seat.\n";
                cout << "Please check the seat number or availability.\n";
            }
        }

        // 3. VERIFY FARE / TAP CARD
        else if (choice == 3)
        {
            int passengerId;
            int seatNumber;
            string cardId;
            double amount;

            cout << "\nEnter passenger ID: ";
            cin >> passengerId;

            cout << "Enter seat number: ";
            cin >> seatNumber;

            cout << "Enter card ID: ";
            cin >> cardId;

            cout << "Enter fare amount: ";
            cin >> amount;


            // Create card payment
            CardPayment payment(
                amount,
                cardId
            );


            // Verify card and fare
            bool paymentValid = cardVerifier.verifyCard(payment);


            if (paymentValid)
            {
                // Verify the corresponding seat
                bool seatVerified =
                    seatManager.verifySeat(seatNumber);


                if (seatVerified)
                {
                    // Create transaction record
                    Transaction transaction(
                        nextTransactionId,
                        passengerId,
                        seatNumber,
                        amount
                    );


                    // Mark transaction as verified
                    transaction.markVerified();


                    // Add transaction to queue
                    transactionQueue.enqueue(transaction);


                    cout << "\n=====================================\n";
                    cout << "       FARE VERIFICATION SUCCESS     \n";
                    cout << "=====================================\n";

                    cout << "Card ID       : " << cardId << "\n";
                    cout << "Passenger ID  : " << passengerId << "\n";
                    cout << "Seat Number   : " << seatNumber << "\n";
                    cout << "Fare Paid     : " << amount << "\n";
                    cout << "Seat Status   : OCCUPIED - VERIFIED\n";
                    cout << "Transaction   : " << nextTransactionId << "\n";

                    cout << "=====================================\n";

                    nextTransactionId++;
                }
                else
                {
                    cout << "\nPayment was valid, but the seat could not be verified.\n";
                    cout << "Check whether the seat is occupied.\n";
                }
            }
            else
            {
                cout << "\nFare verification FAILED.\n";
                cout << "Seat remains OCCUPIED - UNVERIFIED.\n";
            }
        }

        // 4. RELEASE A SEAT
        else if (choice == 4)
        {
            int seatNumber;

            cout << "\nEnter seat number to release: ";
            cin >> seatNumber;


            bool success =
                seatManager.releaseSeat(seatNumber);


            if (success)
            {
                cout << "\nSeat " << seatNumber
                     << " has been released.\n";

                cout << "Status: EMPTY\n";
            }
            else
            {
                cout << "\nUnable to release seat.\n";
                cout << "Please check the seat number.\n";
            }
        }

        // 5. DRIVER STATUS
        else if (choice == 5)
        {
            cout << "\n";
            cout << "==============================================\n";
            cout << "             DRIVER STATUS PANEL              \n";
            cout << "==============================================\n";

            driverControl.displayStatus();

            cout << "\nUnverified seats:\n";

            driverControl.showUnverifiedSeats();

            cout << "==============================================\n";
        }

        // 6. CHECK DEPARTURE
        else if (choice == 6)
        {
            cout << "\n";
            cout << "==============================================\n";
            cout << "              DEPARTURE CHECK                 \n";
            cout << "==============================================\n";

            departureController.displayDepartureStatus();

            cout << "==============================================\n";
        }

        // 7. DISPLAY TRANSACTION QUEUE
        else if (choice == 7)
        {
            cout << "\n";
            cout << "==============================================\n";
            cout << "             TRANSACTION QUEUE                \n";
            cout << "==============================================\n";

            if (transactionQueue.isEmpty())
            {
                cout << "No transactions in queue.\n";
            }
            else
            {
                transactionQueue.displayQueue();
            }

            cout << "==============================================\n";
        }

        // 8. EXIT
        else if (choice == 8)
        {
            cout << "\n";
            cout << "Thank you for using TapNGo.\n";
            cout << "System shutting down...\n";

            running = false;
        }

        // INVALID OPTION
        else
        {
            cout << "\nInvalid choice.\n";
            cout << "Please select an option from 1 to 8.\n";
        }
    }


    return 0;
}