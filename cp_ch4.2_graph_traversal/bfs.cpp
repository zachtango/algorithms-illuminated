#include <vector>
using std::vector;
#include <utility>
using std::pair;
#include <queue>
using std::queue;

/*
    BFS same time complexity as DFS
        AM - O(V^2)
        AL - O(V + E)
        EL - O(VE)
*/

typedef vector<int> vi;
typedef vector<vector<pair<int, int>>> AL;

constexpr const int INF = 1e9;

// Given graph, |V|, s (source vertex)
void bfs(const AL &graph, int V, int s) {

    vi dist(V, INF);
    dist[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto &[v, w] : graph[u]) {
            if (dist[v] != INF) {
                continue;
            }
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    
}


