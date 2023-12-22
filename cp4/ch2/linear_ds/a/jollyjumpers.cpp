#include <iostream>
#include <array>
#include <algorithm>

constexpr const int MAX_N {3000};


int main() {
    /*
        Sequence of n > 0 integers is jolly is absolute value between successive elements
        take all values 1 through n - 1
    */

    std::array<bool, MAX_N + 1> diffs;
    
    int n;
    while (std::cin >> n) {
        diffs.fill(false);
        
        int prev, curr;
        std::cin >> prev;
        for (int i = 0; i < n - 1; i++) {
            std::cin >> curr;
            
            int d = std::abs(curr - prev);

            if (d < n) {
                diffs[d] = true;
            }

            prev = curr;
        }
        
        bool jolly = true;
        for (int i = 1; i < n; i++) {
            if (!diffs[i]) {
                jolly = false;
                break;
            }
        }

        std::cout << (jolly ? "Jolly" : "Not jolly") << '\n';
    }

    return 0;
}