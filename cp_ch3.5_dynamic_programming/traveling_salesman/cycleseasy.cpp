#include <iostream>
using std::cin;
using std::cout;
#include <algorithm>
using std::min;

/*
    To count the number of hamiltonian cycles,
        we use TSP
        
        the state is u (current vertex) and mask (vertices available to visit)
        
        if there exists an edge between u and v, we recursively call with state v and mask - v

        base case is when mask is 0 --> we've reached a cycle and return 1
*/

constexpr const int MAX_N = 10,
                    TWO_POW_MAX_N = 1024,
                    INF = 2e9;

int dist[MAX_N][MAX_N];
int memo[MAX_N][TWO_POW_MAX_N];

void reset() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            dist[i][j] = 1;
        }
    }
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < TWO_POW_MAX_N; j++) {
            memo[i][j] = -1;
        }
    }
}

int LSOne(int S) {
    return S & -S;
}

int dp(int u, int mask) {
    if (mask == 0) {
        return dist[u][0] == 1;
    }

    int &ans = memo[u][mask];
    if (ans != -1) {
        return ans;
    }
    
    ans = 0;

    int m = mask;
    while (m) {
        int twoPowerV = LSOne(m);
        int v = __builtin_ctz(twoPowerV) + 1;

        if (dist[u][v] == 1) {
            ans += dp(v, mask ^ twoPowerV);
        }

        m ^= twoPowerV;
    }

    return ans;
}

int main() {

    int t, k, n;

    cin >> t;

    for (int i = 1; i <= t; i++) {
        reset();

        cin >> n >> k;
        while (k--) {
            int a, b;
            cin >> a >> b;
            dist[a - 1][b - 1] = 0;
            dist[b - 1][a - 1] = 0;
        }

        cout << "Case #" << i << ": " << (dp(0, (1 << (n - 1)) - 1) / 2) % 9901 << '\n';
    }


    return 0;
}

