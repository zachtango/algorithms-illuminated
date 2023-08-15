#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/*
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

class Solution {

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for (const auto &num : nums) {
            count[num] += 1;
        }

        auto cmp = [&count](const int &a, const int &b) { return count[a] > count[b]; };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (const auto &[num, _] : count) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> elements;
        while (!pq.empty()) {
            elements.push_back(pq.top()); pq.pop();
        }

        return elements;
    }
};