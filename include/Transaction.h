#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    int transactionId;
    int passengerId;
    int seatNumber;
    double amount;
    bool verified;
    std::string timestamp;

public:
    Transaction(
        int transactionId,
        int passengerId,
        int seatNumber,
        double amount
    );

    int getTransactionId() const;
    int getPassengerId() const;
    int getSeatNumber() const;
    double getAmount() const;

    bool isVerified() const;

    void markVerified();

    void display() const;
};

#endif