#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    int numSlugs = 0;
    int totalScore = 0;

    int score;
    for (int i = 0; i < n; i++) {
        std::cin >> score;

        if (score == -1) {
            continue;
        }

        numSlugs += 1;
        totalScore += score;
    }

    double slugPercentage = static_cast<double>(totalScore) / static_cast<double>(numSlugs);

    std::cout << std::fixed << std::setprecision(6) << slugPercentage << '\n';

    return 0;
}