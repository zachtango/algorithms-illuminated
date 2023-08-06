#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <stdexcept>
using std::runtime_error;
#include <algorithm>
using std::min;

typedef vector<vector<vector<int>>> al;

#define INF 10000000

// Graph is adjacency list (directed graph)
vector<vector<int>> bellmanFord(const al &graph, int s) {
    int n = graph.size();

    // Store edges (w, v) for all v to get access to all (w, v) for v in the algo
    al revGraph(n);

    for (int v = 0; v < n; v++) {
        for (auto &edge : graph[v]) {
            int neighbor = edge[0],
                weight = edge[1];

            revGraph[neighbor].push_back({v, weight});
        }
    }

    // Store length of shortest paths
    vector<vector<int>> L(n + 1, vector<int>(n));

    // Set base cases
    for (int neighbor = 0; neighbor < n; neighbor++) {
        L[0][neighbor] = INF;
    }
    for (auto &edge : graph[s]) {
        int neighbor = edge[0],
            weight = edge[1];
        
        L[0][neighbor] = weight;
    }
    L[0][s] = 0;

    // Bellman fords
    for (int i = 1; i <= n; i++) {
        for (int v = 0; v < n; v++) {
            L[i][v] = L[i - 1][v];

            for (auto &edge : revGraph[v]) {
                int neighbor = edge[0],
                    weight = edge[1];
                
                if (L[i - 1][neighbor] == INF) {
                    continue;
                }

                L[i][v] = min(L[i][v], L[i - 1][neighbor] + weight);
            }
        }
    }
    
    // Negative cycle check
    // Check if Ln,v == Ln - 1,v for all v
    for (int v = 0; v < n; v++) {
        if (L[n][v] != L[n - 1][v]) {
            throw runtime_error("Negative Cycle in Graph");
        }
    }

    return L;
}

void printShortestDistances(const std::vector<std::vector<int>>& result) {
    for (int i = 0; i < result.size() - 1; i++) {
        std::cout << "Step " << i << ":\n";
        for (int v = 0; v < result[i].size(); v++) {
            if (result[i][v] == INF) {
                std::cout << "To node " << v << ": " << "INF\n";
            } else {
                std::cout << "To node " << v << ": " << result[i][v] << "\n";
            }
        }
        std::cout << "\n";
    }
}

int main() {
    // Test Case 1: Simple graph with 3 nodes
    al graph1 = {
        { {{1, 3}} },
        { {{2, 2}} },
        { {{0, -4}}, {{1, 1}} }
    };
    int start_node1 = 0;
    std::cout << "Test Case 1: Simple graph with 3 nodes\n";
    std::vector<std::vector<int>> result1 = bellmanFord(graph1, start_node1);
    printShortestDistances(result1);
    std::cout << "\n";

    // Test Case 2: Graph with a negative cycle
    al graph2 = {
        { {{1, 1}} },
        { {{2, 2}} },
        { {{0, -6}}, {{1, -3}} }
    };
    int start_node2 = 0;
    std::cout << "Test Case 2: Graph with a negative cycle\n";
    try {
        std::vector<std::vector<int>> result2 = bellmanFord(graph2, start_node2);
        printShortestDistances(result2);
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    std::cout << "\n";

    // Test Case 3: Large graph
    al graph3 = {
        { {{1, 3}}, {{2, 5}}, {{3, 2}} },
        { {{2, 1}} },
        { {{3, 6}} },
        { }
    };
    int start_node3 = 0;
    std::cout << "Test Case 3: Large graph\n";
    std::vector<std::vector<int>> result3 = bellmanFord(graph3, start_node3);
    printShortestDistances(result3);
    std::cout << "\n";

    return 0;
}
