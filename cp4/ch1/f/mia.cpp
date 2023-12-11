#include <iostream>

bool is12or21(int d1, int d2) {
    return (d1 == 1 && d2 == 2) || (d1 == 2 && d2 == 1);
}

bool isDouble(int d1, int d2) {
    return d1 == d2;
}

int getValue(int d1, int d2) {
    if (d1 > d2) {
        return d1 * 10 + d2;
    }
    return d2 * 10 + d1;
}

int main() {
    /*
        12 or 21 is always highest
        doubles next (ties broken by values)
        remaining rolls sorted such that highest number is first, compared by values
    */

    int s0, s1, r0, r1;

    while(std::cin >> s0 >> s1 >> r0 >> r1, s0 != 0) {
        bool tie = false;
        bool p1 = false;
        bool p2 = false;
        if (is12or21(s0, s1) && is12or21(r0, r1)) {
            tie = true;
        } else if (is12or21(s0, s1)) {
            p1 = true;
        } else if (is12or21(r0, r1)) {
            p2 = true;
        } else if (isDouble(s0, s1) && !isDouble(r0, r1)) {
            p1 = true;
        } else if (!isDouble(s0, s1) && isDouble(r0, r1)) {
            p2 = true;
        } else if (getValue(s0, s1) > getValue(r0, r1)) {
            p1 = true;
        } else if (getValue(s0, s1) < getValue(r0, r1)) {
            p2 = true;
        } else {
            tie = true;
        }

        if (tie) {
            std::cout << "Tie." << '\n';
        } else if (p1) {
            std::cout << "Player 1 wins." << '\n';
        } else {
            std::cout << "Player 2 wins." << '\n';
        }
    }

    return 0;
}