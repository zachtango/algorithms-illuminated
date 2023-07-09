#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef vector<vector<int>> al;

/*
    I finished reading over Topological Sort section (8.5)

    GPT Questions:
    1. Implement a C++ function to perform topological sort on a directed acyclic graph represented using an adjacency list. The function should return a vector containing the vertices in the topological order.

    2. Write a C++ function to check if a given directed graph, represented using an adjacency list, is a directed acyclic graph (DAG). Use topological sort to determine if the graph is a DAG.

    3. Given an adjacency list representation of a directed acyclic graph, write a C++ function to find the longest path from a given source vertex to any other vertex in the graph.

    4. Implement a C++ function to determine if there exists a valid topological ordering of a given directed graph, represented using an adjacency list.

    5. Write a C++ function to find the number of distinct topological orderings for a directed acyclic graph represented using an adjacency list.
*/

// 1. Implement a C++ function to perform topological sort on a directed acyclic graph represented using an adjacency list. The function should return a vector containing the vertices in the topological order.
vector<int> topSort(const al &dag) {
    int n = dag.size();

    vector<int> order(n);
    unordered_set<int> visited;

    int i = n - 1;
    function<void(int)> dfs = [&](int s) {        
        visited.insert(s);

        for(const auto &x : dag[s]) {
            if(visited.count(x) == 1)
                continue;
            dfs(x);
        }

        order[i] = s;
        i -= 1;
    };

    dfs(0);

    return order;
}


// 2. Write a C++ function to find all possible topological orderings of a directed acyclic graph represented using an adjacency list.
void allTopOrders(const al &dag) {
    int n = dag.size();

    int indegrees[n];
    bool visited[n];
    
    for(int x = 0; x < n; x++) {
        indegrees[x] = 0;
        visited[x] = false;
    }

    for(int v = 0; v < n; v++)
        for(const auto &x : dag[v])
            indegrees[x] += 1;
    
    function<void(int, vector<int>&)> dfs = [&](int s, vector<int> &order) {

        if(order.size() == n - 1) {
            for(const auto &x : order)
                cout << x << ' ';
            cout << s << '\n';

            return;
        }
        
        order.push_back(s);

        visited[s] = true;

        for(const auto &x : dag[s])
            indegrees[x] -= 1;

        for(int x = 0; x < n; x++)
            if(!visited[x] && indegrees[x] == 0)
                dfs(x, order);

        for(const auto &x : dag[s])
            indegrees[x] += 1;

        visited[s] = false;

        order.pop_back();
    };
    
    vector<int> order;
    for(int v = 0; v < n; v++)
        if(indegrees[v] == 0)
            dfs(v, order);
}

// 3. Write a C++ function to find the number of distinct topological orderings for a directed acyclic graph represented using an adjacency list.
int numTopOrders(const al &dag) {
    int n = dag.size();

    int indegrees[n];
    bool visited[n];
    
    for(int x = 0; x < n; x++) {
        indegrees[x] = 0;
        visited[x] = false;
    }

    for(int v = 0; v < n; v++)
        for(const auto &x : dag[v])
            indegrees[x] += 1;
    
    function<int(int, int)> dfs = [&](int s, int i) {
        if(i == n - 1)
            return 1;
        
        visited[s] = true;

        for(const auto &x : dag[s]) 
            indegrees[x] -= 1;

        int num = 0;
        for(int x = 0; x < n; x++)
            if(!visited[x] && indegrees[x] == 0)
                num += dfs(x, i + 1);

        for(const auto &x : dag[s]) 
            indegrees[x] += 1;

        visited[s] = false;

        return num;
    };
    
    int num = 0;
    vector<int> order;
    for(int v = 0; v < n; v++)
        if(indegrees[v] == 0)
            num += dfs(v, 0);

    return num;   
}


int main() {
    // Test case 1
    cout << "Test case 1:\n";
    al dag1 = {
        {1, 2, 3},
        {4},
        {4},
        {},
        {5},
        {}
    };

    cout << "Topological sort: ";
    vector<int> result1 = topSort(dag1);
    for (int vertex : result1) {
        cout << vertex << " ";
    }
    cout << endl;
    // Expected: 0 1 2 3 4 5

    cout << "All topological orderings:\n";
    allTopOrders(dag1);
    // Expected output: 10 different orderings

    cout << "Number of distinct topological orderings: " << numTopOrders(dag1) << endl;
    // Expected: 10

    // Test case 2
    cout << "Test case 2:\n";
    al dag2 = {
        {1},
        {2},
        {3},
        {}
    };

    cout << "Topological sort: ";
    vector<int> result2 = topSort(dag2);
    for (int vertex : result2) {
        cout << vertex << " ";
    }
    cout << endl;
    // Expected: 0 1 2 3

    cout << "All topological orderings:\n";
    allTopOrders(dag2);
    // Expected output: 1 ordering

    cout << "Number of distinct topological orderings: " << numTopOrders(dag2) << endl;
    // Expected: 1

    return 0;
}
