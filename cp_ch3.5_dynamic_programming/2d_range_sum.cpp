#include <iostream>
using std::cout;
#include <algorithm>
using std::max;

/*
    2D Max Range Sum Problem

    Given an n x n square matrix of integers A
    Output the maximum sum of all sub-matrices of A
*/

// O(n^6)
int maxRangeSum1(int **A, int n) {
    if (n == 0) {
        return 0;
    }
    /*
        Try every possible submatrix of A (i, j) (k, l)
        Compare submatrix sum to max
    */
    int maxSum = A[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { // top left coord (i, j)
            for (int k = i; k < n; k++) {
                for (int l = j; l < n; l++) { // bottom right coord (k, l)
                    int sum = 0;

                    for (int a = i; a <= k; a++) {
                        for (int b = j; b <= l; b++) {
                            sum += A[a][b];
                        }
                    }

                    maxSum = max(sum, maxSum);
                }
            }
        }
    }

    return maxSum;
}

// O(n^4)
int maxRangeSum2(int **A, int n) {
    if (n == 0) {
        return 0;
    }
    /*
        Keep track of prefix sum of A in P
        Try every possible submatrix of A (i, j) (k, l)
        
        Then we can calculate a submatrix sum (i, j) (k, l) in O(1) time
        sum(i, j, k, l) = P[k + 1][l + 1] - P[i + 1][l + 1] - P[k + 1][j + 1] + P[i][j]
    */
    int P[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            P[i][j] = A[i][j];
            if (i > 0) {
                P[i][j] += P[i - 1][j];
            }
            if (j > 0) {
                P[i][j] += P[i][j - 1];
            }
            if (i > 0 && j > 0) {
                P[i][j] -= P[i - 1][j - 1];
            }
        }
    }

    int maxSum = A[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { // top left coord (i, j)
            for (int k = i; k < n; k++) {
                for (int l = j; l < n; l++) { // bot right coord (k, l)
                    int sum = P[k][l];
                    if (i > 0) {
                        sum -= P[i - 1][l];
                    }
                    if (j > 0) {
                        sum -= P[k][j - 1];
                    }
                    if (i > 0 && j > 0) {
                        sum += P[i - 1][j - 1];
                    }
                    maxSum = max(sum, maxSum);
                }
            }
        }
    }

    return maxSum;
}

// O(n^3) Kadane's
int maxRangeSum3(int **A, int n) {
    if (n == 0) {
        return 0;
    }

    int P[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            P[i][j] = A[i][j];
            if (j > 0) {
                P[i][j] += P[i][j - 1];
            }
        }
    }
    
    int maxSum = A[0][0];
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int sum = 0;
            for (int row = 0; row < n; row++) {
                if (l > 0) {
                    sum += P[row][r] - P[row][l - 1];
                } else {
                    sum += P[row][r];
                }
                if (sum < 0) {
                    sum = 0;
                }
                maxSum = max(sum, maxSum);
            }
        }
    }

    return maxSum;
}


int main() {

    return 0;
}



