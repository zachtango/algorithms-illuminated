#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include <unordered_map>
using std::unordered_map;

/*
    m tiles, each labeled with positive integer

    you choose a target t

    your friend chooses n <= m tiles from the bag

    what is the probability the sum of the tiles is equal to t
        = number of different combinations of n that sum to t /
            total number of combinations of n tiles

    how do we calculate the number of different combos of n that sum to t
        try all possible different combos

        state, tile i, number of tiles, target t
            30 * 30 * 10000 states = 9000000

    meet in the middle technique
        split the tiles into 2
        
        calculate the subset sums of all subsets for the 2 bags
            2^15 subsets at most < 40000

        for each subset sum (x elements), see if t - sum w/ n - x elements
            is in the second bag
            40000

            keep track of the ones that match up --> get your count of the diff
                combos of n that sum to t

        200 * 80000
*/
typedef unordered_map<int, unordered_map<int, int>> table;
typedef long long ll;

constexpr const int MAX_M = 30;

int nCr(int n, int r) {
    double sum = 1;
    // Calculate the value of n choose r using the binomial coefficient formula
    for(int i = 1; i <= r; i++){
        sum = sum * (n - r + i) / i;
    }
    return (int) sum;
}

// value, number of elements, count (num ways)
table left;
table right;

vector<int> tiles;

// Brute force calculate all subset sums
void dfs(int i, int v, int end, int numElements, table &side) {
    if (i >= end) {
        side[v][numElements] += 1;
        return;
    }

    dfs(i + 1, v + tiles[i], end, numElements + 1, side);
    dfs(i + 1, v, end, numElements, side);
}

int main() {
    int g;
    cin >> g;

    for (int i = 1; i <= g; i++) {
        int m, n, t;

        cin >> m;
        
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            tiles.push_back(num);
        }

        cin >> n >> t;

        // Meet in the middle
        dfs(0, 0, m / 2, 0, left);
        dfs(m / 2, 0, m, 0, right);
        
        int numWays = 0;
        
        // Check if the sums to t add up and the num elements add up to n
        // for subsets of left and right
        for (auto &elem : left) {
            int value = elem.first;
            for (auto &elem : elem.second) {
                int numElements = elem.first;
                int count = elem.second;
                if (right.count(t - value) && right[t - value].count(n - numElements)) {
                    numWays += count * right[t - value][n - numElements];
                }
            }
        }
        
        int total = nCr(m, n);

        cout << "Game " << i << " -- " << numWays << " : " << total - numWays << '\n';

        tiles.clear();
        left.clear();
        right.clear();
    }

    return 0;
}
