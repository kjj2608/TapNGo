#ifndef TAPNGO_TRANSACTION_QUEUE_H
#define TAPNGO_TRANSACTION_QUEUE_H

#include "Transaction.h"
#include <cstddef>
#include <queue>

class TransactionQueue {
private:
    std::queue<Transaction> transactions;

public:
    void enqueue(const Transaction& transaction);
    bool dequeue(Transaction& transaction);
    bool isEmpty() const;
    std::size_t size() const;
};

#endif
