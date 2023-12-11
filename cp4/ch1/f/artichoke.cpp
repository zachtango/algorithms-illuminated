#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

double price(double p, double a, double b, double c, double d, double i) {
    return p * (std::sin(a * i + b) + std::cos(c * i + d) + 2);
}

int main() {

    /*
        price(k) = p * (sin(a * k + b) + cos(c * k + d) + 2)
        

    */

    int p, a, b, c, d, n;

    std::cin >> p >> a >> b >> c >> d >> n;

    double maxPrice = price(p, a, b, c, d, 1);
    double maxDecline = 0;

    for (int i = 2; i <= n; i++) {
        double currPrice = price(p, a, b, c, d, i);
        
        maxDecline = std::max(maxDecline, maxPrice - currPrice);
        maxPrice = std::max(maxPrice, currPrice);
    }

    if (maxDecline < 0) {
        std::cout << "0.00" << '\n';
    } else {
        std::cout << std::fixed << std::setprecision(6) << maxDecline << '\n';
    }

    return 0;
}