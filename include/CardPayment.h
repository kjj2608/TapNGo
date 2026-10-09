#ifndef CARD_PAYMENT_H
#define CARD_PAYMENT_H

#include "Payment.h"
#include <string>

class CardPayment : public Payment {
private:
    std::string cardId;

public:
    CardPayment(double amount, const std::string& cardId);

    bool processPayment() override;
    bool verify() override;

    std::string getCardId() const;
};

#endif