#include <iostream>
#include <string>
#include <limits>
#include <sstream>

constexpr auto max_size = std::numeric_limits<std::streamsize>::max();

int main() {
    
    int n;
    std::cin >> n;

    int a, b;
    for (int i = 0; i < n; i++) {
        std::cin.ignore(1, '\n');
        // std::cout << "peek: " << std::cin.peek() << '\n';
        if ('P' == std::cin.peek()) {
            std::cin.ignore(max_size, '\n');
            std::cout << "skipped" << '\n';
            std::cin.putback('\n');
        } else {
            std::cin >> a;
            std::cin.ignore(1, '+');
            std::cin >> b;
            std::cout << a + b << '\n';
        }
    }

    return 0;
}