#include <iostream>
#include <string>

int main() {
    
    int n;
    std::cin >> n;
    
    std::string prev, curr;
    std::cin >> prev >> curr;

    bool increasing = curr > prev;
    prev = curr;
    for (int i = 0; i < n - 2; i++) {
        std::cin >> curr;

        if ((increasing && curr > prev) ||
            (!increasing && curr < prev)
        ) {
            prev = curr;
            continue;
        }

        std::cout << "NEITHER" << '\n';
        return 0;
    }

    std::cout << ( increasing ? "INCREASING" : "DECREASING" ) << '\n';

    return 0;
}