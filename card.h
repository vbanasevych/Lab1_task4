#pragma once

#include <iostream>
#include <compare>

enum class Suit { Hearts, Diamonds, Clubs, Spades };

struct Card {
    Suit suit;
    int value;

    // Порівняння лише за value
    auto operator<=>(const Card& other) const {
        return value <=> other.value;
    }

    // Вивід карти
    friend std::ostream& operator<<(std::ostream& os, const Card& c);
};
