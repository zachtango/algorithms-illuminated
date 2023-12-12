#include <iostream>
#include <iomanip>

int main() {
    /*
        x and y
        x indicates point on B where A is 0
        y indicates number of degrees in B that equal a change of single degree in A

        x is not 0 and y is 1 --> IMPOSSIBLE
        x is 1 and y is 1 --> ALL GOOD

        B = y * A + x
        find where A == B

        A = y * A + x
        -x = (y - 1) * A
        A = -x / (y - 1)
    */

    int x, y;
    std::cin >> x >> y;

    if (x != 0 && y == 1) {
        std::cout << "IMPOSSIBLE" << '\n';
    } else if (x == 0 && y == 1) {
        std::cout << "ALL GOOD" << '\n';
    } else {
        double A = static_cast<double>(-x) / (static_cast<double>(y) - 1);
        std::cout << std::fixed << std::setprecision(6) << A << '\n';
    }

    return 0;
}