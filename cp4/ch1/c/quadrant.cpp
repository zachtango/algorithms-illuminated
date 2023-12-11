#include <iostream>

int main() {
    /*
        x and y can't be 0
    */

    int x, y;

    std::cin >> x >> y;

    if (x > 0 && y > 0) {
        std::cout << 1 << '\n';
    } else if (x > 0 && y < 0) {
        std::cout << 4 << '\n';
    } else if (x < 0 && y > 0) {
        std::cout << 2 << '\n';
    } else {
        std::cout << 3 << '\n';
    }

    return 0;
}