#include <iostream>
#include <string>
#include <vector>

int main() {
    int n;
    
    while(std::cin >> n) {
        std::cin.ignore(1, '\n');

        std::vector<std::string> patterns(n);
        for (int i = 0; i < n; i++) {
            std::getline(std::cin, patterns[i]);
        }
        std::string text;
        std::getline(std::cin, text);

        for (int i = 0; i < n; i++) {
            size_t j = 0;

            while (j = text.find(patterns[i], j), j != std::string::npos) {
                std::cout << j << ' ';
                j += 1;
            }

            std::cout << '\n';
        }

    }

    return 0;
}