#include <vector>

using namespace std;

/*
    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0,
            r = n - 1;
        
        int maxL = height[l],
            maxR = height[r];
        
        int rain = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                l += 1;
                rain += max(0, maxL - height[l]);
            } else {
                r -= 1;
                rain += max(0, maxR - height[r]);
            }

            maxL = max(height[l], maxL);
            maxR = max(height[r], maxR);
        }
        
        return rain;
    }
};


