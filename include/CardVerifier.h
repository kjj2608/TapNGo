#ifndef CARD_VERIFIER_H
#define CARD_VERIFIER_H

#include "CardPayment.h"

class CardVerifier {
private:
    double standardFare;

public:
    CardVerifier(double fare);

    bool verifyCard(CardPayment& payment);
    bool verifyFare(double amount) const;

    double getFare() const;
};

#endif