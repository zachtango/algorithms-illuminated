#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
    Given a string s, find the length of the longest substring without repeating characters.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> index;
        int n = s.size();
        int l = 0, r = 0;

        int length = 0;
        while (r < n) {
            if (index.count(s[r])) {
                // Reset window
                l = index[s[r]] + 1;
                index.clear();

                for (int i = l; i < r; i++) {
                    index[s[i]] = i;
                }
                
            } else {
                length = max(length, r - l + 1);
            }
            
            index[s[r]] = r;
            r += 1;
        }

        return length;
    }
};
