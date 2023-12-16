#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>
#include <cstdio>

int main() {
    
    std::vector<std::pair<char, char>> oneLeft {
        {'1', '`'},
        {'2', '1'},
        {'3', '2'},
        {'4', '3'},
        {'5', '4'},
        {'6', '5'},
        {'7', '6'},
        {'8', '7'},
        {'9', '8'},
        {'0', '9'},
        {'-', '0'},
        {'=', '-'},
        {'W', 'Q'},
        {'E', 'W'},
        {'R', 'E'},
        {'T', 'R'},
        {'Y', 'T'},
        {'U', 'Y'},
        {'I', 'U'},
        {'O', 'I'},
        {'P', 'O'},
        {'[', 'P'},
        {']', '['},
        {'\\', ']'},
        {'S', 'A'},
        {'D', 'S'},
        {'F', 'D'},
        {'G', 'F'},
        {'H', 'G'},
        {'J', 'H'},
        {'K', 'J'},
        {'L', 'K'},
        {';', 'L'},
        {'\'', ';'},
        {'X', 'Z'},
        {'C', 'X'},
        {'V', 'C'},
        {'B', 'V'},
        {'N', 'B'},
        {'M', 'N'},
        {',', 'M'},
        {'.', ','},
        {'/', '.'},
        {' ', ' '}
    };

    std::unordered_map<char, char> m;

    for (const auto &p : oneLeft) {
        m[p.first] = p.second;
    }

    std::string line;
    while (std::getline(std::cin, line)) {
        for (auto c : line) {
            std::cout << m[c];
        }
        std::cout << '\n';
    }

    return 0;
}