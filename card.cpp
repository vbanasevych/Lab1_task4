#include "card.h"

std::string Card::toString() const {
    std::string suitStr;
    switch (suit) {
        case Suit::Hearts:   suitStr = "Hearts"; break;
        case Suit::Diamonds: suitStr = "Diamonds"; break;
        case Suit::Clubs:    suitStr = "Clubs"; break;
        case Suit::Spades:   suitStr = "Spades"; break;
        default: throw std::logic_error("Invalid Suit in Card::toString()");
    }
    return std::to_string(value) + " of " + suitStr;
}

std::ostream& operator<<(std::ostream& os, const Card& c) {
    os << c.toString();
    return os;
}