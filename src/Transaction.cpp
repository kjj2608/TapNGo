#include "Transaction.h"

Transaction::Transaction(unsigned long long id, int seat, const std::string& passenger,
                         double fare, const std::string& method)
    : transactionId(id), seatNumber(seat), passengerId(passenger),
      amount(fare), paymentMethod(method), status(TransactionStatus::Pending) {}

unsigned long long Transaction::getId() const { return transactionId; }
int Transaction::getSeatNumber() const { return seatNumber; }
const std::string& Transaction::getPassengerId() const { return passengerId; }
double Transaction::getAmount() const { return amount; }
const std::string& Transaction::getPaymentMethod() const { return paymentMethod; }
TransactionStatus Transaction::getStatus() const { return status; }
void Transaction::setStatus(TransactionStatus value) { status = value; }
