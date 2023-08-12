#include <iostream>
using std::cout;
using std::cin;

/*
    n, number of items on the menu
        - each item given by number
    m, number of orders placed
        - each order given by s, find if you can sum items to s

    this is more of a coin change variant... dunno why they said
        knapsack variant
*/

constexpr const int MAX_N = 100;
constexpr const int MAX_S = 30001;

int memo[MAX_N][MAX_S];
bool chosen[MAX_N][MAX_S];

int n;

int dfs(int *items, int i, int v) {
    if (v == 0) {
        return 1;
    }
    if (i >= n || v < 0) {
        return 0;
    }

    int &ans = memo[i][v];
    if (ans != -1) {
        return ans;
    }

    int skip = dfs(items, i + 1, v);
    int choose = dfs(items, i, v - items[i]);
    
    ans = skip + choose;

    if (ans > 2) {
        ans = 2;
    }

    if (choose > 0) {
        chosen[i][v] = true;
    } else {
        chosen[i][v] = false;
    }

    return ans;
}

void printOrder(int *items, int s) {
    int i = 0;
    while (s > 0) {
        if (chosen[i][s]) {
            cout << i + 1 << ' ';
            s -= items[i];
        } else {
            i += 1;
        }
    }
    cout << '\n';
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_S; j++) {
            memo[i][j] = -1;
        }
    }

    cin >> n;
    int items[n];
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        int numWays = dfs(items, 0, s);
        
        if (numWays > 1) {
            cout << "Ambiguous\n";
        } else if (numWays == 0) {
            cout << "Impossible\n";
        } else {
            printOrder(items, s);
        }
    }

    return 0;
}

