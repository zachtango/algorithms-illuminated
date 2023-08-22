#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
            l, r
            m = (l + r) / 2

            target < nums[m] and target >= nums[l] --> l, m - 1

            target < nums[m] and target < nums[l] --> m + 1, r

            target > nums[m] and target <= nums[r] --> m + 1, r

            target > nums[m] and target > nums[r] --> l, m - 1
        */
        
        function<int(int, int)> binarySearch = [&](int l, int r) {
            if (l == r) {
               return (target == nums[l]) ? l : -1;
            } else if (l == r - 1) {
                if (target == nums[l]) {
                    return l;
                }
                return (target == nums[r]) ? r : -1;
            }

            int m = (l + r) / 2;

            if (target == nums[m]) {
                return m;
            } else if ( (nums[l] <= nums[m - 1] && target >= nums[l] && target <= nums[m - 1]) ||
                (nums[m + 1] <= nums[r] && (target < nums[m + 1] || target > nums[r]))
            ) {
                return binarySearch(l, m - 1);
            } else {
                return binarySearch(m + 1, r);
            }
        };

        return binarySearch(0, nums.size() - 1);
    }
};