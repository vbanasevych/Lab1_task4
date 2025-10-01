#pragma once

#include <iostream>
#include <stdexcept>

enum class Suit { Hearts, Diamonds, Clubs, Spades };

struct Card {
    Suit suit;
    int value;

    Card(Suit s, int v) : suit(s), value(v) {
        if (v <= 0) {
            throw std::invalid_argument("Card value must be > 0");
        }
    }

    auto operator<=>(const Card& other) const {
        return value <=> other.value;
    }

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, const Card& c);
};
