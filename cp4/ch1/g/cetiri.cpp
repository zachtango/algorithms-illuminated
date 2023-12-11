#include <iostream>
#include <algorithm>

int main() {
    
    int a[3];

    std::cin >> a[0] >> a[1] >> a[2];
    std::sort(a, a + 3);

    int d1 = a[1] - a[0];
    int d2 = a[2] - a[1];

    if (d1 == d2) {
        std::cout << a[2] + d1 << '\n';
    } else if (d1 > d2) {
        std::cout << a[0] + d1 / 2 << '\n';
    } else {
        std::cout << a[1] + d2 / 2 << '\n';
    }

    return 0;
}