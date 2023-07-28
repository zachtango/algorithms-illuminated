#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::max;


int knapsack(vector<int> v, vector<int> s, int C) {
    
    /*
        Given items {1, 2, 3, ..., n} and capacity C
            A[0][x] = 0
            A[x][0] = 0
            A[i][c] = A[i - 1][c] if c < si
            A[i][c] = max(A[i - 1][c], A[i - 1][c - si] + vi) if c >= si
    */
    int n = v.size();
    
    int A[n + 1][C + 1];
    for (int i = 0; i <= n; i++) {
        for (int c = 0; c <= C; c++) {
            A[i][c] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int c = 1; c <= C; c++) {
            if (c < s[i - 1]) {
                A[i][c] = A[i - 1][c];
            } else {
                A[i][c] = max(A[i - 1][c],
                                A[i - 1][c - s[i - 1]] + v[i - 1]);
            }
        }
    }
    
    return A[n][C];
}

// Test function to check if the result matches the expected value
void testKnapsack(const vector<int>& values, const vector<int>& sizes, int capacity, int expected) {
    int result = knapsack(values, sizes, capacity);
    if (result == expected) {
        cout << "Test Passed: knapsack(";
        for (int i = 0; i < values.size(); ++i) {
            cout << "(" << values[i] << ", " << sizes[i] << ")";
            if (i != values.size() - 1) {
                cout << ", ";
            }
        }
        cout << ", " << capacity << ") = " << expected << "\n";
    } else {
        cout << "Test Failed: knapsack(";
        for (int i = 0; i < values.size(); ++i) {
            cout << "(" << values[i] << ", " << sizes[i] << ")";
            if (i != values.size() - 1) {
                cout << ", ";
            }
        }
        cout << ", " << capacity << ") returned " << result << ", expected " << expected << "\n";
    }
}

int main() {
    // Test Cases
    vector<int> values1 = {60, 100, 120};
    vector<int> sizes1 = {10, 20, 30};
    int capacity1 = 50;
    int expected1 = 220; // The maximum value is achieved by selecting items 2 and 3.
    testKnapsack(values1, sizes1, capacity1, expected1);

    vector<int> values2 = {30, 40, 50, 10, 20};
    vector<int> sizes2 = {5, 4, 10, 2, 3};
    int capacity2 = 15;
    int expected2 = 100; // The maximum value is achieved by selecting items 1, 2, 4, and 5
    testKnapsack(values2, sizes2, capacity2, expected2);

    // Add more test cases here...

    return 0;
}