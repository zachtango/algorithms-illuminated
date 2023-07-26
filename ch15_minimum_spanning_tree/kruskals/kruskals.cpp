#include "../include/Edge.h"
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <unordered_set>
using std::unordered_set;
#include <algorithm>
using std::sort;
using std::copy;
#include <iterator>
using std::back_inserter;


typedef vector<vector<Edge>> al;

bool hasCycle(const al &graph, int v, int p, unordered_set<int> &visited) {
    visited.insert(v);

    for (const auto &e : graph[v]) {
        if (e.b == p) {
            continue;
        }
        if (visited.count(e.b) == 1 || hasCycle(graph, e.b, v, visited)) {
            return true;
        }
    }

    return false;
}

vector<Edge> kruskals(const al &graph) {
    int n = graph.size();
    
    vector<Edge> edges;
    for (int v = 0; v < n; v++) {
        for (auto &e : graph[v]) {
            edges.push_back({v, e.b, e.weight});
        }
    }
    sort(edges.begin(), edges.end());

    al T(n);
    unordered_set<int> visited;
    for (auto &e : edges) {
        T[e.a].push_back({e.a, e.b, e.weight});
        T[e.b].push_back({e.b, e.a, e.weight});

        if (hasCycle(T, e.a, -1, visited)) {
            T[e.a].pop_back();
            T[e.b].pop_back();
        }

        visited.clear();
    }

    set<Edge> Tedges;
    for (int v = 0; v < n; v++) {
        for (auto &e : T[v]) {
            Tedges.insert(e);
        }
    }

    vector<Edge> mst;
    copy(Tedges.begin(), Tedges.end(), back_inserter(mst));

    return mst;
}


int main() {
    al testGraph1 = {
        {Edge(0, 1, 5), Edge(0, 2, 3)},
        {Edge(1, 0, 5), Edge(1, 2, 1), Edge(1, 3, 4)},
        {Edge(2, 0, 3), Edge(2, 1, 1), Edge(2, 3, 2)},
        {Edge(3, 1, 4), Edge(3, 2, 2)}
    };

    vector<Edge> expectedResult1 = {
        Edge(0, 2, 3), Edge(2, 1, 1), Edge(3, 2, 2)
    };

    vector<Edge> result1 = kruskals(testGraph1);

    sort(expectedResult1.begin(), expectedResult1.end());
    sort(result1.begin(), result1.end());

    assert(result1 == expectedResult1);

    al testGraph2 = {
        {Edge(0, 1, 3)}, // Connected edge between vertices 0 and 1
        {Edge(1, 0, 3), Edge(1, 2, 4)}, // Connected edges between vertices 1 and 0, 1 and 2
        {Edge(2, 1, 4), Edge(2, 3, 5)}, // Connected edges between vertices 2 and 1, 2 and 3
        {Edge(3, 2, 5)}  // Connected edge between vertices 3 and 2
    };

    // The MST should be {Edge(0, 1, 3), Edge(1, 2, 4), Edge(2, 3, 5)}
    std::vector<Edge> expectedResult2 = {
        Edge(0, 1, 3), Edge(1, 2, 4), Edge(2, 3, 5)
    };
    
    vector<Edge> result2 = kruskals(testGraph2);

    sort(expectedResult2.begin(), expectedResult2.end());
    sort(result2.begin(), result2.end());

    assert(result2 == expectedResult2);

    al testGraph3 = {
        {} // Only one vertex, no edges
    };

    vector<Edge> expectedResult3; // MST of a single vertex is an empty vector

    vector<Edge> result3 = kruskals(testGraph3);
    assert(result3 == expectedResult3);

    al testGraph4 = {
        {Edge(0, 1, 4), Edge(0, 2, 3)},
        {Edge(1, 0, 4), Edge(1, 2, 1), Edge(1, 3, 4)},
        {Edge(2, 0, 3), Edge(2, 1, 1), Edge(2, 3, 2)},
        {Edge(3, 1, 4), Edge(3, 2, 2)}
    };

    // The MST should be one of the two possible solutions:
    // Solution 1: {Edge(0, 2, 3), Edge(2, 1, 1), Edge(3, 2, 2)}
    // Solution 2: {Edge(0, 2, 3), Edge(1, 2, 1), Edge(3, 2, 2)}
    vector<Edge> expectedResult4 = {
        Edge(0, 2, 3), Edge(2, 1, 1), Edge(3, 2, 2)
    };

    vector<Edge> result4 = kruskals(testGraph4);

    sort(expectedResult4.begin(), expectedResult4.end());
    sort(result4.begin(), result4.end());

    assert(result4 == expectedResult4);

    al testGraph5 = {
        {Edge(0, 1, 2), Edge(0, 2, 1)},
        {Edge(1, 0, 2), Edge(1, 2, -3)},
        {Edge(2, 0, 1), Edge(2, 1, -3)}
    };

    // The MST should be {Edge(0, 2, 1), Edge(1, 2, -3)}
    vector<Edge> expectedResult5 = {
        Edge(0, 2, 1), Edge(1, 2, -3)
    };

    vector<Edge> result5 = kruskals(testGraph5);

    sort(expectedResult5.begin(), expectedResult5.end());
    sort(result5.begin(), result5.end());
    
    assert(result5 == expectedResult5);

    return 0;
}

