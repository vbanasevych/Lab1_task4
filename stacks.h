#pragma once

#include <vector>
#include <map>

using namespace std;

class StackAnalyzer {

    int cardsPerSuit;
    int n; // кількість карт для роздачі
    vector<int> stackLengths;

    double average() const;
    double median() const;
    int mode() const;
    map<int, double> frequency() const; // довжина стопки в %

public:
    StackAnalyzer(int cardsPerSuit, int n);

    void dealAndAnalyze(); // формує стопки і зберігає їхні довжини
    void printStatistics() const;
    void experiment(const vector<int>& cardsPerSuitValues, int n);

    double getAverage() const { return average(); }
    double getMedian() const { return median(); }
    int getMode() const { return mode(); }


};