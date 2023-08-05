#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::min;

typedef vector<vector<int>> am;

vector<vector<int>> bellman_ford(const am &graph, int s) {
    int n = graph.size();

    /*
        Case 1: Li - 1, v
        Case 2: Li - 1, k + weight(k, v)
    */
    vector<vector<int>> L(n + 1, vector<int>(n + 1));
    
    // Base case
    for (int v = 0; v < n; v++) {
        L[0][v] = graph[s][v];
    }

    // Recurrence
    for (int i = 1; i <= n; i++) {
        for(int v = 0;  v < n; v++) {
            L[i][v] = L[i - 1][v];

            for (int k = 0; k < n; k++) {
                L[i][v] = min(L[i][v], L[i - 1][k] + graph[k][v]);
            }
        }
    }

    return L;
}


int main() {
    


    return 0;
}

