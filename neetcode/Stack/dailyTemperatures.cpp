#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<pair<int, int>> stk;

        stk.push({temperatures[0], 0});

        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[i] > stk.top().first) {
                const auto [top, j] = stk.top(); stk.pop();

                answer[j] = i - j;
            }
            stk.push({temperatures[i], i});
        }

        return answer;
    }
};