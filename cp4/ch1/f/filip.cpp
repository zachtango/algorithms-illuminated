#include <iostream>
#include <string>
#include <algorithm>

int main() {
    
    std::string a, b;

    std::cin >> a >> b;

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    int reverseA = std::stoi(a);
    int reverseB = std::stoi(b);

    std::cout << std::max(reverseA, reverseB) << '\n';

    return 0;
}