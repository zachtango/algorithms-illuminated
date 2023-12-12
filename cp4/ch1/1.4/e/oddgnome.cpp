#include <iostream>

int main() {
    
    int n;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int g;
        std::cin >> g;

        int prevGnome, currGnome, nextGnome;

        std::cin >> prevGnome >> currGnome;

        for (int j = 0; j < g - 2; j++) {
            std::cin >> nextGnome;

            if ( (currGnome > prevGnome && currGnome > nextGnome && nextGnome > prevGnome) ||
                (currGnome < prevGnome && currGnome < nextGnome && nextGnome > prevGnome)
            ) {
                std::cout << j + 2 << '\n';
            }

            prevGnome = currGnome;
            currGnome = nextGnome;
        }

    }

    return 0;
}