#include <iostream>
using std::cout;
using std::endl;
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

vector<int> knapsackReconstruction(vector<int> v, vector<int> s, int C) {
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

    // Reconstruction
    vector<int> K;
    int c = C;
    for (int i = n; i > 0; i--) {
        if (c >= s[i - 1] && A[i - 1][c - s[i - 1]] + v[i - 1] >= A[i - 1][c]) {
            c -= s[i - 1];
            K.push_back(i - 1);
        }
    }
    
    return K;
}


// Test function to check if the result matches the expected value

void runTestCases() {
    // Test Case 1
    vector<int> values1 = {60, 100, 120};
    vector<int> sizes1 = {10, 20, 30};
    int capacity1 = 50;
    int expectedValue1 = 220;
    int result1 = knapsack(values1, sizes1, capacity1);
    cout << "Test Case 1 - Expected: " << expectedValue1 << ", Result: " << result1 << endl;

    vector<int> expectedItems1 = {2, 1}; // Indices of selected items
    vector<int> resultItems1 = knapsackReconstruction(values1, sizes1, capacity1);
    cout << "Test Case 1 - Expected Items: ";
    for (int item : expectedItems1) {
        cout << item << " ";
    }
    cout << ", Result Items: ";
    for (int item : resultItems1) {
        cout << item << " ";
    }
    cout << endl;

    // Test Case 2
    vector<int> values2 = {30, 40, 50, 60};
    vector<int> sizes2 = {5, 10, 15, 22};
    int capacity2 = 30;
    int expectedValue2 = 120;
    int result2 = knapsack(values2, sizes2, capacity2);
    cout << "Test Case 2 - Expected: " << expectedValue2 << ", Result: " << result2 << endl;

    vector<int> expectedItems2 = {2, 1, 0}; // Indices of selected items
    vector<int> resultItems2 = knapsackReconstruction(values2, sizes2, capacity2);
    cout << "Test Case 2 - Expected Items: ";
    for (int item : expectedItems2) {
        cout << item << " ";
    }
    cout << ", Result Items: ";
    for (int item : resultItems2) {
        cout << item << " ";
    }
    cout << endl;

}


int main() {
    
    runTestCases();

    return 0;
}