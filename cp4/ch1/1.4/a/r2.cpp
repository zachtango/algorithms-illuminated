#include <iostream>

int main() {
    /*
        S = (R1 + R2) / 2

        R2 = 2S - R1
    */

    int s, r1;

    std::cin >> r1 >> s;

    int r2 = 2 * s - r1;

    std::cout << r2 << '\n';

    return 0;
}