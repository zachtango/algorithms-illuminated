#include <iostream>
using std::cout;
#include <algorithm>
using std::max;
#include <functional>
using std::function;

/*
    Longest Increasing Subsequence Problem
    Given an array of integers
    Output the length of the longest increasing subsequence
*/

// O(n * 2^n)
// Try all possible subsequences and track the longest increasing one

// O(n^2) DP
int lis(int *A, int n) {
    if (n == 0) {
        return 0;
    }

    int memo[n];
    memo[0] = 1;
    for (int i = 1; i < n; i++) {
        memo[i] = -1;
    }

    function<int(int)> _lis = [&](int i) {
        int &ans = memo[i];
        if (ans != -1) {
            return ans;
        }
        ans = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                ans = max(ans, _lis(j) + 1);
            }
        }
        return ans;
    };

    return _lis(n - 1);
}

// O(nlogk) Greedy + Divide and Conquer Algorithm


int main() {

    return 0;
}
