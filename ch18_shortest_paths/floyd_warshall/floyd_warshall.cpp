#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::reverse;
using std::min;
#include <stdexcept>
using std::runtime_error;
#include <string>
using std::to_string;
#include <functional>
using std::function;

typedef vector<vector<vector<int>>> al;

#define INF 10000000


void printResult(const vector<vector<vector<int>>> &result) {
    int n = result.size() - 1;

    for (int k = 0; k <= n; k++) {
        cout << "k: " << k << '\n';
        for (int s = 1; s <= n; s++) {
            for (int v = 1; v <= n; v++) {
                if (result[k][s][v] == INF) {
                    cout << "INF ";
                } else {
                    cout << result[k][s][v] << ' ';
                }
            }
            cout << '\n';
        }
    }

    for (int s = 1; s <= n; s++) {
        cout << "s: " << s << '\n';
        for (int v = 1; v <= n; v++) {
            cout << v << ' ' << result[n][s][v] << '\n';
        }
        cout << '\n';
    }
}

void printPaths(const vector<vector<vector<int>>> &paths) {
    int n = paths.size() - 1;

    for (int s = 1; s <= n; s++) {
        for (int v = 1; v <= n; v++) {
            cout << s << " to " << v << ": ";
            for (auto &w : paths[s][v]) {
                cout << w << ' ';
            }
            cout << '\n';
        }
    }

}

// Input directed graph
vector<vector<vector<int>>> floydWarshall(const al &graph) {
    int n = graph.size() - 1;
    cout << "n: " << n << '\n';
    vector<vector<vector<int>>> L(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
    
    // Base cases
    for (int s = 1; s <= n; s++) {
        for (int v = 1; v <= n; v++) {
            if (s == v) {
                L[0][s][v] = 0;
            } else {
                L[0][s][v] = INF;
            }
        }   
    }
    for (int v = 1; v <= n; v++) {
        for (auto &edge : graph[v]) {
            int neighbor = edge[0],
                weight = edge[1];

            L[0][v][neighbor] = weight;
        }
    }

    // Recurrence
    for (int k = 1; k <= n; k++) {
        for (int s = 1; s <= n; s++) {
            for (int v = 1; v <= n; v++) {
                L[k][s][v] = min(L[k - 1][s][v], L[k - 1][s][k] + L[k - 1][k][v]);
            }
        }
    }

    // Check for negative cycle
    for (int k = 0; k <= n; k++) {
        for (int v = 1; v <= n; v++) {
            if (L[k][v][v] < 0) {
                throw runtime_error("Negative Cycle in Graph");
            }
        }
    }

    return L;
}

vector<vector<vector<int>>> reconstruction(const al &graph) {
    int n = graph.size() - 1;

    vector<vector<vector<int>>> L(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1)));
    
    // Base cases
    for (int s = 1; s <= n; s++) {
        for (int v = 1; v <= n; v++) {
            if (s == v) {
                L[0][s][v] = 0;
            } else {
                L[0][s][v] = INF;
            }
        }   
    }
    for (int v = 1; v <= n; v++) {
        for (auto &edge : graph[v]) {
            int neighbor = edge[0],
                weight = edge[1];

            L[0][v][neighbor] = weight;
        }
    }

    vector<vector<int>> B(n + 1, vector<int>(n + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            B[i][j] = -1;
        }
    }

    // Recurrence
    for (int k = 1; k <= n; k++) {
        for (int s = 1; s <= n; s++) {
            for (int v = 1; v <= n; v++) {
                if (L[k - 1][s][v] > L[k - 1][s][k] + L[k - 1][k][v]) {
                    L[k][s][v] = L[k - 1][s][k] + L[k - 1][k][v];
                    B[s][v] = k;
                } else {
                    L[k][s][v] = L[k - 1][s][v];
                }
            }
        }
    }

    // printResult(L);

    // Check for negative cycle
    for (int k = 0; k <= n; k++) {
        for (int v = 1; v <= n; v++) {
            if (L[k][v][v] < 0) {
                throw runtime_error("Negative Cycle in Graph");
            }
        }
    }

    vector<vector<vector<int>>> paths(n + 1, vector<vector<int>>(n + 1));

    for (int s = 1; s <= n; s++) {
        for (int v = 1; v <= n; v++) {
            cout << B[s][v] << ' ';
        }
        cout << '\n';
    }

    function<void(vector<int> &, int, int)> bestPath = [&bestPath, &B, &paths](vector<int> &path, int s, int v) {
        if (B[s][v] == -1) {
            return;
        }
        int w = B[s][v];

        bestPath(path, s, w);
        path.push_back(w);
        bestPath(path, w, v);
    };

    for (int s = 1; s <= n; s++) {
        for (int v = 1; v <= n; v++) {
            if (L[n][s][v] > INF - 10000) {
                continue;
            }

            paths[s][v] = {s};
            vector<int> p;
            bestPath(p, s, v);
            paths[s][v].insert(paths[s][v].end(), p.begin(), p.end());
            paths[s][v].push_back(v);
        }
    }

    return paths;
}

int main() {
    al graph1 = {
        {},                 // Dummy element to make the vertex indexing 1-based
        {{2, 3}, {3, 8}},   // Vertex 1: (2, 3) and (3, 8)
        {{3, 1}},           // Vertex 2: (3, 1)
        {{2, 4}}            // Vertex 3: (2, 4)
    };

    al graph2 = {
        {},
        {{2, 3}, {3, 8}},
        {{3, -1}},          // Negative weight edge
        {{2, 4}}
    };

    al graph3 = {
        {},
        {{2, 3}, {3, 8}},
        {{3, 1}, {4, 5}},   // Two paths from vertex 2 to vertex 3: 2 -> 3 and 2 -> 4 -> 3
        {{4, 2}},
        {{1, 1}}            // Path from vertex 4 to vertex 1: 4 -> 2 -> 1
    };

    al graph4 {
        {},
        {{1, -1}}
    };

    try {
        cout << "Result for Test Case 1:\n";
        vector<vector<vector<int>>> result1 = floydWarshall(graph1);

        vector<vector<vector<int>>> paths1 = reconstruction(graph1);
        printPaths(paths1);

        cout << "\nResult for Test Case 2:\n";
        vector<vector<vector<int>>> result2 = floydWarshall(graph2);
        vector<vector<vector<int>>> paths2 = reconstruction(graph2);
        printPaths(paths2);

        cout << "\nResult for Test Case 3:\n";
        vector<vector<vector<int>>> result3 = floydWarshall(graph3);
        vector<vector<vector<int>>> paths3 = reconstruction(graph3);
        printPaths(paths3);

        // cout << "\nResult for Test Case 4:\n";
        // floydWarshall(graph4);
    } catch (const std::runtime_error &e) {
        cout << e.what() << '\n'; // For any graph with a negative cycle
    }

    return 0;
}
