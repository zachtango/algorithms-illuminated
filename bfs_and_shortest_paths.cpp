#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

typedef vector<vector<int>> al;

/*
    I finished reading over BFS and Shortest Paths section (8.2)

    GPT Questions:
    1. Implement a function bfs in C++ that takes a graph represented using an adjacency list and a starting vertex as parameters.
        The function should perform a breadth-first search and print the vertices in the order they are visited.

    2. Modify the previous implementation to return a vector of integers containing the vertices visited in BFS order instead of printing them.

    3. Extend the previous implementation to compute and return the shortest-path distances from the starting vertex to all other vertices.
        The function should return a vector of integers where the index represents the vertex and the value represents the shortest-path distance from the starting vertex.

    4. Implement a function shortestPath that takes a graph represented using an adjacency matrix, a starting vertex, and an ending vertex as parameters.
        The function should use BFS to find the shortest path between the starting and ending vertices and return a vector of integers representing the path.

    5. Modify the previous implementation to return an empty vector if there is no path between the starting and ending vertices.
*/

/*
    1. Implement a function bfs in C++ that takes a graph represented using an adjacency list and a starting vertex as parameters.
        The function should perform a breadth-first search and print the vertices in the order they are visited.
*/
void bfs(const al &graph, int s) {

    int n = graph.size();

    queue<int> q;
    unordered_set<int> visited;

    q.push(s);
    visited.insert(s);

    cout << "BFS: ";
    while(!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << ' ';

        for(const auto &x : graph[v]) {
            if(visited.count(x) == 1)
                continue;
            
            visited.insert(x);
            q.push(x);
        }
    }
    cout << '\n';
}

// 2. Modify the previous implementation to return a vector of integers containing the vertices visited in BFS order instead of printing them.
vector<int> bfs2(const al &graph, int s) {

    int n = graph.size();

    queue<int> q;
    unordered_set<int> visited;
    vector<int> order;
    
    q.push(s);
    visited.insert(s);

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        order.push_back(v);

        for(const auto &x : graph[v]) {
            if(visited.count(x) == 1)
                continue;
            
            visited.insert(x);
            q.push(x);
        }
    }

    return order;
}

/*
    3. Extend the previous implementation to compute and return the shortest-path distances from the starting vertex to all other vertices.
        The function should return a vector of integers where the index represents the vertex and the value represents the shortest-path distance from the starting vertex.
*/
vector<int> bfs3(const al &graph, int s) {

    int n = graph.size();
    
    // dist(s, x)
    vector<int> dist(n);

    dist[s] = 0;

    queue<int> q;
    unordered_set<int> visited;

    q.push(s);
    visited.insert(s);

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(const auto &x : graph[v]) {
            if(visited.count(x) == 1)
                continue;
            
            visited.insert(x);
            q.push(x);
            dist[x] = dist[v] + 1;
        }
    }

    return dist;
}

/*
    4. Implement a function shortestPath that takes a graph represented using an adjacency matrix, a starting vertex, and an ending vertex as parameters.
        The function should use BFS to find the shortest path between the starting and ending vertices and return a vector of integers representing the path.
*/
vector<int> shortestPath(const al &graph, int s, int e) {
    int n = graph.size();

    // Stores next vertex in shortest path to vertex
    vector<int> nextVertex(n);

    queue<int> q;
    unordered_set<int> visited;

    q.push(s);
    visited.insert(s);

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        // Only need to find shortest path to e
        if(v == e) {
            nextVertex[e] = e;
            break;
        }

        for(const auto &x : graph[v]) {
            if(visited.count(x) == 1)
                continue;
            
            visited.insert(x);
            q.push(x);
            nextVertex[v] = x;
        }
    }

    // Generate shortest path from nextVertex
    vector<int> path {s};
    int v = s;

    do {
        v = nextVertex[v];
        path.push_back(v);
    } while(nextVertex[v] != v);

    return path;
}

// 5. Modify the previous implementation to return an empty vector if there is no path between the starting and ending vertices.
vector<int> shortestPath2(const al &graph, int s, int e) {
    int n = graph.size();

    // Stores next vertex in shortest path to vertex
    vector<int> nextVertex(n);

    queue<int> q;
    unordered_set<int> visited;

    q.push(s);
    visited.insert(s);

    bool pathExists = false;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        // Only need to find shortest path to e
        if(v == e) {
            nextVertex[e] = e;
            pathExists = true;
            break;
        }

        for(const auto &x : graph[v]) {
            if(visited.count(x) == 1)
                continue;
            
            visited.insert(x);
            q.push(x);
            nextVertex[v] = x;
        }
    }

    if(!pathExists)
        return {};

    // Generate shortest path from nextVertex
    vector<int> path;
    int v = s;

    do {
        path.push_back(v);
        v = nextVertex[v];
    } while(nextVertex[v] != v);

    return path;
}

void print(const vector<int> &v) {
    for(const auto &x : v)
        cout << x << ' ';
    cout << '\n';
}

int main() {

    al graph = {
        {1, 2},        // 0 -> 1, 2
        {0, 2, 3},     // 1 -> 0, 2, 3
        {0, 1, 3, 4},  // 2 -> 0, 1, 3, 4
        {1, 2, 4},     // 3 -> 1, 2, 4
        {2, 3}         // 4 -> 2, 3
    };
    int startVertex = 0;

    // Test BFS
    bfs(graph, startVertex);
    // Expected output: BFS: 0 1 2 3 4

    // Test BFS2
    vector<int> bfsOrder = bfs2(graph, startVertex);
    // Expected output: [0, 1, 2, 3, 4]
    print(bfsOrder);

    // Test BFS3
    vector<int> shortestDistances = bfs3(graph, startVertex);
    // Expected output: [0, 1, 1, 2, 2]
    print(shortestDistances);

    // Test Shortest Path
    int endVertex = 4;
    vector<int> path = shortestPath(graph, startVertex, endVertex);
    // Expected output: [0, 2, 4]
    print(path);

    // Test Shortest Path 2
    int nonExistingEndVertex = 5;
    vector<int> path2 = shortestPath2(graph, startVertex, nonExistingEndVertex);
    // Expected output: []
    print(path2);

    return 0;
}

