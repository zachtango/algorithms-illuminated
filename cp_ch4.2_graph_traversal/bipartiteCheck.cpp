#include <vector>
using std::vector;
#include <utility>
using std::pair;
#include <queue>
using std::queue;

typedef vector<int> vi;
typedef vector<vector<pair<int, int>>> AL;

constexpr const int INF = 2;

/*
    Bipartite Graph is a special graph where the set of vertices V
        can be partitioned into 2 disjoint sets V1 and V2 such that all
        edges (u, v) in E have property u in V1 and v in V2
        - has no ODD LENGTH cycles
        - a tree is bipartite

    Check with 2 coloring
    Can use BFS or DFS, but BFS feels more natural

    BFS, alternate between 2 colors, if we encounter any violations
        we know it's not bipartite
*/

bool bfs(const AL &graph) {
    int n = graph.size();

    queue<int> q;
    q.push(0);
    
    vi color(n, INF); color[0] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (const auto &[v, w] : graph[u]) {
            if (color[v] == INF) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }

    return true;
}

