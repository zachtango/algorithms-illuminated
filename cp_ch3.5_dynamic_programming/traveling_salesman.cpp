#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::min;
#include <functional>
using std::function;

int LSOne(int b) {
    return (b) & (-b);
}

/*
    Traveling Salesman Problem

    Given n cities (1 <= n <= 19) and their pairwise distances in the form of a matrix
    Output the minimum cost of making a tour that starts from any city s, goes through
        all the other n - 1 cities exactly once, and finally returns to the starting city s

*/

// O(n!) Complete Search
// Try all possible tours, fixing the first city to vertex 0

// O(2^(n - 1) * n^2) DP
int travelingSalesman(int **dist, int n) {
    /*
        Overlapping subproblems exist
            A-B-C-best sequence return to A
            A-C-B-best sequence return to A

        2 state parameters:
            1. last city / vertex visited v
            2. set of visited cities / vertices
            - use bitmask to represent set of visited cities (0 for visited)
    */

    vector<vector<int>> memo(n - 1, vector<int>( (1 << n) - 1 ));
    function<int(int, int)> dp = [&](int u, int mask) {
        if (mask == 0) {
            return dist[u][0];
        }

        int &ans = memo[u][mask];
        if (ans != -1) {
            return ans;
        }
        ans = (int) 1e9;
        int m = mask;
        while (m) {
            int twoPowerV = LSOne(m);
            int v = __builtin_ctz(twoPowerV) + 1; // offset by 1 because 0 isn't included in mask

            ans = min(ans, dist[u][v] + dp(v, mask ^ twoPowerV));

            m ^= twoPowerV;
        }

        return ans;
    };

    // Assume 0 is always visited
    int mask = (1 << n) - 1;

    return dp(0, mask);
}

int main() {

    return 0;
}
