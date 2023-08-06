#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::min;
#include <stdexcept>
using std::runtime_error;

typedef vector<vector<vector<int>>> al;

#define INF 10000000

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

void printResult(const vector<vector<vector<int>>>& result) {
    int n = result.size() - 1;

    for (int s = 1; s <= n; s++) {
        cout << "s: " << s << '\n';
        for (int v = 1; v <= n; v++) {
            cout << v << ' ' << result[n][s][v] << '\n';
        }
        cout << '\n';
    }
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
        printResult(result1);

        cout << "\nResult for Test Case 2:\n";
        vector<vector<vector<int>>> result2 = floydWarshall(graph2);
        printResult(result2);

        cout << "\nResult for Test Case 3:\n";
        vector<vector<vector<int>>> result3 = floydWarshall(graph3);
        printResult(result3);

        cout << "\nResult for Test Case 4:\n";
        floydWarshall(graph4);
    } catch (const std::runtime_error &e) {
        cout << e.what() << '\n'; // For any graph with a negative cycle
    }

    return 0;
}
