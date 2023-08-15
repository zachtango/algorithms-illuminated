#include <vector>

using namespace std;

/*
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.

    Define prefix array as prefix[i] = product of elements up to index i
    Define postfix array as postfix[i] = product of elements from i to end
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), postfix(n, 1);

        prefix[0] = nums[0];
        postfix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i] * prefix[i - 1];
            postfix[n - i - 1] = nums[n - i - 1] * postfix[n - i];
        }
        
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = 1;
            
            if (i > 0) {
                ans[i] *= prefix[i - 1];
            }
            if (i < n - 1) {    
                ans[i] *= postfix[i + 1];
            }
        }

        return ans;
    }
};
