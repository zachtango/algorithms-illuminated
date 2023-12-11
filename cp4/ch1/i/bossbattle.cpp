#include <iostream>

int main() {
    /*
        n pillars

        1. throw bomb past one pillar, bomb defeats boss if it's behind the pillar or either of adjacent pillars
        2. boss may stay where it is or use its turn to move to a pillar adjacent
    */

    int n;

    std::cin >> n;

    // Simulated
    // int bomb = 0;
    // int boss = n - 1;

    // int numAttempts = 1;
    // while (true) {
    //     if ((boss == bomb) ||
    //         (boss == ((bomb + 1) % n)) ||
    //         (boss == ((bomb + 2) % n))) {
    //         std::cout << numAttempts << '\n';
    //         return 0;
    //     }
        
    //     numAttempts += 1;
        
    //     bomb += 2;
    //     boss += 1;

    //     bomb %= n;
    //     boss %= n;
    // }

    // Can just subtract 2 and get the right answer
    std::cout << (n > 2 ? (n - 2) : 1) << '\n';

    return 0;
}