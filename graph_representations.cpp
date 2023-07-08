#include <iostream>
#include <vector>

using namespace std;

/*
    I finished reading over Representing a Graph Chapter Section of Algorithms Illuminated (Part 2).

    I asked Chat GPT to write me some questions that makes me apply the representations we talked about (adjacency list and matrix) in C++:

    Adjacency Matrix:
    a. Write a C++ function to create an adjacency matrix representation of an undirected graph given the number of vertices and a list of edges.
    b. Implement a function to check if there is an edge between two vertices in a graph represented by an adjacency matrix.
    c. Write a C++ function to add an edge between two vertices in a graph represented by an adjacency matrix.
    d. Implement a function to remove an edge between two vertices in a graph represented by an adjacency matrix.
    e. Write a C++ function to print the adjacency matrix representation of a graph.
    f. Implement a function to find the degree of a vertex in a graph represented by an adjacency matrix.

    Adjacency List:
    a. Write a C++ function to create an adjacency list representation of an undirected graph given the number of vertices and a list of edges.
    b. Implement a function to check if there is an edge between two vertices in a graph represented by an adjacency list.
    c. Write a C++ function to add an edge between two vertices in a graph represented by an adjacency list.
    d. Implement a function to remove an edge between two vertices in a graph represented by an adjacency list.
    e. Write a C++ function to print the adjacency list representation of a graph.
    f. Implement a function to find the degree of a vertex in a graph represented by an adjacency list.
*/

/* Abstract Graph */

class AbstractGraph {
public:
    virtual bool isEdge(int v, int w) = 0;
    virtual void addEdge(int v, int w) = 0;
    virtual void removeEdge(int v, int w) = 0;
    virtual void print() = 0;
    virtual int degree(int v) = 0;
};

/* Adjacency Matrix */

class AdjacencyMatrix : public AbstractGraph {
private:
    int **A;
    int n;

public:
    // a. Write a C++ function to create an adjacency matrix representation of an undirected graph given the number of vertices and a list of edges.
    AdjacencyMatrix(int n, const vector<vector<int>> &edges) {
        /*
            Aij = 1 if (i, j) in edges
            Aij = 0 otherwise
        */

        // Allocate memory to hold graph
        A = new int *[n];
        for(int i = 0; i < n; i++)
            A[i] = new int[n];

        // Set all Aij to 0 initially
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                A[i][j] = 0;

        // Set Aij to 1 if (i, j) in edges
        for(const auto &e : edges) {
            A[e[0]][e[1]] = 1;
            A[e[1]][e[0]] = 1;
        }

        this->n = n;
    }

    ~AdjacencyMatrix() {
        for(int i = 0; i < n; i++)
            delete[] A[i];
        delete A;
    }

    // b. Implement a function to check if there is an edge between two vertices in a graph represented by an adjacency matrix.
    bool isEdge(int v, int w) {
        return A[v][w];
    }

    // c. Write a C++ function to add an edge between two vertices in a graph represented by an adjacency matrix.
    void addEdge(int v, int w) {
        A[v][w] = 1;
        A[w][v] = 1;
    }

    // d. Implement a function to remove an edge between two vertices in a graph represented by an adjacency matrix.
    void removeEdge(int v, int w) {
        A[v][w] = 0;
        A[w][v] = 0;
    }

    // e. Write a C++ function to print the adjacency matrix representation of a graph.
    void print() {
        cout << "Adjacency Matrix Graph\n";
        for(int i = 0; i < n; i++) {
            cout << i << ": ";
            for(int j = 0; j < n; j++) {
                if(A[i][j])
                    cout << j << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    // f. Implement a function to find the degree of a vertex in a graph represented by an adjacency matrix.
    int degree(int v) {
        int d = 0;
        for(int i = 0; i < n; i++) {
            if(A[i][v])
                d += 1;
        }
        return d;
    }

};

/* Adjacency List */

class AdjacencyList : public AbstractGraph {
private:
    vector<vector<int>> A;
    int n;
public:
    // a. Write a C++ function to create an adjacency list representation of an undirected graph given the number of vertices and a list of edges.
    AdjacencyList(int n, const vector<vector<int>> &edges) {
        A.resize(n);

        for(const auto &e : edges) {
            A[e[0]].push_back(e[1]);
            A[e[1]].push_back(e[0]);
        }
        
        this->n = n;
    }

    // b. Implement a function to check if there is an edge between two vertices in a graph represented by an adjacency list.
    bool isEdge(int v, int w) {
        for(const auto &x : A[v])
            if(x == w) return true;
        
        return false;
    }

    // c. Write a C++ function to add an edge between two vertices in a graph represented by an adjacency list.
    void addEdge(int v, int w) {
        A[v].push_back(w);
        A[w].push_back(v);
    }

    // d. Implement a function to remove an edge between two vertices in a graph represented by an adjacency list.
    void removeEdge(int v, int w) {
        A[v].erase(find(A[v].begin(), A[v].end(), w));
        A[w].erase(find(A[w].begin(), A[w].end(), v));
    }

    // e. Write a C++ function to print the adjacency list representation of a graph.
    void print() {
        cout << "Adjacency List\n";
        for(int i = 0; i < n; i++) {
            cout << i << ": ";
            for(const auto &x : A[i])
                cout << x << ' ';
            cout << '\n';
        }
        cout << '\n';
    }

    // f. Implement a function to find the degree of a vertex in a graph represented by an adjacency list.
    int degree(int v) {
        return A[v].size();
    }
};

void test(AbstractGraph &graph) {
    // Tests produced by GPT
    cout << "Edge exists between 0 and 1: " << graph.isEdge(0, 1) << endl; // Expected output: 1
    cout << "Edge exists between 0 and 3: " << graph.isEdge(0, 3) << endl; // Expected output: 0

    graph.addEdge(0, 3);
    cout << "Edge exists between 0 and 3 after adding: " << graph.isEdge(0, 3) << endl; // Expected output: 1

    graph.removeEdge(0, 2);
    cout << "Edge exists between 0 and 2 after removal: " << graph.isEdge(0, 2) << endl; // Expected output: 0

    graph.print();

    int vertex = 3;
    int deg = graph.degree(vertex);
    cout << "Degree of vertex " << vertex << ": " << deg << endl; // Expected output: 3
}

int main() {

    int numVertices = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 4}};

    AdjacencyMatrix am(numVertices, edges);
    AdjacencyList al(numVertices, edges);

    test(am);
    test(al);

    return 0;
}

