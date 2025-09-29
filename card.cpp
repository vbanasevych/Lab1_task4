#include "card.h"

std::string Card::toString() const {
    std::string suitStr;
    switch (suit) {
        case Suit::Hearts:   suitStr = "♥"; break;
        case Suit::Diamonds: suitStr = "♦"; break;
        case Suit::Clubs:    suitStr = "♣"; break;
        case Suit::Spades:   suitStr = "♠"; break;
    }
    return std::to_string(value) + suitStr;
}

std::ostream& operator<<(std::ostream& os, const Card& c) {
    os << c.toString();
    return os;
}
// зробити декомпозицію
// може бути метод, який конвертує в рядок, а тоді вже виводити