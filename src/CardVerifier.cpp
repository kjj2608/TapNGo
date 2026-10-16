#include "CardVerifier.h"
#include <algorithm>
#include <cctype>

bool CardVerifier::isCardFormatValid(const std::string& cardId) const {
    if (cardId.size() < 4 || cardId.size() > 24) return false;
    return std::any_of(cardId.begin(), cardId.end(),
        [](unsigned char c) { return !std::isspace(c); });
}

bool CardVerifier::verifyCard(const std::string& cardId) const {
    return isCardFormatValid(cardId);
}
