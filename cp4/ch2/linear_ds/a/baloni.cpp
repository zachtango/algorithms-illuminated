#include <iostream>
#include <array>

constexpr const int MAX_H {1000000};

int main() {

    std::array<int, MAX_H + 1> arrows;
    arrows.fill(0);

    int n;
    std::cin >> n;

    int numArrows = 0;
    int h;
    for (int i = 0; i < n; i++) {
        std::cin >> h;
        if (arrows[h] > 0) {
            arrows[h] -= 1;
            arrows[h - 1] += 1;
        } else {
            arrows[h - 1] += 1;
            numArrows += 1;
        }
    }

    std::cout << numArrows << '\n';

    return 0;
}