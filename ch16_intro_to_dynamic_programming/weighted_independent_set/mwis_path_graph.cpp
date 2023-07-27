#include <vector>
using std::vector;
#include <algorithm>
using std::max;
#include <iostream>
using std::cout;


vector<int> mwis(vector<int> pathGraph) {
    int n = pathGraph.size();

    vector<int> W(n + 1);
    vector<int> prevV(n + 1);
    
    /*
        W0 = 0
        W1 = pathGraph[0]
        Wi = max(Wi - 1, Wi - 2 + pathGraph[i - 1]) for i = 2 to n
    */
    
    W[0] = 0;
    W[1] = pathGraph[0];
    prevV[0] = 0;
    prevV[1] = W[1] > 0 ? 1 : 0;

    for (int i = 2; i <= n; i++) {
        int a = W[i - 1];
        int b = W[i - 2] + pathGraph[i - 1];

        if (a > b) {
            W[i] = a;
            prevV[i] = i - 1;
        } else {
            W[i] = b;
            prevV[i] = i;
            cout << i << " set\n";
        }
    }

    vector<int> s;
    for (int i = n; i > 0; ) {
        if (prevV[i] == i) {
            s.push_back(i - 1);
            i -= 2;
        } else {
            i -= 1;
        }
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
        cout << "Case 3\n";
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

        for(auto &v : result) {
            cout << v << ' ';
        }
        cout << '\n';

        assert(result == expected);
    }

    return 0;
}
