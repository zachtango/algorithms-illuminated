#include <iostream>

int main() {

    int n;

    std::cin >> n;

    int x;
    for (int i = 0; i < n; i++) {
        std::cin >> x;

        if ( (x % 2) == 0 ) {
            std::cout << x << " is even" << '\n';
        } else {
            std::cout << x << " is odd" << '\n';
        }
    }

    return 0;
}