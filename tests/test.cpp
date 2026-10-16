#include "CardPayment.h"
#include "DepartureController.h"
#include "Passenger.h"
#include "Seat.h"
#include "SeatManager.h"
#include "Transaction.h"
#include "TransactionQueue.h"


#include <cassert>
#include <iostream>
 
//EDGE CASES

//Edge Case 1: SeatManager → Invalid seat index

void testInvalidSeatIndex() {
    SeatManager manager(3); // sirf 3 seats hain
    Passenger p("P200", "Edge Passenger");

    // Invalid seat index (10) → should fail
    assert(manager.assignPassenger(10, p) == false);

    std::cout << "SeatManager invalid index test passed!\n";
}

//Edge Case 2: Payment → Zero/negative amount, invalid card

void testPaymentEdgeCases() {
    CardPayment payment;

    // Zero amount → fail
    assert(!payment.processPayment(0.0, "CARD1234"));

    // Negative amount → fail
    assert(!payment.processPayment(-50.0, "CARD1234"));

    // Invalid card format → fail
    assert(!payment.processPayment(20.0, "xxx"));

    std::cout << "Payment edge cases test passed!\n";
}

//Edge Case 3: TransactionQueue → Empty dequeue

void testEmptyQueueDequeue() {
    TransactionQueue queue;
    Transaction out(0,0,"",0.0,"");

    // Empty queue → dequeue should fail
    assert(!queue.dequeue(out));
    assert(queue.isEmpty());

    std::cout << "TransactionQueue empty dequeue test passed!\n";
}




int main() {
    Seat seat(1);
    assert(seat.getState() == SeatState::Empty);
    assert(seat.assignPassenger("P001"));
    assert(seat.getState() == SeatState::OccupiedUnverified);
    assert(!seat.assignPassenger("P002"));
    assert(seat.markVerified());
    assert(seat.getState() == SeatState::OccupiedVerified);
    assert(seat.clear());
    assert(seat.getState() == SeatState::Empty);

    SeatManager manager(3);
    Passenger passenger("P100", "Test Passenger");
    assert(manager.assignPassenger(2, passenger));
    assert(manager.hasUnverifiedPassengers());
    DepartureController departure(manager);
    assert(!departure.canDepart());
    assert(manager.markFareVerified(2));
    assert(!manager.hasUnverifiedPassengers());
    assert(departure.canDepart());

    CardPayment payment;
    assert(payment.processPayment(20.0, "CARD1234"));
    assert(!payment.processPayment(0.0, "CARD1234"));
    assert(!payment.processPayment(20.0, "x"));

    TransactionQueue queue;
    Transaction tx(1, 2, "P100", 20.0, "Card");
    tx.setStatus(TransactionStatus::Successful);
    queue.enqueue(tx);
    assert(queue.size() == 1);
    Transaction out(0, 0, "", 0.0, "");
    assert(queue.dequeue(out));
    assert(out.getId() == 1);
    assert(out.getStatus() == TransactionStatus::Successful);
    assert(queue.isEmpty());

    std::cout << "All TapNGo tests passed.\n";

    // Edge case call
    testInvalidSeatIndex();
    testPaymentEdgeCases();
    testEmptyQueueDequeue();

    std::cout << "All edge case tests passed!\n";
    return 0;
    
}
