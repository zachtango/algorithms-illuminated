#include <algorithm>
using std::max;
#include <iostream>
using std::cout;
using std::cin;
/*
    https://open.kattis.com/problems/commercials
    
    notes:
    - commercial between 8 am and 5 pm
    - how many people listen to the radio at each point of the day
    - commercial break is every 15 minutes
    - choose one continuous commercial break such that profit is maximized
    
    N = total number of commercial breaks in a day
    P = price of one commercial break
    next N separated integers that denote how many students listen to i-th commercial break

    determine the maximum subarray sum

*/

int maxProfit(int *A, int N, int P) {
    if (N == 0) {
        return 0;
    }

    int maxSum = A[0];
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += A[i];

        maxSum = max(maxSum, sum);
        
        if (sum < 0) {
            sum = 0;
        }
    }

    return maxSum;
}

int main() {
    
    int N, P;
    cin >> N >> P;

    int A[N];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= P;
    }

    cout << maxProfit(A, N, P);

    return 0;
}
