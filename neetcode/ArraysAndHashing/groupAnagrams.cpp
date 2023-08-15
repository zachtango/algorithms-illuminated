#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        
        for (const auto &str : strs) {
            string s = str;
            sort(s.begin(), s.end());

            m[s].push_back(str);
        }

        vector<vector<string>> anagrams;

        for (const auto &p : m) {
            anagrams.push_back(p.second);
        }

        return anagrams;
    }
};

