#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::min;

/*
    Canonical if greedy soln gives you the least amount of coins to make up a combo
        non canonical otherwise

    Useful: if S is non-canonincal, the smallest counterexample is
        less than the sum of the two largest deonominations
    A denomination is a coin

    We need to compare the count of the coins used to get to all values
        less than sum of two largest denoms
        With the greedy approach

*/

constexpr const int MAX_N = 100;
constexpr const int MAX_TWO_DENOM = 2 * 1e6;
constexpr const int INF = 1e9;

// Store min count of coins to get to this val with dp approach
int dp[MAX_TWO_DENOM + 1];


bool isCanonical(vector<int> &coins, int n) {
    int maxTwoDenom = coins[n - 1] + coins[n - 2];

    dp[0] = 0;
    dp[1] = 1;

    for (int v = 2; v < maxTwoDenom; v++) {
        // DP
        dp[v] = INF;
        for (auto &coin : coins) {
            if (v >= coin) {
                dp[v] = min(dp[v], dp[v - coin] + 1);
            }
        }
        
        // GREEDY
        int accum = v;
        int i = n - 1;
        int numCoins = 0;
        while (accum > 0) {
            if (accum >= coins[i]) {
                numCoins += accum / coins[i];

                accum %= coins[i];
            }

            i -= 1;
        }
        
        if (dp[v] < numCoins) {
            return false;
        }
    }
    return true;
}

int main() {
    
    int n;
    cin >> n;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << (isCanonical(coins, n) ? "canonical\n" : "non-canonical\n");

    return 0;
}



