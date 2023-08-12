#include <iostream>
using std::cout;
using std::cin;
#include <algorithm>
using std::max;

/*
    Given A, determine maximum subarray such that
        the subarray contains only one m as a minimum element
    
    have 2 pointers:
        lastL - indicates start of subarray
        lastM - indicates last element that was equal to m

    Iterate through subarray
        reset lastL if current element < m
            lastL = i + 1
        reset lastL if current element == m and lastM >= lastL
            lastL = lastM + 1
        consider the sum if lastM >= lastL

*/

const int INF = (int) 1e9;

void maxSubarray(int *A, int n, int m) {

    int lastM = -1;
    int lastL = 0;
    int maxSum = -INF;
    int sum = 0;

    int P[n];
    P[0] = A[0];
    for (int i = 1; i < n; i++) {
        P[i] = A[i] + P[i - 1];
    }

    for (int i = 0; i < n; i++) {
        sum += A[i];

        if (A[i] == m && lastM >= lastL) {
            lastL = lastM + 1;
            sum = P[i] - P[lastL - 1];
        }

        if (sum < 0 || A[i] < m){ 
            sum = 0;
            lastL = i + 1;
        }

        if (A[i] == m) {
            lastM = i;
        }

        if (lastM >= lastL) {
            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum << '\n';
}

int main() {

    int t, n, m;

    cin >> t;
    
    while(t--) {
        cin >> n >> m;

        int A[n];

        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        maxSubarray(A, n, m);
    }

    return 0;
}