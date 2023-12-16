#include <iostream>

int main() {
    /*
        C, n
        num people left train, num people entered train, num people at station
    */

    int c, n;
    std::cin >> c >> n;

    int numPeople = 0;

    int left, enter, station;
    
    for (int i = 0; i < n; i++) {
        std::cin >> left >> enter >> station;

        numPeople -= left;

        if (numPeople < 0) {
            std::cout << "impossible" << '\n';
            return 0;
        }

        numPeople += enter;

        if (numPeople > c || (numPeople < c && station > 0) || (i == n - 1 && station > 0)) {
            std::cout << "impossible" << '\n';
            return 0;
        }
    }

    std::cout << (numPeople == 0 ? "possible" : "impossible") << '\n';

    return 0;
}
