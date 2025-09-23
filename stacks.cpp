#include "stacks.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

using namespace std;

StackAnalyzer::StackAnalyzer(int cardsPerSuit, int n)
    : cardsPerSuit(cardsPerSuit), n(n) {
    if (cardsPerSuit <= 0 || n <= 0) {
        throw invalid_argument("cardsPerSuit and n must be positive");
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

// Doxygen - для документації
double StackAnalyzer::median() const {
    if (stackLengths.empty()) return 0.0;

    vector<int> temp = stackLengths;
    sort(temp.begin(), temp.end());
    size_t mid = temp.size() / 2;

    if (temp.size() % 2 == 0) {
        return (temp[mid - 1] + temp[mid]) / 2.0;
    }
    return temp[mid];
}

int StackAnalyzer::mode() const {
    if (stackLengths.empty()) return 0;

    map<int, int> counts;
    for (auto len: stackLengths) ++counts[len];

    int maxCount = 0;
    int modeVal = 0;
    for (const auto &pair : counts) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            modeVal = pair.first;
        }
    }
    // використати std::max_element()
    return modeVal;
}

map<int, double> StackAnalyzer::frequency() const {
    map<int, double> freq;

    if (stackLengths.empty()) return freq;

    map<int, int> counts;
    for (int len : stackLengths) ++counts[len];

    for (auto [len, count]: counts) {
        freq[len] = static_cast<double>(count) * 100 / stackLengths.size();
    }

    return freq;
}
