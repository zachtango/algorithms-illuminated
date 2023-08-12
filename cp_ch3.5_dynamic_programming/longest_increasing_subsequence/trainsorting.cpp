#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::max;
using std::reverse;

/*
    Problem reduces to longest increasing
        subsequence[i] + longest decreasing subsequence[i] - 1
        of input
*/

void solve(vector<int> &A, int n) {
    int IL[n], DL[n];

    int maxL = 0;

    for (int i = 0; i < n; i++) {
        IL[i] = 1;
        DL[i] = 1;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                IL[i] = max(IL[i], IL[j] + 1);
            } else {
                DL[i] = max(DL[i], DL[j] + 1);
            }
        }
        maxL = max(maxL, IL[i] + DL[i] - 1);
    }
    
    cout << maxL << '\n';
}

int main() {
    
    int n;
    cin >> n;

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    reverse(A.begin(), A.end());

    solve(A, n);

    return 0;
}