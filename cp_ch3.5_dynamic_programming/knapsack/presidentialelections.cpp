#include <iostream>
using std::cin;
using std::cout;
#include <cmath>
using std::min;
using std::max;
using std::ceil;
#include <vector>
using std::vector;

#define INF (int) 1e9
#define MAX_DELEGATES 2016

/*
    Voter votes for exactly 2 candidates
    
    Every state has a number of delegates
    The delegates go to final round of voting to vote the side of their majority votes


    Each state provides a value
    Each state also has a weight (number of voters)

    Trying to get combination of states over >= a value V while
        minimizing the total weight of the states

    S
        Di delegates
        Ci registered voted for Constituents
        Fi registered voters for Feds
        Ui undecided voters

    Cleaning Input:
        need to get Ci > Fi

        possible if Ci + Ui > Fi
            otherwise impossible
        
        possible -> Ci + a > Fi + b
                    Ci - Fi > u - 2a
                    Ci - Fi - u > -2a
                    Ci - Fi - u / -2 < a
    
    Total C
    Total F
    Total D
    If F > (D + 1) / 2, it's impossible
*/


int main() {
    
    int S;
    cin >> S;

    int C, F, U, D;
    int total_C = 0, total_F = 0, total_D = 0;

    vector<int> V, W;

    for (int i = 0; i < S; i++) {
        cin >> D >> C >> F >> U;

        int requiredVotes;

        if (F - C >= U) {
            // Impossible to win this state
            total_F += D;
            requiredVotes = INF;
        } else if (C - F > U) {
            // Always win this state
            total_C += D;
            requiredVotes = 0;
        } else {
            requiredVotes = (F - C + U) / 2 + 1;
        }

        V.push_back(D);
        W.push_back(requiredVotes);

        total_D += D;
    }

    if (total_F >= (total_D + 1) / 2) {
        cout << "impossible\n";
        return 0;
    }

    if (total_C > total_D / 2) {
        cout << 0 << '\n';
        return 0;
    }

    int dp[S + 1][MAX_DELEGATES + 1];
    int minVotes = INF;
    for (int i = 0; i <= S; i++) {
        for (int j = 0; j <= total_D / 2 + 1; j++) {
            if (i == 0 && j == 0) {
                dp[0][0] = 0;
                continue;
            }
            if (i == 0) {
                dp[i][j] = INF;
                continue;
            }
            if (j == 0) {
                dp[i][j] = 0;
                continue;
            }

            dp[i][j] = min(
                dp[i - 1][j],
                dp[i - 1][max(j - V[i - 1], 0)] + W[i - 1]
            );

            if (dp[i][j] > INF) {
                dp[i][j] = INF;
            }

            if (j > total_D / 2) {
                minVotes = min(minVotes, dp[i][j]);
            }
        }
    }

    cout << minVotes << '\n';

    return 0;
}


