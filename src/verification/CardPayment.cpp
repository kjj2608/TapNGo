#include "CardPayment.h"

bool CardPayment::processPayment(double amount, const std::string& token) {
    // Simulated payment only: a real system must use a secure payment provider.
    return amount > 0.0 && verifier.verifyCard(token);
}

std::string CardPayment::getMethodName() const {
    return "Card";
}
