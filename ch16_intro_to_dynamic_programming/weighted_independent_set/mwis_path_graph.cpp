#include <vector>
using std::vector;
#include <algorithm>
using std::max;
#include <iostream>
using std::cout;


vector<int> mwis(vector<int> pathGraph) {
    int n = pathGraph.size();

    vector<int> W(n + 1);
    
    /*
        W0 = 0
        W1 = pathGraph[0]
        Wi = max(Wi - 1, Wi - 2 + pathGraph[i - 1]) for i = 2 to n
    */
    W[0] = 0;
    W[1] = pathGraph[0];
    for (int i = 2; i <= n; i++) {
        W[i] = max(W[i - 1], W[i - 2] + pathGraph[i - 1]);
    }

    // Reconstruction
    vector<int> s;
    int i = n;
    while (i >= 2) {
        if (W[i - 2] + pathGraph[i - 1] >= W[i - 1]) {
            s.push_back(i - 1);
            i -= 2;
        } else {
            i -= 1;
        }
    }

    if (i == 1 && n >= 1 && pathGraph[0] >= 0) {
        s.push_back(0);
    }

    return s;
}


int main() {

    // Test Case 1: Basic Case
    {
        vector<int> input = {1, 2, 3, 1, 5};
        vector<int> expected = {4, 2, 0};
        vector<int> result = mwis(input);

        assert(result == expected);
    }

    // Test Case 2: All Positive Weights
    {
        vector<int> input = {5, 10, 15, 20};
        vector<int> expected = {3, 1};
        vector<int> result = mwis(input);

        assert(result == expected);
    }

    // Test Case 3: All Negative Weights
    {
        vector<int> input = {-2, -5, -10, -1};
        vector<int> expected = {};
        vector<int> result = mwis(input);
    
        assert(result == expected);
    }

    // Test Case 4: Single Vertex
    {
        vector<int> input = {7};
        vector<int> expected = {0};
        vector<int> result = mwis(input);

        assert(result == expected);
    }

    // Test Case 5: Large Graph
    {
        // 3 + 2 + 8 + 10 = 23
        // 5 + 9 + 10 + 7 = 
        vector<int> input = {3, 5, 2, 9, 8, 6, 10, 2, 7};
        vector<int> expected = {8, 6, 3, 1};
        vector<int> result = mwis(input);

        assert(result == expected);
    }

    return 0;
}
