#include <iostream>
#include <vector>

int main() {

    std::vector<int> g;
    
    int n;
    std::cin >> n;

    int prevA, a;
    std::cin >> prevA;

    for (int i = 0; i < n - 1; i++) {
        std::cin >> a;
        if (a > prevA) {
            g.push_back(prevA);
            prevA = a;
        }
    }
    g.push_back(prevA);

    std::cout << g.size() << '\n';
    for (auto e : g) {
        std::cout << e << ' ';
    }
    std::cout << '\n';
    
    return 0;
}