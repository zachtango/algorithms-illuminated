#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;


/*
    R x S pixels (window)
    K pixels of racket (K x K racket, but only K - 2 x K - 2 )
    What is the maximal amount of flies could be killed in a single shot?

    1. Store 2D range sum in P
    2. Iterate through all possible submatrices of size K - 2 x K - 2
        and get the one with the most flies (keep track of i, j)
    3. Output the new window with racket on it
*/

char window[101][101];

void printWindow(int R, int S, int K, int maxI, int maxJ, int maxFlies) {
    cout << maxFlies << '\n';

    for (int i = maxI - 1; i < maxI - 1 + K; i++) {
        window[i][maxJ - 1] = '|';
        window[i][maxJ - 1 + K - 1] = '|';
    }

    for (int j = maxJ - 1; j < maxJ - 1 + K; j++) {
        window[maxI - 1][j] = '-';
        window[maxI - 1 + K - 1][j] = '-';
    }

    window[maxI - 1][maxJ - 1] = '+';
    window[maxI - 1][maxJ - 1 + K - 1] = '+';
    window[maxI - 1 + K - 1][maxJ - 1] = '+';
    window[maxI - 1 + K - 1][maxJ - 1 + K - 1] = '+';

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            cout << window[i][j];
        }
        cout << '\n';
    }

}

void solve(vector<vector<int>> &P, int R, int S, int K) {
    int maxFlies = 0,
        maxI = 0,
        maxJ = 0;

    
    // Try all possible submatrices size K - 2
    // Must be WITHIN the window (hence starting at i = 1 and ending at end - 1)
    for (int i = 1; i < R - (K - 2); i++) {
        for (int j = 1; j < S - (K - 2); j++) {
            int flies = P[i + K - 2 - 1][j + K - 2 - 1] -
                        P[i + K - 2 - 1][j - 1] -
                        P[i - 1][j + K - 2 - 1] +
                        P[i - 1][j - 1];
            // cout << "Flies: " << flies << '\n';
            if (flies > maxFlies) {
                maxI = i;
                maxJ = j;
                maxFlies = flies;
            }
        }
    }

    printWindow(R, S, K, maxI, maxJ, maxFlies);
}


int main() {

    int R, S, K;

    cin >> R >> S >> K;

    vector<vector<int>> P(R, vector<int>(S));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < S; j++) {
            cin >> window[i][j];

            if (window[i][j] == '*') {
                P[i][j] = 1;
            } else {
                P[i][j] = 0;
            }
            
            if (i > 0) {
                P[i][j] += P[i - 1][j];
            }
            if (j > 0) {
                P[i][j] += P[i][j - 1];
            }
            if (i > 0 && j > 0) {
                P[i][j] -= P[i - 1][j - 1];
            }
            // cout << P[i][j] << ' ';
        }
        // cout << '\n';
    }

    solve(P, R, S, K);
    
    return 0;
}