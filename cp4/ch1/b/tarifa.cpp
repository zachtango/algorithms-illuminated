#include <iostream>

int main() {
    /*
        X megabytes per month
            - carries over to next month if unused

        given megabytes used first N months
        how much megabytes available in N + 1 month?

        megabytes available = (N + 1) * X - sum of megabytes used in first N months
    */

    int X, N;
    int totalUsed = 0;
    
    std::cin >> X >> N;

    int monthUsed;
    for (int i = 0; i < N; i++) {
        std::cin >> monthUsed;
        totalUsed += monthUsed;
    }

    int megabytesAvailable = (N + 1) * X - totalUsed;

    std::cout << megabytesAvailable << '\n';

    return 0;
}