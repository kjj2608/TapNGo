#include "TransactionQueue.h"

void TransactionQueue::enqueue(const Transaction& transaction) {
    transactions.push(transaction);
}

bool TransactionQueue::dequeue(Transaction& transaction) {
    if (transactions.empty()) return false;
    transaction = transactions.front();
    transactions.pop();
    return true;
}

bool TransactionQueue::isEmpty() const { return transactions.empty(); }
std::size_t TransactionQueue::size() const { return transactions.size(); }
