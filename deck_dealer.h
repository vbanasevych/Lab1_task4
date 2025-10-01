#pragma once

#include "card.h"
#include <vector>
#include <random>

class DeckDealer {
    std::vector<Card> deck;
    size_t index;
    int cardsPerSuit;
    std::mt19937 rng;

public:
    explicit DeckDealer(int cps);

    Card operator()();

private:
    void newDeck();
};