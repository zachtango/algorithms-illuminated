#include <iostream>
using std::cout;
#include <algorithm>
using std::min;
#include <functional>
using std::function;
#include <vector>
using std::vector;

/*
    Coin Change Problem

    Given a target V cents and a list of denominations for n coins. Assume we may
        supply as many coins as possible
    Output the minimum number of coins we must use to represent V
*/

int coinChange(int *C, int n, int V) {
    int memo[V + 1];
    for (int i = 0; i <= V; i++) {
        memo[i] = -1;
    }

    function<int(int)> dp = [&](int v) {
        if (v == 0) {
            return 0;
        }

        if (v < 0) {
            return (int) 1e9;
        }

        int &ans = memo[v];
        if (ans != -1) {
            return ans;
        }
        ans = 1e9;

        for (int i = 0; i < n; i++) {
            ans = min(ans, dp(v - C[i]));
        }

        return ans;
    };

    return dp(V);
}

// Cointing number of ways to get to V variant
int coinChangeVariant(int *C, int n, int V) {
    vector<vector<int>> memo(n, vector<int>(V + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= V; j++) {
            memo[i][j] = -1;
        }
    }

    function<int(int, int)> dp = [&](int i, int v) {
        if (v == 0) {
            return 1;
        }

        if (v < 0) {
            return 0;
        }

        int &ans = memo[i][v];
        if (ans != -1) {
            return ans;
        }

        ans = dp(i, V - C[i]) + dp(i + 1, V);

        return ans;
    };

    return dp(0, V);
}

int main() {

    return 0;
}
