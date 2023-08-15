#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

    You must write an algorithm that runs in O(n) time.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniqueNums(nums.begin(), nums.end());

        int longest = 0;
        
        while (uniqueNums.size()) {
            int s = *uniqueNums.begin();
            int counter = 0, i = s;

            // Left
            while (uniqueNums.count(i)) {
                uniqueNums.erase(i);
                i -= 1;
                counter += 1;
            }

            i = s + 1;
            // Right
            while (uniqueNums.count(i)) {
                uniqueNums.erase(i);
                i += 1;
                counter += 1;
            }

            longest = max(longest, counter);
        }

        return longest;
    }
};

