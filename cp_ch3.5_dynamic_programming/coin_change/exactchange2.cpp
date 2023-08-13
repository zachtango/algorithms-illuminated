#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::min;

/*
    multiple test casees

        each case begins w C, the item cost
            <= 10000
        n, indicating number of bills and coins you have
            <= 100
            
            n values <= 10000
            
            therefore, we only need to try for values up to 20000

    minimize amount you pay and number of coins or bills you pay out

*/

constexpr const int INF = 1e9;
constexpr const int MAX_N = 100;
constexpr const int MAX_T = 20000;
int memo[MAX_N + 1][MAX_T + 1];

void solve(vector<int> &coins, int n, int t) {

    int bestV = INF;
    int bestC = INF;
    for (int i = 0; i <= n; i++) {
        for (int v = 0; v <= MAX_T; v++) {
            if (v == 0) {
                memo[i][v] = 0;
                continue;
            }
            if (i == 0) {
                memo[i][v] = INF;
                continue;
            }

            memo[i][v] = memo[i - 1][v];

            if (v >= coins[i - 1]) {
                memo[i][v] = min(
                    memo[i - 1][v], // don't use coin
                    memo[i - 1][v - coins[i - 1]] + 1 // use coin
                );
            }

            if (v >= t && memo[i][v] != INF &&
                (v < bestV || (v == bestV && memo[i][v] < bestC))
             ) {
                bestV = v;
                bestC = memo[i][v];
            }
        }
    }
    cout << bestV << ' ' << bestC << '\n';
}

int main() {

    int t;

    cin >> t;

    while (t--) {
        int t, n;
        cin >> t >> n;
        vector<int> coins(n);
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        }

        solve(coins, n, t);
    }

    return 0;
}

