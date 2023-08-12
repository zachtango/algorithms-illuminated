#include <iostream>
using std::cout;
using std::cin;
#include <iomanip>
using std::setprecision;
using std::fixed;
#include <vector>
using std::vector;
#include <cmath>
using std::round;

/*
    Given a time stamps with profit
        Determine the most profitable period
            If there are two most profitable periods, choose the shortest
            If they are the same length, choose the earliest
    0.08 per minute to keep store running

    Get max range sum, keep track of left and right endpoints (time)
        subtract (right - left + 1) * 8 when calculating range sum

    ROUNDING ERRORS
    - Round never truncate, I got this problem wrong multiple times
        because I didn't round the input
*/

const int MAX_TIME = 1440;

void maxProfit(int *profits) {
    
    int maxSum = profits[0];
    int maxL = 0,
        maxR = 0;

    int sum = 0,
        l = 0;
    
    for (int i = 0; i < MAX_TIME; i++) {
        sum += profits[i];
        
        if (sum > maxSum) {
            maxSum = sum;
            maxL = l;
            maxR = i;
        } else if (sum == maxSum && i - l < maxR - maxL) {
            maxL = l;
            maxR = i;
        }

        if (sum <= 0) {
            sum = 0;
            l = i + 1;
        }
    }
    
    if (maxSum <= 0) {
        cout << "no profit\n";
    } else {
        cout << fixed << setprecision(2) << ( (double) (maxSum) / 100 ) << ' ' <<
                maxL << ' ' <<
                maxR << '\n';
    }

}


int main() {

    int profits[MAX_TIME];

    int n;

    while (cin >> n, n) {
        for (int i = 0; i < MAX_TIME; i++) {
            profits[i] = -8;
        }

        for (int i = 0; i < n; i++) {
            int time;
            double profit;

            cin >> time >> profit;

            profits[time] = (int) round(profit * 100) - 8;
        }

        maxProfit(profits);
    }

    return 0;
}

