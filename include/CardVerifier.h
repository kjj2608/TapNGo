#ifndef TAPNGO_CARD_VERIFIER_H
#define TAPNGO_CARD_VERIFIER_H

#include <string>

class CardVerifier {
public:
    // Prototype-only validation; this is not real payment authorization.
    bool isCardFormatValid(const std::string& cardId) const;
    bool verifyCard(const std::string& cardId) const;
};

#endif
