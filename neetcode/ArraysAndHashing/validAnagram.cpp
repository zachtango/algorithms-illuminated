#include <string>

using namespace std;

/*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        constexpr const int NUM_SYMBOLS = 26;
        int count[NUM_SYMBOLS];
        for (int i = 0; i < NUM_SYMBOLS; i++) {
            count[i] = 0;
        }

        for (const auto &c : s) {
            count[c - 'a'] += 1;
        }
        for (const auto &c : t) {
            count[c - 'a'] -= 1;
        }

        for (int i = 0; i < NUM_SYMBOLS; i++) {
            if (count[i]) {
                return false;
            }
        }

        return true;
    }
};
