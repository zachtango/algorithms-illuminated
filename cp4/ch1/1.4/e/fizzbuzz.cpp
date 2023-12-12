#include <iostream>

int main() {
    
    int x, y, n;

    std::cin >> x >> y >> n;


    for (int i = 1; i <= n; i++) {
        bool fizz = (i % x) == 0;
        bool buzz = (i % y) == 0;

        if (fizz && buzz) {
            std::cout << "FizzBuzz" << '\n';
        } else if (fizz) {
            std::cout << "Fizz" << '\n';
        } else if (buzz) {
            std::cout << "Buzz" << '\n';
        } else {
            std::cout << i << '\n';
        }
    }

    return 0;
}