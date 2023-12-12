#include <iostream>


int main() {
    /*
        only buy treasure and victory point cards

        3 kinds of victory cards:
        - province costs 8, worth 6 victory points
        - duchy costs 5, worth 3 victory points
        - estate costs 2, worth 1 victory point
        3 kinds of treasure cards
        - gold costs 6, worth 3 buying power
        - silver costs 3, worth 2 buying power
        - copper costs 0, worth 1 buying power

    */

    int g, s, c;

    std::cin >> g >> s >> c;

    int buyingPower = g * 3 + s * 2 + c;

    if (buyingPower >= 8) {
        std::cout << "Province or Gold" << '\n';
    } else if (buyingPower >= 6) {
        std::cout << "Duchy or Gold" << '\n';
    } else if (buyingPower >= 5) {
        std::cout << "Duchy or Silver" << '\n';
    } else if (buyingPower >= 3) {
        std::cout << "Estate or Silver" << '\n';
    } else if (buyingPower >= 2) {
        std::cout << "Estate or Copper" << '\n';
    } else {
        std::cout << "Copper" << '\n';
    }

    return 0;
}