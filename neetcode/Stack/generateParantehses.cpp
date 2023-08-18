#include <vector>
#include <string>

using namespace std;


class Solution {
private:
    vector<string> valid;

public:
    void dfs(int open, int close, int n, string &s) {
        if (open + close == 2 * n) {
            valid.push_back(s);
            return;
        }

        if (open < n) {
            s.push_back('(');
            dfs(open + 1, close, n, s);
            s.pop_back();
        }

        if (open > close) {
            s.push_back(')');
            dfs(open, close + 1, n, s);
            s.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        string accum = "(";
        dfs(1, 0, n, accum);
        return valid;
    }
};