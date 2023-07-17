#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

typedef vector<vector<int>> al;
typedef vector<int> cc;
typedef vector<cc> ccs;

/*
    I finished reading over Computing Connected Components section (8.3)

    GPT Questions:
    1. Write a C++ function computeConnectedComponents that takes an undirected graph represented using an adjacency list and
        returns a vector of vectors, where each inner vector represents a connected component. Test the function with a sample graph.

    2. Implement a C++ function printConnectedComponents that takes a vector of vectors representing connected components and prints each component on a separate line.
        Test the function with a sample connected component.

    3. Modify the computeConnectedComponents function to also return the number of connected components found. Update the test cases accordingly.

    4. Write a C++ function findLargestComponent that takes a vector of vectors representing connected components and returns the largest component (the one with the most vertices).
        Test the function with a sample connected component.

    5. Modify the computeConnectedComponents function to use depth-first search instead of breadth-first search. Update the test cases and compare the results with the previous implementation.
*/

/*
    1. Write a C++ function computeConnectedComponents that takes an undirected graph represented using an adjacency list and
        returns a vector of vectors, where each inner vector represents a connected component. Test the function with a sample graph.
*/
ccs computeConnectedComponentsBFS(const al &graph) {
    int n = graph.size();
    
    ccs ccs;
    unordered_set<int> visited;

    auto bfs = [&](int s) {
        ccs.push_back({});
        queue<int> q;

        q.push(s);
        visited.insert(s);

        while(!q.empty()) {
            int v = q.front();
            q.pop();

            for(const auto &x : graph[v]) {
                if(visited.count(x) == 1)
                    continue;
                q.push(x);
                visited.insert(x);
            }
            
            ccs[ccs.size() - 1].push_back(v);
        }
    };

    for(int v = 0; v < n; v++) {
        if(visited.count(v) == 1)
            continue;
        
        bfs(v);
    }

    return ccs;
}

/*
    2. Implement a C++ function printConnectedComponents that takes a vector of vectors representing connected components and prints each component on a separate line.
        Test the function with a sample connected component.
*/
void printConnectedComponents(const ccs &ccs) {
    cout << "Connected Components\n";

    for(const auto &cc : ccs) {
        for(const auto &x : cc)
            cout << x << ' ';
        cout << '\n';
    }        
}

// 3. Modify the computeConnectedComponents function to also return the number of connected components found. Update the test cases accordingly.
int numConnectedComponents(const al &graph) {
    return computeConnectedComponentsBFS(graph).size();
}

/*
    4. Write a C++ function findLargestComponent that takes a vector of vectors representing connected components and returns the largest component (the one with the most vertices).
        Test the function with a sample connected component.
*/
cc findLargestComponent(const ccs &ccs) {
    int largest = 0;

    for(int i = 0; i < ccs.size(); i++) {
        if(ccs[i].size() > ccs[largest].size())
            largest = i;
    }

    return ccs[largest];
}


// 5. Modify the computeConnectedComponents function to use depth-first search instead of breadth-first search. Update the test cases and compare the results with the previous implementation.
ccs computeConnectedComponentsDFS(const al &graph) {
    int n = graph.size();
    
    ccs ccs;
    unordered_set<int> visited;

    function<void(int)> dfs = [&](int s) {
        ccs[ccs.size() - 1].push_back(s);
        visited.insert(s);

        for(const auto &x : graph[s]) {
            if(visited.count(x) == 1)
                continue;
            dfs(x);
        }
    };

    for(int v = 0; v < n; v++) {
        if(visited.count(v) == 1)
            continue;
        
        ccs.push_back({});
        dfs(v);
    }

    return ccs;
}


int main() {
    
    // Test Case 1: computeConnectedComponentsBFS and computeConnectedComponentsDFS with graph1
    al graph1 = {
        {1, 2},
        {0, 2},
        {0, 1},
        {4, 5},
        {3},
        {3},
        {7, 8},
        {6},
        {6},
        {10},
        {9}
    };

    ccs connectedComponentsBFS1 = computeConnectedComponentsBFS(graph1);
    ccs connectedComponentsDFS1 = computeConnectedComponentsDFS(graph1);

    // Expected Connected Components (BFS):
    /*
    Connected Components
    0 1 2 
    3 4 5 
    6 7 8 
    9 10 
    */
    printConnectedComponents(connectedComponentsBFS1);

    // Expected Number of Connected Components (BFS): 4
    cout << "Number of Connected Components (BFS): " << numConnectedComponents(graph1) << endl;

    // Expected Connected Components (DFS):
    /*
    Connected Components
    0 1 2 
    3 4 5 
    6 7 8 
    9 10 
    */
    printConnectedComponents(connectedComponentsDFS1);

    // Expected Number of Connected Components (DFS): 4
    cout << "Number of Connected Components (DFS): " << numConnectedComponents(graph1) << endl;

    // Test Case 2: computeConnectedComponentsBFS and computeConnectedComponentsDFS with graph2
    al graph2 = {
        {1, 2},
        {0},
        {0},
        {4},
        {3},
        {},
        {}
    };

    ccs connectedComponentsBFS2 = computeConnectedComponentsBFS(graph2);
    ccs connectedComponentsDFS2 = computeConnectedComponentsDFS(graph2);

    // Expected Connected Components (BFS):
    /*
    Connected Components
    0 1 2 
    3 4 
    5 
    6 
    */
    printConnectedComponents(connectedComponentsBFS2);

    // Expected Number of Connected Components (BFS): 4
    cout << "Number of Connected Components (BFS): " << numConnectedComponents(graph2) << endl;

    // Expected Connected Components (DFS):
    /*
    Connected Components
    0 1 2 
    3 4 
    5 
    6 
    */
    printConnectedComponents(connectedComponentsDFS2);

    // Expected Number of Connected Components (DFS): 4
    cout << "Number of Connected Components (DFS): " << numConnectedComponents(graph2) << endl;

    // Test Case 3: findLargestComponent with connectedComponentsBFS1
    cc largestComponent = findLargestComponent(connectedComponentsBFS1);

    // Expected Largest Component: 0 1 2
    cout << "Largest Component: ";
    for (const auto& vertex : largestComponent) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}