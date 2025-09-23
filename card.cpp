#include "card.h"

std::ostream& operator<<(std::ostream& os, const Card& c) {
    std::string suitStr;
    switch (c.suit) {
        case Suit::Hearts:   suitStr = "♥"; break;
        case Suit::Diamonds: suitStr = "♦"; break;
        case Suit::Clubs:    suitStr = "♣"; break;
        case Suit::Spades:   suitStr = "♠"; break;
    }
    os << c.value << suitStr;
    return os;
}
// зробити декомпозицію
// може бути метод, який конвертує в рядок, а тоді вже виводити