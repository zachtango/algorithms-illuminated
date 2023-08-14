#include <vector>
using std::vector;
#include <utility>
using std::pair;
#include <algorithm>
using std::reverse;
#include <queue>
using std::priority_queue;

/*
    Top Sort (DAG)
    Linear ordering of vertices in the DAG so vertex u comes before vertex v if
        directed edge u --> v exists
    Every dag has at least one top sort and up to n!

    Several algos for Top Sort, but we use
        DFS variant
*/

typedef vector<int> vi;
typedef vector<vector<pair<int, int>>> AL;

enum { UNVISITED, VISITED };
vi dfsNum;
vi ts;

// DFS Variant
void topSort(int u, const AL &graph) {
    dfsNum[u] = VISITED;
    for (const auto &[v, w] : graph[u]) {
        if (dfsNum[v] == VISITED) {
            topSort(v, graph);
        }
    }
    ts.push_back(u);
}

// Kahn's Algo
void kahns() {
    int V;
    const AL graph;
    vi indegree(V);

    priority_queue<int> pq;
    for (int u = 0; u < V; u++) {
        if (indegree[u] != 0) {
            continue;
        }
        pq.push(u);
    }

    vi ts;
    while (!pq.empty()) {
        int u = pq.top(); pq.pop();

        for (const auto &[v, w] : graph[u]) {
            indegree[v] -= 1;
            if (indegree[v] > 0) {
                continue;
            }
            pq.push(v);
        }

        ts.push_back(u);
    }
}

int main() {
    int V = 10;
    AL graph;
    
    dfsNum.assign(V, UNVISITED);
    ts.clear();
    for (int u = 0; u < V; u++) {
        if (dfsNum[u] == UNVISITED) {
            topSort(u, graph);
        }
    }
    reverse(ts.begin(), ts.end());

    return 0;
}
