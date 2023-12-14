#include <iostream>
#include <string>

int getValue(const std::string &card, char dominantSuit) {
    bool dominant = card[1] == dominantSuit;
    switch (card[0]) {
        case 'A':
            return 11;
        case 'K':
            return 4;
        case 'Q':
            return 3;
        case 'J':
            return dominant ? 20 : 2;
        case 'T':
            return 10;
        case '9':
            return dominant ? 14 : 0;
        case '8':
        case '7':
        default:
            return 0;
    }
}

int main() {
    /*
        Add up all the hand values given the suit
    */
    int N;
    char S;

    std::cin >> N >> S;

    int totalValue = 0;
    std::string hand;
    for (int i = 0; i < 4 * N; i++) {
        std::cin >> hand;
        totalValue += getValue(hand, S);
    }

    std::cout << totalValue << '\n';

    return 0;
}