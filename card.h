#pragma once

#include <iostream>

enum class Suit { Hearts, Diamonds, Clubs, Spades };

struct Card {
    Suit suit;
    int value;


    auto operator<=>(const Card& other) const {
        return value <=> other.value;
    }
    std::string toString() const;

     friend std::ostream& operator<<(std::ostream& os, const Card& c);
};
