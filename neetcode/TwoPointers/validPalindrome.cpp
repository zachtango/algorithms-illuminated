#include <string>
#include <cstring>

using namespace std;

/*
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

    Given a string s, return true if it is a palindrome, or false otherwise.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0,
            r = s.size() - 1;
        
        while (l < r) {
            if (!isalnum(s[l])) {
                l += 1;
                continue;
            }

            if (!isalnum(s[r])) {
                r -= 1;
                continue;
            }

            if (toupper(s[l]) != toupper(s[r])) {
                return false;
            }

            l += 1;
            r -= 1;
        }

        return true;
    }
};
