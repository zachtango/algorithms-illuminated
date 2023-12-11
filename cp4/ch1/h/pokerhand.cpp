#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

int main() {
    
    std::unordered_map<char, int> frequency;
    std::string hand;

    int strength = 0;
    for (int i = 0; i < 5; i++) {
        std::cin >> hand;
        frequency[hand[0]] += 1;

        strength = std::max(strength, frequency[hand[0]]);
    }

    std::cout << strength << '\n';

    return 0;
}