#include <iostream>
#include <vector>
#include <utility>

struct Node {
    int id;
    std::vector<std::pair<Node*, int>> neighbors;
    bool isLeaf;

    Node(int id) : id(id), isLeaf(false) {}
};

long long dfs(Node *node, Node *parent) {
    if (node->isLeaf && !node->neighbors.size()) {
        return 0;
    }

    if (!node->neighbors.size()) {
        return -1;
    }

    long long total = 0;
    bool hasLeaf = false;
    for (const auto &p : node->neighbors) {
        if (p.first == parent) {
            continue;
        }
        long long d = dfs(p.first, node);
        if (d >= 0) {
            // 2 * distance to node + amt to travel to eat all leaves from node
            total += 2 * p.second + d;
            hasLeaf = true;
        }
    }

    if (total == 0) {
        return hasLeaf || node->isLeaf ? 0 : -1;
    }

    return total;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
        Node* node = new Node(i);
        nodes[i] = node;
    }

    for (int i = 0; i < n - 1; i++) {
        int s, t, d;
        std::cin >> s >> t >> d;
        nodes[s]->neighbors.push_back({nodes[t], d});
        nodes[t]->neighbors.push_back({nodes[s], d});
    }

    for (int i = 0; i < k; i++) {
        int id;
        std::cin >> id;
        nodes[id]->isLeaf = true;
    }

    std::cout << dfs(nodes[0], nullptr) << '\n';

    return 0;
}