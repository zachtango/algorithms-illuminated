#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

std::unordered_set<char> validChars {'0', '1', '6', '8', '9'};

std::string flip(std::string s) {
    std::string f(s);

    std::reverse(f.begin(), f.end());

    for (auto &c : f) {
        if (!validChars.count(c)) {
            return s;
        }
        if (c == '6') {
            c = '9';
        } else if (c == '9') {
            c = '6';
        }
    }

    return std::min(s, f);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> magnets;
    std::string line;
    for (int i = 0; i < n; i++) {
        std::cin >> line;

        magnets.push_back(flip(line));
    }

    std::sort(magnets.begin(), magnets.end(), [](const std::string &a, const std::string &b) {
        return a + b < b + a;
    });

    for (const auto &s : magnets) {
        std::cout << s;
    }
    std::cout << '\n';

    return 0;
}
