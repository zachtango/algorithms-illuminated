#include <iostream>
using std::cin;
using std::cout;


/*
    
    B = -1
    R = 1

    Find the min sub array
    Find the max sub array

    Whichever's absolute value is greater, choose that one
    If tie, choose the leftmost one

*/

const int MAX_N = 1e5;
int A[MAX_N];

void bestSubarray(int n) {

    int l1 = 0, l2 = 0,
        bestL1 = 0, bestL2 = 0,
        bestR1 = 0, bestR2 = 0,
        sum1 = 0, sum2 = 0,
        maxSum = A[0], minSum = A[0];

    for (int i = 0; i < n; i++) {
        sum1 += A[i];
        sum2 += A[i];

        if (sum1 > maxSum) {
            bestL1 = l1;
            bestR1 = i;
            maxSum = sum1;
        }

        if (sum2 < minSum) {
            bestL2 = l2;
            bestR2 = i;
            minSum = sum2;
        }

        if (sum1 < 0) {
            sum1 = 0;
            l1 = i + 1;
        }

        if (sum2 > 0) {
            sum2 = 0;
            l2 = i + 1;
        }
    }
    
    bestL1 += 1;
    bestR1 += 1;
    bestL2 += 1;
    bestR2 += 1;

    if (maxSum > -minSum) {
        cout << bestL1 << ' ' << bestR1 << '\n';
    } else if (maxSum == -minSum) {
        if (bestL1 < bestL2) {
            cout << bestL1 << ' ' << bestR1 << '\n';
        } else {
            cout << bestL2 << ' ' << bestR2 << '\n';
        }
    } else {
        cout << bestL2 << ' ' << bestR2 << '\n';
    }

}

int main() {

    int n = 0;
    char c;

    while (cin >> c) {
        if (c == 'R') {
            A[n] = 1;
        } else {
            A[n] = -1;
        }
        n += 1;
    }

    bestSubarray(n);

    return 0;
}