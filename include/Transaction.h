#ifndef TAPNGO_TRANSACTION_H
#define TAPNGO_TRANSACTION_H

#include <string>

enum class TransactionStatus {
    Pending,
    Successful,
    Failed
};

class Transaction {
private:
    unsigned long long transactionId;
    int seatNumber;
    std::string passengerId;
    double amount;
    std::string paymentMethod;
    TransactionStatus status;

public:
    Transaction(unsigned long long id, int seat, const std::string& passenger,
                double fare, const std::string& method);

    unsigned long long getId() const;
    int getSeatNumber() const;
    const std::string& getPassengerId() const;
    double getAmount() const;
    const std::string& getPaymentMethod() const;
    TransactionStatus getStatus() const;
    void setStatus(TransactionStatus newStatus);
};

#endif
