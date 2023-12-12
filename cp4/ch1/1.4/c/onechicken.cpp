#include <iostream>
#include <algorithm>
#include <string>

int main() {
    
    int n, m;

    std::cin >> n >> m;

    int p = std::abs(n - m);
    std::string s = (p == 1) ? "piece" : "pieces";

    if (m >= n) {
        std::cout << "Dr. Chaz will have " << p << ' ' << s << " of chicken left over!" << '\n';
    } else {
        std::cout << "Dr. Chaz needs " << p << " more " << s << " of chicken!" << '\n';
    }

    return 0;
}