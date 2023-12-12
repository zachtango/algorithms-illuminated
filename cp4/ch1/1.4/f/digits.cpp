#include <iostream>
#include <string>

int main() {
    
    std::string x0;

    while (std::cin >> x0, x0 != "END") {
        if (x0 == "1") {
            std::cout << 1 << '\n';
            continue;
        }

        std::string xi = std::to_string(x0.size());
        int i = 1;
        while (xi != "1") {
            xi = std::to_string(xi.size());
            i += 1;
        }

        std::cout << i + 1 << '\n';
    }

    return 0;
}