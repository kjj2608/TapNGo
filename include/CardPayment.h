#ifndef TAPNGO_CARD_PAYMENT_H
#define TAPNGO_CARD_PAYMENT_H

#include "Payment.h"
#include "CardVerifier.h"

class CardPayment : public Payment {
private:
    CardVerifier verifier;

public:
    bool processPayment(double amount, const std::string& paymentToken) override;
    std::string getMethodName() const override;
};

#endif
