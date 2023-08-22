#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(),
            n = matrix[0].size();
        
        int l = 0,
            r = m * n;

        while (l < r) {
            int mid = (l + r) / 2;

            int i = mid / n,
                j = mid % n;
            
            if (target < matrix[i][j]) {
                r = mid;
            } else if (target > matrix[i][j]) {
                l = mid + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};