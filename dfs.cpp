#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

typedef vector<vector<int>> al;

/*
    I finished reading over DFS section (8.4)

    GPT Questions:
    1. Given an adjacency list representation of a graph, write a C++ function to perform DFS starting from a given vertex and print the vertices in the order they are explored.

    2. Implement a recursive version of DFS in C++ to traverse a graph and print the vertices as explored. Use an adjacency list representation for the graph.

    3. Write a C++ function to check if a directed graph contains a cycle using DFS. The graph is represented using an adjacency list.

    4. Given a directed acyclic graph (DAG) represented using an adjacency list, write a C++ function to perform topological sorting using DFS and print the vertices in the sorted order.

    5. Implement a C++ function to find the path between two vertices in an undirected graph using DFS. Print the path if it exists. The graph is represented using an adjacency list.
*/

// 1. Given an adjacency list representation of a graph, write a C++ function to perform DFS starting from a given vertex and print the vertices in the order they are explored.
void dfsIterative(const al &graph, int s) {
    int n = graph.size();

    stack<int> stk;
    unordered_set<int> visited;

    stk.push(s);
    visited.insert(s);

    cout << "DFS: ";
    while(!stk.empty()) {
        int v = stk.top();
        stk.pop();

        cout << v << ' ';

        for(const auto &x : graph[v]) {
            if(visited.count(x) == 1)
                continue;
            visited.insert(x);
            stk.push(x);
        }
    }
    cout << '\n';
}

// 2. Implement a recursive version of DFS in C++ to traverse a graph and print the vertices as explored. Use an adjacency list representation for the graph.
void dfsRecursive(const al &graph, int s) {
    
    unordered_set<int> visited;

    function<void(int)> dfs = [&](int s) {
        cout << s << ' ';

        visited.insert(s);

        for(const auto &x : graph[s]) {
            if(visited.count(x) == 1)
                continue;
            dfs(x);
        }
    };

    dfs(s);

    cout << '\n';
}

// 3. Write a C++ function to check if a directed graph contains a cycle using DFS. The graph is represented using an adjacency list.
bool hasCycle(const al &graph) {
    int n = graph.size();
    unordered_set<int> visited;

    function<bool(int)> dfs = [&](int s) {
        visited.insert(s);
        
        for(const auto &x : graph[s]) {
            if(visited.count(x) == 1 || dfs(x))
                return true;
        }
        
        return false;        
    };

    for(int v = 0; v < n; v++) {
        if(visited.count(v) == 0 && dfs(v))
            return true;
    }

    return false;
}

// 4. Given a directed acyclic graph (DAG) represented using an adjacency list, write a C++ function to perform topological sorting using DFS and print the vertices in the sorted order.
void topSort(const al &dag) {
    int n = dag.size();

    vector<int> order(n);
    unordered_set<int> visited;

    int i = n - 1;
    function<void(int s)> dfs = [&](int s) {
        visited.insert(s);

        for(const auto &x : dag[s]) {
            if(visited.count(x) == 1)
                continue;
            dfs(x);
        }
        
        order[i] = s;
        i -= 1;
    };
    
    for(int v = 0; v < n; v++) {
        if(visited.count(v) == 1)
            continue;
        dfs(v);
    }

    cout << "Top Sort: ";
    for(const auto &x : order)
        cout << x << ' ';
    cout << '\n';
}

// 5. Implement a C++ function to find the path between two vertices in an undirected graph using DFS. Print the path if it exists. The graph is represented using an adjacency list.
void findPath(const al &graph, int s, int e) {
    int n = graph.size();

    vector<int> nextVertex(n);
    unordered_set<int> visited;

    function<bool(int)> dfs = [&](int s) {
        if(s == e) {
            nextVertex[s] = e;
            return true;
        }

        visited.insert(s);

        for(const auto &x : graph[s]) {
            if(visited.count(x) == 1)
                continue;
            nextVertex[s] = x;
            if(dfs(x))
                return true;
        }

        return false;
    };

    if(dfs(s)) {
        int v = s;
        cout << "Path: " << v << ' ';
        do {
            v = nextVertex[v];
            cout << v << ' ';
        } while(nextVertex[v] != v);
        cout << '\n';
    } else {
        cout << "Path from " << s << " to " << e << " does not exist\n";
    }
}

int main() {

    // Test Case for dfsIterative
    al graph = {
        {1, 2},
        {0, 3, 4},
        {0, 4, 5},
        {1},
        {1, 2},
        {2}
    };
    cout << "DFS Iterative Test: ";
    dfsIterative(graph, 0);
    // Output: DFS: 0 2 5 4 1 3

    // Test Case for dfsRecursive
    cout << "DFS Recursive Test: ";
    dfsRecursive(graph, 0);
    // Output: 0 1 3 4 2 5

    // Test Case for hasCycles
    bool cycle = hasCycle(graph);
    cout << "Cycle Detection Test: ";
    cout << (cycle ? "The graph contains a cycle" : "The graph does not contain a cycle") << endl;
    // Output: The graph contains a cycle

    // Test Case for topSort
    al dag = {
        {1},
        {2, 3},
        {4, 5},
        {},
        {5},
        {}
    };
    cout << "Topological Sorting Test: ";
    topSort(dag);
    // Output: Top Sort: 0 1 3 2 4 5 or any other valid top sort

    // Test Case for findPath
    cout << "Find Path Test: ";
    findPath(graph, 0, 5);
    // Output: Path: 0 1 4 2 5 or any other valid path

    return 0;
}