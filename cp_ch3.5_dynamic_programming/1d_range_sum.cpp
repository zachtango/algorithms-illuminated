#include <iostream>
using std::cout;
#include <algorithm>
using std::max;


/*
    1D Max Range Sum Problem

    Given a list of integer numbers A
    Output the maximum range sum of A

    A range sum of i and j is the sum of elements 
        [i] + A[i + 1]  + ... + A[j]
*/

// O(n^3)
int maxRangeSum1(int *A, int n) {
    if (n == 0) {
        return 0;
    }
    /*
        Try every pair (i, j) such that i <= j
        Add up elements in (i, j) and compare it to max sum
    */
    int maxSum = A[0];
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; i++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += A[k];
            }
            maxSum = max(sum, maxSum);
        }
    }
    
    return maxSum;
}

// O(n^2)
int maxRangeSum2(int *A, int n) {
    if (n == 0) {
        return 0;
    }
    /*
        Try every pair (i, j) such that i <= j
        Optimize adding up elements in (i, j)
    */
    int maxSum = A[0];

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += A[j];
            maxSum = max(sum, maxSum);
        }
    }

    return maxSum;
}

// O(n^2)
int maxRangeSum3(int *A, int n) {
    if (n == 0) {
        return 0;
    }
    /*
        Create prefix sum
        P[j] = sum(0, j - 1)
        P[0] = 0
        
        O(1) calculation
        sum(i, j) = P[j + 1] - P[i]

        Try all (i, j) O(n^2)
    */

    int *P = new int[n + 1];
    P[0] = 0;
    for (int j = 1; j <= n; j++) {
        P[j] = P[j - 1] + A[j - 1];
    }

    int maxSum = A[0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            maxSum = max(P[j + 1] - P[i], maxSum);
        }
    }

    delete []P;

    return maxSum;
}

// O(n) Kadane's algo
int maxRangeSum4(int *A, int n) {
    if (n == 0) {
        return 0;
    }
    /*
        Greedy View: Keep running sum of integers seen so far and greedily reset to 0 if
            running sum dips below 0
        DP View: Each step, we have 2 choices: leverage previously accumulated max sum
            or begin a new range
            - DP[i] is the max sum ending with element A[i], then:
                1. DP[i] = DP[i - 1] + A[i] (leverage prev accum max) or
                2. DP[i] = A[i] (begin new range)
    */

    int maxSum = A[0], sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        maxSum = max(maxSum, sum);
        if (sum < 0) {
            sum = 0;
        }
    }

    return maxSum;
}


int main() {

    

    return 0;
}

