#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

int main() {
    /*
        Ingredients are vertices in a graph
        Ingredient pairs are edges in a graph

        Try to form a bipartite graph, if this is impossible, then an unsuspicious division is impossible
    */
    int n;
    std::cin >> n;

    std::vector<std::string> V(n);
    std::unordered_map<std::string, std::vector<std::string>> graph;
    std::unordered_map<std::string, int> color;
    std::string s;
    for (int i = 0; i < n; i++) {
        std::cin >> V[i];
    }

    int m;
    std::cin >> m;
    std::string a, b;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Color graph
    bool impossible = false;

    for (const auto &s : V) {
        if (color.count(s)) {
            continue;
        }

        std::queue<std::string> q;
        q.push(s);
        color[s] = 0;

        while (!impossible && q.size()) {
            std::string vertex = q.front();
            q.pop();

            int c =  1 - color[vertex];
            for (const auto &neighbor : graph[vertex]) {
                if (color.count(neighbor) && color[vertex] == color[neighbor]) {
                    impossible = true;
                    break;
                } else if (!color.count(neighbor)) {
                    color[neighbor] = c;
                    q.push(neighbor);
                }
            }
        }

        if (impossible) {
            break;
        }
    }

    if (impossible) {
        std::cout << "impossible" << '\n';
        return 0;
    }

    for (const auto &p : color) {
        if (p.second == 0) {
            std::cout << p.first << ' ';
        }
    }
    std::cout << '\n';
    for (const auto &p : color) {
        if (p.second == 1) {
            std::cout << p.first << ' ';
        }
    }
    std::cout << '\n';
    
    return 0;
}