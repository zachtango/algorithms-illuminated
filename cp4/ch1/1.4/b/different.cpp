#include <iostream>
#include <cmath>

int main() {

    long long a, b;
    while (std::cin >> a >> b) {
        long long d = std::abs(a - b);

        std::cout << d << '\n';
    }
    

    return 0;
}