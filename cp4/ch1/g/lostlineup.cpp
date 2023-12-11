#include <iostream>
#include <vector>

int main() {
    int n;

    std::cin >> n;

    std::vector<int> order(n - 1);

    for (int i = 2; i <= n; i++) {
        int between;
        std::cin >> between;

        order[between] = i;
    }

    std::cout << 1 << ' ';

    for (auto p : order) {
        std::cout << p << ' ';
    }

    std::cout << '\n';

    return 0;
}