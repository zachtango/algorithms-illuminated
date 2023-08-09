#include <iostream>
using std::cout;
#include <algorithm>
using std::max;
#include <vector>
using std::vector;
#include <functional>
using std::function;


/*
    Knapsack problem

    Given n items, each with its own value Vi and weight Wi and a max knapsack size S
    Output the maximum value of items we can carry if we can either take or ignore an item

*/

// O(nS)
int knapsack(int *V, int *W, int n, int S) {
    
    vector<vector<int>> memo(n, vector<int>(S));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < S; j++) {
            memo[i][j] = -1;
        }
    }

    function<int(int, int)> dp = [&](int i, int w) {
        if (i == n || w == 0) {
            return 0;
        }

        int &ans = memo[i][w];
        if (ans != -1) {
            return ans;
        }
        
        if (w > W[i]) {
            ans = dp(i + 1, w - W[i]);
        }
        ans = max(ans, dp(i + 1, w));

        return ans;
    };

    return dp(0, S);
}


int main() {



    return 0;
}


