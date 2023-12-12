#include <iostream>
#include <algorithm>

int main() {
    
    int leftTines, rightTines;

    std::cin >> leftTines >> rightTines;

    int maxTines = std::max(leftTines, rightTines);

    if (maxTines == 0) {
        std::cout << "Not a moose" << '\n';
    } else if (leftTines != rightTines) {
        std::cout << "Odd " << maxTines * 2 << '\n';
    } else {
        std::cout << "Even " << maxTines * 2 << '\n';
    }

    return 0;
}