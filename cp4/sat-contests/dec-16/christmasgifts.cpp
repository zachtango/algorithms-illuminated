#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

void removeEdge(std::unordered_map<int, std::unordered_set<int>> &graph, std::vector<int> &degree, int u, int v) {
    graph[u].erase(v);
    graph[v].erase(u);
    degree[u] -= 1;
    degree[v] -= 1;
}

int main() {
    /*
        maintain all odd degree vertices
            remove cycle as soon as found

        dfs until finding odd degree vertex, never have to backtrack
            if you couldn't, means u ended up at leaf but leaf is odd degree vertex
        

        even goal is to get back to where we started

        eliminate edges as you go
        
        euler cycle path (each edge is visited exactly once)

    */
    int s, f;
    std::cin >> s >> f;

    std::vector<int> degree(s + 1, 0);
    std::unordered_map<int, std::unordered_set<int>> graph;

    for (int i = 0; i < f; i++) {
        int a, b;
        std::cin >> a >> b;
        degree[a] += 1;
        degree[b] += 1;    
        graph[a].insert(b);
        graph[b].insert(a);    
    }

    std::unordered_set<int> oddVertices;
    std::unordered_set<int> evenVertices;

    for (int i = 1; i <= s; i++) {
        if (degree[i] % 2) {
            oddVertices.insert(i);
        } else if (degree[i] > 0) {
            evenVertices.insert(i);
        }
    }

    std::cout << oddVertices.size() << '\n';

    while (oddVertices.size()) {
        int u = *oddVertices.begin();
        int v = *graph[u].begin();

        oddVertices.erase(u);
        evenVertices.insert(u);
        
        std::cout << u << ' ' << v << '\n';

        while (!oddVertices.count(v)) {
            removeEdge(graph, degree, u, v);

            if (degree[u] == 0) {
                evenVertices.erase(u);
            }
            if (degree[v] == 0) {
                evenVertices.erase(v);
            }
            
            u = v;
            v = *graph[u].begin();

            std::cout << u << ' ' << v << '\n';
        }
        
        removeEdge(graph, degree, u, v);

        evenVertices.insert(v);
        if (degree[u] == 0) {
            evenVertices.erase(u);
        }
        if (degree[v] == 0) {
            evenVertices.erase(v);
        }

        oddVertices.erase(v);
    }

    while (evenVertices.size()) {
        int u = *evenVertices.begin();
        int v = *graph[u].begin();

        while (true) {
            removeEdge(graph, degree, u, v);
            
            std::cout << u << ' ' << v << '\n';

            if (degree[u] == 0) {
                evenVertices.erase(u);
            }
            if (degree[v] == 0) {
                evenVertices.erase(v);
                break;
            } else {
                u = v;
                v = *graph[u].begin();
            }
        }
    }

    return 0;
}