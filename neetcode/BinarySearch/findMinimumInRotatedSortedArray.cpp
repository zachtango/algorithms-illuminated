#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
            nums[m]
            nums[l, m - 1]
            nums[m + 1, r]

            case nums[l, m - 1] and nums[m, r] ascending
                recurse on whichever one is smaller nums[l] or nums[m]
            case nums[l, m - 1] rotated
                recurse on l, m - 1
            case nums[m, r] rotated
                recurse on m, r
        */
        function<int(int, int)> binarySearch = [&](int l, int r) {
            if (l == r) {
                return nums[l];
            }

            int m = (l + r) / 2;

            if (nums[l] > nums[m]) {
                return binarySearch(l, m);
            }

            if (nums[m + 1] > nums[r]) {
                return binarySearch(m + 1, r);
            }

            return (nums[l] < nums[m + 1]) ? binarySearch(l, m) : binarySearch(m + 1, r);
        };

        return binarySearch(0, nums.size() - 1);
    }
};