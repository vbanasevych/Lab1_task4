#include "deck_dealer.h"
#include <algorithm>
#include <stdexcept>

DeckDealer::DeckDealer(int cps) : cardsPerSuit(cps), index(0) {
    if (cardsPerSuit <= 0) {
        throw std::invalid_argument("cardsPerSuit must be > 0");
    }
    std::random_device rd;
    rng = std::mt19937(rd());
    newDeck();
}

Card DeckDealer::operator()() {
    if (index >= deck.size()) {
        newDeck();
    }
    return deck[index++];
}

void DeckDealer::newDeck() {
    deck.clear();
    for (int v = 1; v <= cardsPerSuit; ++v) {
        deck.push_back({Suit::Hearts, v});
        deck.push_back({Suit::Diamonds, v});
        deck.push_back({Suit::Clubs, v});
        deck.push_back({Suit::Spades, v});
    }
    std::shuffle(deck.begin(), deck.end(), rng);
    index = 0;
}
