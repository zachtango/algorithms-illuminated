#include <vector>
#include <unordered_set>

using namespace std;

/*
    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> s;
        for (const auto &num : nums) {
            if (s.count(num)) {
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};
