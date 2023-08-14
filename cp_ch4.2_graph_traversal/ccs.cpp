#include <vector>
using std::vector;
#include <utility>
using std::pair;
#include <iostream>
using std::cout;

/*
    Connected Components in an Undirected Graph (Review Quizlet Vocab!)

    can use DFS or BFS to solve
*/

typedef vector<int> vi;
typedef vector<vector<pair<int, int>>> AL;

enum { UNVISITED, VISITED };
vi dfsNum;

void dfs(const AL &graph, int u) {
    dfsNum[u] = VISITED;

    for (const auto &[v, w] : graph[u]) {
        if (dfsNum[v] == VISITED) {
            continue;
        }
        dfs(graph, v);
    }
}

void ccs(const AL &graph, int V) {
    int numCC = 0;
    dfsNum.assign(V, UNVISITED);

    for (int u = 0; u < V; u++) {
        if (dfsNum[u] == VISITED) {
            continue;
        }
        cout << "CC " << u << ": ";
        dfs(graph, u);
        cout << '\n';
    }
    
    cout << "There are " << numCC << " connected components\n";
}
