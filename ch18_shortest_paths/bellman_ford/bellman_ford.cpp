#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <stdexcept>
using std::runtime_error;
#include <algorithm>
using std::min;
using std::reverse;

typedef vector<vector<vector<int>>> al;

#define INF 10000000

al reverseGraph(const al &graph) {
    int n = graph.size();

    al revGraph(n);

    for (int v = 0; v < n; v++) {
        for (auto &edge : graph[v]) {
            int neighbor = edge[0],
                weight = edge[1];

            revGraph[neighbor].push_back({v, weight});
        }
    }

    return revGraph;
}

// Graph is adjacency list (directed graph)
vector<vector<int>> bellmanFord(const al &graph, int s) {
    int n = graph.size();

    // Store edges (w, v) for all v to get access to all (w, v) for v in the algo
    al revGraph = reverseGraph(graph);

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

vector<vector<int>> reconstruction(const al &graph, int s, const vector<vector<int>> &L) {
    int n = graph.size();

    al revGraph = reverseGraph(graph);

    // Hold paths from s to v
    vector<vector<int>> paths(n);

    for (int v = 0; v < n; v++) {
        paths[v].push_back(v);

        for (int i = n - 1; i > 0; i--) {
            int w = *paths[v].rbegin();
            int minL = L[i - 1][w];

            int k = -1;
            for (auto &edge : revGraph[w]) {
                int neighbor = edge[0],
                    weight = edge[1];
                
                if (minL > L[i - 1][neighbor] + weight) {
                    minL = L[i - 1][neighbor] + weight;
                    k = neighbor;
                }
            }

            if (k != -1) {
                paths[v].push_back(k);
            }
        }
    }

    for (int v = 0; v < n; v++) {
        paths[v].push_back(s);
        reverse(paths[v].begin(), paths[v].end());
    }

    return paths;
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

    // Reconstruct paths and print them
    std::vector<std::vector<int>> paths1 = reconstruction(graph1, start_node1, result1);
    std::cout << "\nReconstructed paths:\n";
    for (int v = 0; v < paths1.size(); v++) {
        std::cout << "To node " << v << ": ";
        for (int j = 0; j < paths1[v].size(); j++) {
            std::cout << paths1[v][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // Test Case 2: Graph with a negative cycle
    al graph2 = {
        { {{1, 1}} },
        { {{2, 2}} },
        { {{0, -6}, {1, -3}} }
    };
    int start_node2 = 0;
    std::cout << "Test Case 2: Graph with a negative cycle\n";
    try {
        std::vector<std::vector<int>> result2 = bellmanFord(graph2, start_node2);
        printShortestDistances(result2);

        // Reconstruct paths and print them
        std::vector<std::vector<int>> paths2 = reconstruction(graph2, start_node2, result2);
        std::cout << "\nReconstructed paths:\n";
        for (int v = 0; v < paths2.size(); v++) {
            std::cout << "To node " << v << ": ";
            for (int j = 0; j < paths2[v].size(); j++) {
                std::cout << paths2[v][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    // Test Case 3: Large graph
    al graph3 = {
        { {{1, 3}, {2, 5}, {3, 2}} },
        { {{2, 1}} },
        { {{3, 6}} },
        { }
    };
    int start_node3 = 0;
    std::cout << "Test Case 3: Large graph\n";
    std::vector<std::vector<int>> result3 = bellmanFord(graph3, start_node3);
    printShortestDistances(result3);

    // Reconstruct paths and print them
    std::vector<std::vector<int>> paths3 = reconstruction(graph3, start_node3, result3);
    std::cout << "\nReconstructed paths:\n";
    for (int v = 0; v < paths3.size(); v++) {
        std::cout << "To node " << v << ": ";
        for (int j = 0; j < paths3[v].size(); j++) {
            std::cout << paths3[v][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    return 0;
}
