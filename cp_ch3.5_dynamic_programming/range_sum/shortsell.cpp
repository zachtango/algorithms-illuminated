#include <iostream>
using std::cout;
using std::cin;
#include <algorithm>
using std::max;

/*
    Given N stock prices, determine when max you can make from short selling 100 stock
        Convert N stock prices to N - 1 differences (subtract given K from difference)

    Reduces to the maximum subarray sum problem
        (subtract K from max to account for starting day)
*/
constexpr const int SHARES = 100;

void solve(int *D, int N, int K) {
    int maxSum = 0,
        sum = 0;

    for (int i = 0; i < N - 1; i++) {
        sum += D[i];
        
        maxSum = max(maxSum, sum - K);

        if (sum < 0) {
            sum = 0;
        }
    }

    cout << maxSum << '\n';
}


int main() {
    
    int N, K;

    cin >> N >> K;

    int D[N - 1];
    int lastElem;
    cin >> lastElem;

    for (int i = 0; i < N - 1; i++) {
        int elem;
        cin >> elem;
        
        D[i] = (lastElem - elem) * SHARES - K;

        lastElem = elem;
    }

    solve(D, N, K);

    return 0;
}

