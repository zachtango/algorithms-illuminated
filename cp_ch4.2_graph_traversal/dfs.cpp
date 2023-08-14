#include <vector>
using std::vector;
#include <utility>
using std::pair;

typedef vector<int> vi;
typedef vector<vector<pair<int, int>>> AL;

/*
    Time complexity depends on the graph being used:
        Adjacency Matrix, Adjacency List, Edge List

        AM - O(V) for checking neighbors
        AL - O(K) for checking neighbors (K is the number of neighbors)
        EL - O(E) for checking neighbors

        Therefore, the time complexities are
            O(V * V), O(max(V, E)) = O(V + E), O(VE)
        
        AL is the most efficient, so it might be beneficial to convert
            AM or EL to AL first
*/

enum { UNVISITED, VISITED };
vi dfsNum;

void dfs(int u, const AL &graph) {
    dfsNum[u] = VISITED;

    for (const auto &[v, w] : graph[u]) {
        if (dfsNum[v] == VISITED) {
            continue;
        }
        dfs(v, graph);
    }
}

/*
    Backtracking un flags visited vertices (reset state to prev state)
        when recursion backtracks --> no global dfsNum to keep track of visitation
    This runtime is exponential
    Backtracking explores all (up to V!) paths from source vertex
    DFS only explores one such path

void backtrack(state) {
    for (each neighbor of state) {
        if (neighbor is an end-state) {
            continue;
        }
        if (neighbor is an invalid-state) {
            continue;
        }
        backtrack(neighbor);
    }
}
*/

