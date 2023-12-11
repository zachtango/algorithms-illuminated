#include <iostream>

int main() {
    /*
        a easy, b medium, c hard
        exactly n problems with atleast 1 easy, 1 medium, and 1 hard
    */

    int a, b, c, n;

    std::cin >> a >> b >> c >> n;

    if (a >= 1 && b >= 1 && c >= 1 && n >= 3 && (a + b + c) >= n) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
    }

    
    return 0;
}