#include "../include/Edge.h"
#include <iostream>
using std::ostream;
using std::cout;
#include <vector>
using std::vector;
#include <queue>
using std::priority_queue;
#include <unordered_set>
using std::unordered_set;
#include <functional>
using std::function;
using std::greater;

typedef vector<vector<Edge>> al;

vector<Edge> prims(const al &graph) {
    if (graph.size() == 0) {
        return {};
    }

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    // Start with vertex 0
    unordered_set<int> visited {0};
    for (auto &e : graph[0]) {
        pq.push(e);
    }

    vector<Edge> mst;

    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();

        if (visited.count(e.b) == 1) {
            continue;
        }

        visited.insert(e.b);
        mst.push_back(e);

        for (auto &e : graph[e.b]) {
            pq.push(e);
        }

    }
    
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

    vector<Edge> result1 = prims(testGraph1);

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

    std::vector<Edge> result2 = prims(testGraph2);
    
    assert(result2 == expectedResult2);

    al testGraph3 = {
        {} // Only one vertex, no edges
    };

    vector<Edge> expectedResult3; // MST of a single vertex is an empty vector

    vector<Edge> result3 = prims(testGraph3);
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
    vector<Edge> expectedResults4[2] = {
        {Edge(0, 2, 3), Edge(2, 1, 1), Edge(3, 2, 2)},
        {Edge(0, 2, 3), Edge(1, 2, 1), Edge(3, 2, 2)}
    };

    vector<Edge> result4 = prims(testGraph4);
    assert(result4 == expectedResults4[0] || result4 == expectedResults4[1]);

    al testGraph5 = {
        {Edge(0, 1, 2), Edge(0, 2, 1)},
        {Edge(1, 0, 2), Edge(1, 2, -3)},
        {Edge(2, 0, 1), Edge(2, 1, -3)}
    };

    // The MST should be {Edge(0, 2, 1), Edge(1, 2, -3)}
    vector<Edge> expectedResult5 = {
        Edge(0, 2, 1), Edge(1, 2, -3)
    };

    vector<Edge> result5 = prims(testGraph5);
    assert(result5 == expectedResult5);

    return 0;
}

