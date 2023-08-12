#include <iostream>
using std::cin;
using std::cout;
#include <algorithm>
using std::max;
#include <deque>
using std::deque;

/*
    Classic Knapsack DP
*/

void solve(int *V, int *W, int n, int C) {
    
    int dp[n + 1][C + 1];
    bool chosen[n + 1][C + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = dp[i - 1][j];
            chosen[i][j] = false;

            if (j >= W[i - 1] && dp[i - 1][j - W[i - 1]] + V[i - 1] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - W[i - 1]] + V[i - 1];
                chosen[i][j] = true;
            }
        }
    }

    deque<int> items;

    int i = n, j = C;

    while (i > 0 && j > 0) {
        if (chosen[i][j]) {
            items.push_front(i - 1);
            j -= W[i - 1];
        }
        i -= 1;
    }

    cout << items.size() << '\n';
    for (auto &item : items) {
        cout << item << ' ';
    }
    cout << '\n';
}


int main() {

    int C, n;

    while (cin >> C) {
        cin >> n;

        int V[n], W[n];

        for (int i = 0; i < n; i++) {
            cin >> V[i] >> W[i];
        }

        solve(V, W, n, C);
    }

    return 0;
}


