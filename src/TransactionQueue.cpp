#include "TransactionQueue.h"

// Adds a transaction to the queue.
void TransactionQueue::enqueue(const Transaction& transaction) {
    transactions.push(transaction);
}

// Removes the oldest transaction from the queue.
bool TransactionQueue::dequeue(Transaction& transaction) {
    // Check if the queue is empty.
    if (transactions.empty()) return false;

    // Get and remove the oldest transaction.
    transaction = transactions.front();
    transactions.pop();
    return true;
}

// Checks if the queue is empty.
bool TransactionQueue::isEmpty() const { return transactions.empty(); }

// Returns the number of transactions.
std::size_t TransactionQueue::size() const { return transactions.size(); }
