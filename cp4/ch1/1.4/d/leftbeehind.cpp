#include <iostream>

int main() {
    /*
        x, y

        x + y == 13
        Never speak again
        x < y
        Left beehind
        x == y
        Undecided
        x > y
        To the convention
    */

    int x, y;

    while (std::cin >> x >> y, (x + y) != 0) {
        if ( (x + y) == 13 ) {
            std::cout << "Never speak again." << '\n';
        } else if (x < y) {
            std::cout << "Left beehind." << '\n';
        } else if (x == y) {
            std::cout << "Undecided." << '\n';
        } else {
            std::cout << "To the convention." << '\n';
        }
    }

    return 0;
}