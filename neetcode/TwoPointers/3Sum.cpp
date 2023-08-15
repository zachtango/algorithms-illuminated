#include <vector>
#include <algorithm>

using namespace std;

/*
    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the most water.

    Return the maximum amount of water a container can store.

    Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0, r = n - 1;

        int m = 0;
        while (l < r) {
            m = max(m, min(height[r], height[l]) * (r - l));

            if (height[l] < height[r]) {
                l += 1;
            } else {
                r -= 1;
            }
        }

        return m;
    }
};

