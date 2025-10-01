// компідятор - g++

#include "stacks.h"
#include "deck_dealer.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    try {
        int cardsPerSuit = 7;
        int n = 20;

        cout << "=== Stack statistics test ===\n";
        StackAnalyzer analyzer(cardsPerSuit, n);

        analyzer.dealAndAnalyze();
        analyzer.printStatistics();

        vector<int> cpsValues = {5, 7, 10, 13};
        analyzer.experiment(cpsValues, n);

    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
        return 1;
    }

    return 0;
}