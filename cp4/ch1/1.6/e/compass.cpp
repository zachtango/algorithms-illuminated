#include <iostream>

int main() {
    int n1, n2;

    std::cin >> n1 >> n2;

    /*
        Try both directions, CW and CCW, choose minimum
    */

    int cwDistance;
    int ccwDistance;
    if (n1 > n2) {
        cwDistance = 360 - n1 + n2;
        ccwDistance = n1 - n2;
    } else {
        cwDistance = n2 - n1;
        ccwDistance = 360 - n2 + n1;
    }

    if (cwDistance <= ccwDistance) {
        std::cout << cwDistance << '\n';
    } else {
        std::cout << -ccwDistance << '\n';
    }

    return 0;
}