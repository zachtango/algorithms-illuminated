#include <vector>
using std::vector;
#include <utility>
using std::pair;
#include <iostream>
using std::cout;

typedef vector<int> vi;
typedef vector<vector<pair<int, int>>> AL;

/*
    Cycle Check Directed Graph
    
    Using 3 states in our DFS traversal: EXPLORED, VISITED, UNVISITED
        We can classify edges into 3 types:
        1. Tree
        - edge that's part of DFS spanning tree
        - detect when move from vertex u with state EXPLORED to another vertex v
            with state UNVISITED
        2. Back / Bidirectional
        - edge that's part of a non-trivial or trivial cycle
        - detect when move from u EXPLORED to v EXPLORED
            which implies v is an ancestor of u in the DFS spanning tree
            if v is a direct parent of u in the tree, it's a trivial cycle
                otherwise it's a nontrivial cycle
        3. Forward / Cross
        - detect when u EXPLORED to v VISITED
*/

enum {VISITED, UNVISITED, EXPLORED};

vi dfsNum;
vi dfsParent;

void cycleCheck(int u, const AL &graph) {
    dfsNum[u] = EXPLORED;

    for (const auto &[v, w] : graph[u]) {
        if (dfsNum[v] == UNVISITED) {
            cout << "Tree Edge\n";
            dfsParent[v] = u;
            cycleCheck(v, graph);
        } else if (dfsNum[v] == EXPLORED) {
            if (dfsParent[u] == v) {
                cout << "Bidirectional Edge\n";
            } else {
                cout << "Back Edge\n";
            }
        } else {
            cout << "Forward Edge\n";
        }
    }

    dfsNum[u] = VISITED;
}

int main() {
    int V;
    AL graph;

    dfsNum.assign(V, UNVISITED);
    dfsParent.assign(V, -1);

    for (int u = 0; u < V; u++) {
        if (dfsNum[u] == UNVISITED) {
            cycleCheck(u, graph);
        }
    }

    return 0;
}

