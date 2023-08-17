#include <string>
#include <algorithm>

using namespace std;

/*
    You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

    Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/

class Solution {
    static const int NUM_CHARS = 26;
    int count[NUM_CHARS];

    void resetCount() {
        for (int i = 0; i < NUM_CHARS; i++) {
            count[i] = 0;
        }
    }

    int getMaxCount() {
        int m = 0;
        for (int i = 0; i < NUM_CHARS; i++) {
            m = max(m, count[i]);
        }
        return m;
    }

public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int l = 0, r = 0;

        // window size - max num of same char in window = amt of letters to be used
        // keep increasing the window until it doesn't satisfy the constraints, then just move the window one over until end or it satisfies constraints then go back to increasing
        
        resetCount();

        int maxCount = 0;
        int length = 0;
        while (r < n) {
            count[s[r] - 'A'] += 1;

            maxCount = max(maxCount, count[s[r] - 'A']);
            
            int replaced = r - l + 1 - maxCount;

            if (replaced > k) {
                count[s[l] - 'A'] -= 1;
                l += 1;
                maxCount = getMaxCount();
            } else {
                length = max(length, r - l + 1);
            }

            r += 1;
        }

        return length;
    }
};

