#include <string>

using namespace std;

/*
    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

    In other words, return true if one of s1's permutations is the substring of s2.
*/

class Solution {
    static const int NUM_CHARS = 26;
    int count[NUM_CHARS];
    int windowCount[NUM_CHARS];

    void resetCount() {
        for (int i = 0; i < NUM_CHARS; i++) {
            count[i] = 0;
            windowCount[i] = 0;
        }
    }

    bool countsMatch() {
        for (int i = 0; i < NUM_CHARS; i++) {
            if (count[i] != windowCount[i]) {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        /*
            keep count of s1's chars

            create a window of size s1.size() that has a count of s2's chars in that window
                check if the window count equals s1's count, if it does, the permutation exists

                otherwise move the window right and repeat check until the end
        */

        resetCount();

        for (const auto &c : s1) {
            count[c - 'a'] += 1;
        }

        int n = s1.size();

        int l = 0, r = n - 1;
        for (int i = l; i <= r; i++) {
            windowCount[s2[i] - 'a'] += 1;
        }

        while (r < n) {
            if (countsMatch()) {
                return true;
            }

            windowCount[s2[l] - 'a'] -= 1;
            if (r < n - 1) {
                windowCount[s2[r + 1] - 'a'] += 1;
            }

            l += 1;
            r += 1;
        }

        return false;
    }
};
