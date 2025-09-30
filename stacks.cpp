#include "stacks.h"
#include "deck_dealer.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

StackAnalyzer::StackAnalyzer(int cardsPerSuit, int n)
    : cardsPerSuit(cardsPerSuit), n(n) {
    if (cardsPerSuit < 0 || n < 0) {
        throw std::invalid_argument("cardsPerSuit and n must be positive");
    }
}

double StackAnalyzer::average() const {
    if (stackLengths.empty()) return 0.0;

    double sum = 0.0;
    for (auto len: stackLengths) {
        sum += len;
    }
    return sum / stackLengths.size();
}

double StackAnalyzer::median() const {
    if (stackLengths.empty()) return 0.0;

    std::vector<int> temp = stackLengths;
    std::sort(temp.begin(), temp.end());
    size_t mid = temp.size() / 2;

    if (temp.size() % 2 == 0) {
        return (temp[mid - 1] + temp[mid]) / 2.0;
    }
    return temp[mid];
}

int StackAnalyzer::mode() const {
    if (stackLengths.empty()) return 0;

    std::map<int, int> counts;
    for (auto len: stackLengths) {
        ++counts[len];
    }

    auto maxPair = std::max_element(
        counts.begin(),
        counts.end(),
        [](const auto &a, const auto &b) {
            return a.second < b.second;
        }
    );

    return maxPair->first;
}

std::map<int, double> StackAnalyzer::frequency() const {
    std::map<int, double> freq;

    if (stackLengths.empty()) return freq;

    std::map<int, int> counts;
    for (int len: stackLengths) {
        ++counts[len];
    }

    for (const auto &pair: counts) {
        freq[pair.first] = static_cast<double>(pair.second) * 100 / stackLengths.size();
    }

    return freq;
}

void StackAnalyzer::printStatistics() const {
    std::cout << "Average: " << average() << std::endl;
    std::cout << "Median: " << median() << std::endl;
    std::cout << "Mode: " << mode() << std::endl;
    std::cout << "Frequencies: " << std::endl;
    for (const auto &pair: frequency()) {
        std::cout << "Length " << pair.first << ": " << pair.second << "%\n";
    }
}

void StackAnalyzer::dealAndAnalyze() {
    if (n <= 0)
        throw runtime_error("Cannot deal cards: n <= 0");

    stackLengths.clear();
    DeckDealer dealer(cardsPerSuit);

    Card prevCard = dealer();
    int currentLength = 1;

    for (int i = 1; i < n; ++i) {
        Card nextCard = dealer();
        if (nextCard > prevCard) {
            ++currentLength;
        } else {
            stackLengths.push_back(currentLength);
            currentLength = 1;
        }
        prevCard = nextCard;
    }

    stackLengths.push_back(currentLength);
}

void StackAnalyzer::experiment(const std::vector<int> &cardsPerSuitValues, int n) {
    if (cardsPerSuitValues.empty())
        throw invalid_argument("cardsPerSuitValues cannot be empty");
    if (n <= 0)
        throw invalid_argument("n must be > 0");

    std::cout << "Experiment: effect of cards per suit on stack statistics" << std::endl;
    for (int cps: cardsPerSuitValues) {
        if (!cin) {
            cerr << "Cps must be a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (cps <= 0) {
            cerr << "Skipping invalid cardsPerSuit: " << cps << endl;
            continue;
        }
        std::cout << "Cards per suit: " << cps << std::endl;

        StackAnalyzer tempAnalyzer(cps, n);
        tempAnalyzer.dealAndAnalyze();

        std::cout << "Average length: " << tempAnalyzer.getAverage() << std::endl;
        std::cout << "Median length: " << tempAnalyzer.getMedian() << std::endl;

        auto freq = tempAnalyzer.frequency();
        std::cout << "Frequencies (%):" << std::endl;
        for (const auto &pair: freq) {
            std::cout << "Length " << pair.first << ": " << pair.second << "%\n";
        }
    }
}