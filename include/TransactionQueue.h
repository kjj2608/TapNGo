#ifndef TRANSACTION_QUEUE_H
#define TRANSACTION_QUEUE_H

#include "Transaction.h"
#include <queue>

class TransactionQueue {
private:
    std::queue<Transaction> transactions;

public:
    void enqueue(const Transaction& transaction);
    Transaction dequeue();

    bool isEmpty() const;
    int size() const;

    void displayQueue() const;
};

#endif