#include <iostream>
using std::cout;
using std::getline;
#include <vector>
using std::vector;
#include <unordered_set>
using std::unordered_set;
#include <fstream>
using std::ifstream;
#include <exception>
using std::runtime_error;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;

/*
    These questions are NOT GPT generated, they were provided at the end of the chapter

    Problem 9.1 Consider a directed graph G with distinct and nonnegative edge lengths.
    Let s be a starting vertex and t a destination vertex, and assume that G has at least
    one s-t path. Which of the following statements are true? (Choose all that apply.)
        a. The shortest (meaning minimum-length) s-t path might have as many as n - 1 edges, where n is the number of vertices.
            example: s --> t graph
                    then the shortest path is (s, t), where the edges == n - 1 == 2 - 1
        b. There is a shortest s-t path with no repeated vertices
            a shortest path can never have a cycle in this case because if there exists a cycle,
                then there's always a better path that does not include parts of the cycle
    
    Problem 9.2 (S) Consider a directed graph G with a starting vertex s, a destination t, and nonnegative edge lengths.
    Under what conditions is the shortest s-t path guaranteed to be unique?
        a. When all edge lengths are distinct positive integers.
        b. When all edge lengths are distinct powers of 2.
        c. When all edge lengths are distinct positive integers and the
            graph G contains no directed cycles.

    Problem 9.3 (S) Consider a directed graph G with nonnegative edge
    lengths and two distinct vertices, s and t. Let P denote a shortest
    path from s to t. If we add 10 to the length of every edge in the
    graph, then: (Choose all that apply.)
        c. P might or might not remain a shortest s-t path (depending on
        the graph).

    Problem 9.4 Consider a directed graph G and a starting vertex s
    with the following properties: no edges enter the starting vertex s;
    edges that leave s have arbitrary (possibly negative) lengths; and
    all other edge lengths are nonnegative. Does Dijkstra’s algorithm
    correctly solve the single-source shortest path problem in this case?
    (Choose all that apply.)
        a) Yes, for all such inputs.
            Cycles with negative edges can't exist because of the constraint of starting vertex s having
                no incoming edges and the outgoing edges from s being the only negative edges.

            s -> x is negative, but x -> t is filled with nonnegative edges, which is why Djikstra's is still valid.

            Because there are no cycles with negative edges, and the only negative edges are from s -> x where x is incident to s,
                all such inputs work. 

    Problem 9.5 Consider a directed graph G and a starting vertex s.
    Suppose G has some negative edge lengths but no negative cycles,
    meaning G does not have a directed cycle in which the sum of its
    edge lengths is negative. Suppose you run Dijkstra’s algorithm on
    this input. Which of the following statements are true? (Choose all
    that apply.)
        c) Dijkstra’s algorithm always halts, but in some cases the shortestpath distances it computes will not all be correct.
            e.g. s --> x --> t
                    --> b --> t
                where (s, x) = -5 and (x, t) = -1
                        (s, b) = 1 and (b, t) = -5000
                    dist(s, t) = -6 if we ran the Djikstra's algo
    
    Problem 9.6 Continuing the previous problem, suppose now that
    the input graph G does contain a negative cycle, and also a path
    from the starting vertex s to this cycle. Suppose you run Dijkstra’s
    algorithm on this input. Which of the following statements are true?
    (Choose all that apply.)
        a) Dijkstra’s algorithm might loop forever.

    Problem 9.7 (S) Consider a directed graph G = (V,E) with nonnegative edge lengths and a starting vertex s. 
    Define the bottleneck of a path to be the maximum length of one of its edges (as opposed to
    the sum of the lengths of its edges). Show how to modify Dijkstra’s
    algorithm to compute, for each vertex v in V, the smallest bottleneck
    of any s-v path. Your algorithm should run in O(mn) time, where m
    and n denote the number of edges and vertices, respectively.
        1. Rather than get the minimum distance, we would define dist[v] as the minimum bottleneck of all paths to s - v.
        2. In each iteration of Djikstra's, we would then find the minimum bottlneck from (v, w) where v in visited and w not in visited
            dist[v] = min(dist[v], max(dist[u], weight(u, v)))
    
    Problem 9.8 Implement in your favorite programming language the
    Dijkstra algorithm from Section 9.2, and use it to solve the singlesource shortest path problem in different directed graphs. With
    the straightforward implementation in this chapter, what’s the size
    of the largest problem you can solve in five minutes or less? (See
    www.algorithmsilluminated.org for test cases and challenge data
    sets.)

    Given G = (V, E) and s

    dist[v] = infinity for v in V
    dist[s] = 0

    visited = {s}

    while there exists edge (v, w) where v in V and w not in V:
        edge = (v*, w*) such that dist[v*] + l(v*, w*) is minimized
        visited.add(w*)
        dist[w*] = dist[v*] + l(v*, w*)

    ANSWERS
        graph1.in:
            1 0
            2 1
            3 2
            4 3
            5 4
            6 4
            7 3
            8 2
        graph2.in:
            7 2599
            37 2610
            59 2947
            82 2052
            99 2367
            115 2399
            133 2029
            165 2442
            188 2505
            197 3068
*/

typedef vector<vector<vector<int>>> al;

vector<int> minEdge(const al &graph, const unordered_set<int> &visited, const vector<int> &dist) {
    int n = graph.size();

    int minV = -1;
    int minW = -1;
    int minDist = INT32_MAX;

    for (int v = 0; v < n; v++) {
        if (visited.count(v) == 0) {
            continue;
        }

        for (auto &p : graph[v]) {
            int w = p[0];

            if (visited.count(w) == 1) {
                continue;
            }

            int weight = p[1];
            int d = dist[v] + weight;

            if (d < minDist) {
                minDist = d;
                minV = v;
                minW = w;
            }
        }

    }

    return {minV, minW, minDist};
}

vector<int> djikstras(const al &graph, int s) {
    unordered_set<int> visited;
    int n = graph.size();

    vector<int> dist(n, INT32_MAX - 1000000);
    dist[s] = 0;

    visited.insert(s);

    for (;;) {
        vector<int> e = minEdge(graph, visited, dist);

        if (e[0] == -1) {
            break;
        }

        int v = e[0];
        int w = e[1];
        int minDist = e[2];

        dist[w] = minDist;

        visited.insert(w);
    }

    return dist;
}

al extractGraph(string fileName) {
    ifstream fin(fileName);
    if (!fin.is_open()) {
        throw runtime_error("Unable to open file " + fileName);
    }
    
    string line;
    al graph;

    while (getline(fin, line)) {
        istringstream iss(line);
        graph.push_back({});

        int v;
        iss >> v;

        int w;
        while (iss >> w) {
            char c;
            int weight;

            iss >> c >> weight;
            
            graph[v - 1].push_back({w - 1, weight});
        }
    }

    return graph;
}

int main() {
    
    al graph = extractGraph("graph1.in");

    int v = 0;

    vector<int> dist = djikstras(graph, 0);

    v = 0;
    for (auto &d : dist) {
        v += 1;

        cout << v << ' ' << d << '\n';
    }

    return 0;
}