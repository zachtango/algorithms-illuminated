#include <iostream>

int main() {
    
    int n;
    
    std::cin >> n;

    double qaly, periodLength;
    double accumulatedQaly = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> qaly >> periodLength;

        accumulatedQaly += qaly * periodLength;
    }

    std::cout << accumulatedQaly << '\n';

    return 0;
}
