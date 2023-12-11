#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

int main() {
    /*
        N teas, M toppings

        N integers, price of each tea
        M integers, price of each topping

        ith of next N lines describes toppings that can be mixed with ith tea
            K followed by K integers, in range [1, M]
        
    */

    int N, M;

    std::cin >> N;
    int minTea = std::numeric_limits<int>::max();
    std::vector<int> tea(N);
    for (int i = 0; i < N; i++) {
        std::cin >> tea[i];
        minTea = std::min(minTea, tea[i]);
    }

    std::cin >> M;
    std::vector<int> topping(M);
    for (int i = 0; i < M; i++) {
        std::cin >> topping[i];
    }

    int minOrder = std::numeric_limits<int>::max();
    int K;
    int k;
    for (int i = 0; i < N; i++) {
        std::cin >> K;
        for (int j = 0; j < K; j++) {
            std::cin >> k;
            minOrder = std::min(minOrder, tea[i] + topping[k - 1]);
        }
    }

    int X;
    std::cin >> X;

    int canBuy = X / minOrder;

    if ( (X % minOrder) < minTea ) {
        canBuy -= 1;
    }

    std::cout << canBuy << '\n';
    
    return 0;
}