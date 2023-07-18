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
#include <set>
using std::multiset;
#include <algorithm>
using std::min;

/*
    These questions are NOT GPT generated, they were provided at the end of the chapter

    Problem 10.1 (S) Which of the following patterns in a computer
    program suggests that a heap data structure could provide a significant
    speed-up? (Check all that apply.)
        b. Repeated minimum computations.
        c. Repeated maximum computations.

    Problem 10.2 Suppose you implement the functionality of a priority
    queue (that is, Insert and ExtractMin) using an array sorted from
    largest to smallest. What is the worst-case running time of Insert
    and ExtractMin, respectively? Assume you have a large enough
    array to accommodate all your insertions.
        d. O(n) and O(n)

    Problem 10.3 Suppose you implement the functionality of a priority
    queue (that is, Insert and ExtractMin) using an unsorted array.
    What is the worst-case running time of Insert and ExtractMin,
    respectively? Assume you have a large enough array to accommodate
    all your insertions.
        d. O(n) and O(n)

    Problem 10.4 (S) You are given a heap with n objects. Which of the
    following tasks can you solve using O(1) Insert and ExtractMin
    operations and O(1) additional work? (Choose all that apply.)
        b. Find the object stored in the heap with the maximum key.
            This is not using O(1) insert and ExtractMin operations (I'm not sure if that was a typo, but those are not the time complexitiies for a heap)

    
    Problem 10.8 Implement in your favorite programming language
    the heap-based version of the Dijkstra algorithm from Section 10.4,
    and use it to solve the single-source shortest path problem in different
    directed graphs. With this heap-based implementation, what’s the
    size of the largest problem you can solve in five minutes or less? (See
    www.algorithmsilluminated.org for test cases and challenge data
    sets.)

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

struct HeapCompare {
    const vector<int> &dist;
    bool operator()(int x, int y) const {
        return dist[x] < dist[y];
    }

    HeapCompare(const vector<int> &dist) : dist(dist) {}
};

vector<int> djikstras(const al &graph, int s) {
    unordered_set<int> visited;
    int n = graph.size();

    vector<int> dist(n, INT32_MAX - 1000000);
    dist[s] = 0;

    HeapCompare compare(dist);
    multiset<int, HeapCompare> heap(compare);

    for (int v = 0; v < n; v++) {
        heap.insert(v);
    }

    while (heap.size() > 0) {
        int w = *heap.begin();
        heap.erase(heap.begin());

        visited.insert(w);

        for (auto &neighbor : graph[w]) {
            int y = neighbor[0];

            if (visited.count(y) == 1) {
                continue;
            }

            int weight = neighbor[1];

            heap.erase(y);

            dist[y] = min(dist[y], dist[w] + weight);

            heap.insert(y);
        }
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
    al graph = extractGraph("graph2.in");

    int v = 0;

    vector<int> dist = djikstras(graph, 0);
    unordered_set<int> num { 7,37,59,82,99,115,133,165,188,197 };

    v = 0;
    for (auto &d : dist) {
        v += 1;
        if (num.count(v) == 0) {
            continue;
        }

        cout << v << ' ' << d << '\n';
    }

    return 0;
}