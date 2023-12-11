#include <iostream>
#include <algorithm>

int main() {
    int n;
    int c = 1;

    while (std::cin >> n) {
        int minX, maxX, num;

        std::cin >> minX;

        maxX = minX;

        for (int i = 0; i < n - 1; i++) {
            std::cin >> num;
            minX = std::min(minX, num);
            maxX = std::max(maxX, num);
        }

        std::cout << "Case " << c << ": " << minX << ' ' << maxX << ' ' << maxX - minX << '\n';
        
        c += 1;
    }
    
    return 0;
}