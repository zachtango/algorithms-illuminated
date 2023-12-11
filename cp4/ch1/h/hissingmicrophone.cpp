#include <iostream>

int main() {
    char prevChar;
    char currChar;

    bool hiss = false;

    std::cin >> prevChar;

    while (std::cin >> currChar) {
        if (prevChar == 's' && currChar == 's') {
            hiss = true;
        }
        prevChar = currChar;
    }

    std::cout << (hiss ? "hiss" : "no hiss") << '\n';

    return 0;
}