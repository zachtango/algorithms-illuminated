#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    
    int n, k;
    std::string restaurant;
    std::string item;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        bool peaSoup = false;
        bool pancakes = false;

        std::cin >> k;
        std::cin.ignore(1, '\n');

        std::getline(std::cin, restaurant);

        for (int j = 0; j < k; j++) {
            std::getline(std::cin, item);
            if (item == "pea soup") {
                peaSoup = true;
            } else if (item == "pancakes") {
                pancakes = true;
            }
        }

        if (peaSoup && pancakes) {
            std::cout << restaurant << '\n';
            return 0;
        }
    }

    std::cout << "Anywhere is fine I guess" << '\n';

    return 0;
}