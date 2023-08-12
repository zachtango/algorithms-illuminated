#include <iostream>
using std::cout;
using std::cin;

/*
    Strictly increasing subsequence
    Use DP
*/

constexpr const int MAX_N = 200;

void solve(int *A, int n) {
    
    int next[n];
    int L[n];
    
    next[n - 1] = n - 1;
    L[n - 1] = 1;

    int maxL = 1,
        maxI = n - 1;

    for (int i = n - 2; i >= 0; i--) {
        next[i] = i;
        L[i] = 1;
        for (int j = n - 1; j > i; j--) {
            if (A[i] < A[j]) {
                if (L[j] + 1 > L[i]) {
                    next[i] = j;
                    L[i] = L[j] + 1;
                } else if (L[j] + 1 == L[i] && A[j] < A[next[i]]) {
                    next[i] = j;
                }
            }
        }
        if (L[i] > maxL) {
            maxL = L[i];
            maxI = i;
        } else if(L[i] == maxL && A[i] < A[maxI]) {
            maxI = i;
        }
    }

    cout << maxL << ' ';
    for (int i = 0; i < maxL; i++) {
        cout << A[maxI] << ' ';
        maxI = next[maxI];
    }
    cout << '\n';
}

int main() {

    int A[MAX_N],
        n;

    while (cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        solve(A, n);
    }
    

    return 0;
}