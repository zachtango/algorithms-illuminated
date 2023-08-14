#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::min;
using std::abs;

/*
    
We are in the rectangular coordinate system
    Each location is identified by integer coordinates
    
    There are a set of beepers given on the coordinate system
    You have a starting position
    
    Goal is to find the shortest path from your starting position to
        each of the beepers and back to the starting position
    
    Can only move up or down (moving up or down is 1 cost)
        Therefore, the distance between two coords (x1, y1) and (x2, y2) is
            |x1 - x2| + |y1 - y2|
    
    The coordinate system is at most 20 x 20
    You have at most 10 beepers

    Given X and Y size of world
    Given x and y starting position
    n beepers
    next n lines have x and y

    1. Get all pair distances between all coords (beepers + starting pos)
    2. Fix the starting position
    3. Try all possible paths (n) and choose min
        - use Traveling Salesman DP to get best path
        - Recurrence is
            F(u, set of cities to visit) = 
                min (F(v, set of cities to visit - v))
                    for v in set of cities to visit
            Base case: set of cities to visit is none --> return d[u][0]
                return distance from current vertex back to starting vertex
*/

constexpr const int MAX_MASK = 2048,
                    MAX_N = 10,
                    INF = INT32_MAX;
// 2^10 = 1024 biggest mask possible
int memo[MAX_N + 1][MAX_MASK];
// MAX_N + 1 due to addition of starting coord
int dist[MAX_N + 1][MAX_N + 1];

struct Coord {
    int x, y;
};

int LSOne(int S) {
    return (S) & (-S);
}

void resetMemo() {
    for (int i = 0; i <= MAX_N; i++) {
        for (int j = 0; j < MAX_MASK; j++) {
            memo[i][j] = -1;
        }
    }
}

int dp(int u, int mask) {
    if (mask == 0) {
        return dist[u][0];
    }
    
    int &ans = memo[u][mask];
    if (ans != -1) {
        return ans;
    }
    ans = INF;
    int m = mask;
    while (m) {
        int twoPowerV = LSOne(m);
        // Get # trailing zeros, add 1 bc mask doesn't include starting vertex
        int v = __builtin_ctz(twoPowerV) + 1;
        
        ans = min(ans, dist[u][v] + dp(v, mask ^ twoPowerV));
        m ^= twoPowerV;
    }

    return ans;
}

int getDist(Coord a, Coord b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    
    int t;
    cin >> t;

    while (t--) {
        resetMemo();

        int X, Y;
        
        cin >> X >> Y;

        vector<Coord> coords(1);
        cin >> coords[0].x >> coords[0].y;

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            Coord coord;
            cin >> coord.x >> coord.y;
            coords.push_back(coord);
        }
        
        for (int i = 0; i <= n; i++) {
            dist[i][i] = 0;
            for (int j = i + 1; j <= n; j++) {
                dist[i][j] = dist[j][i] = getDist(coords[i], coords[j]);
            }
        }

        cout << dp(0, (1 << n) - 1) << '\n';
    }


    return 0;
}
