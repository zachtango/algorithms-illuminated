#include <vector>
#include <unordered_map>

using namespace std;

/*
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_multimap<int, int> index;

        for (int i = 0; i < n; i++) {
            index.insert({nums[i], i});
        }

        for (int i = 0; i < n; i++) {
            int num = target - nums[i];
            if (index.count(num)) {
                auto range = index.equal_range(num);
                for (auto it = range.first; it != range.second; it++) {
                    if (it->second == i) {
                        continue;
                    }
                    return {i, it->second};
                }
            }
        }

        // Should never reach here
        return {};
    }
};