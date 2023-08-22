#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /*
            given piles of bananas and h

            guards come back in h hours
            find the minimum integer k such that you can eat all piles of bananas
                before the guards come back
            you will eat k bananas from a pile each hour
            if there is less than k bananas in a pile, you will eat just the pile

            binary search k

            start with max of piles; if can eat try k + k / 2 else k - k / 2
                start with range [1, maxPiles]
        */

        int r = *max_element(piles.begin(), piles.end());
        int l = 1;

        int minK = r;

        while (l < r) {
            int k = (l + r) / 2;
            long long hToEat = 0;
            
            for (auto p : piles) {
                hToEat += p / k + (p % k != 0);
            }

            if (hToEat <= h) {
                minK = k;
                r = k;
            } else {
                l = k + 1;
            }
        }

        return minK;
    }
};