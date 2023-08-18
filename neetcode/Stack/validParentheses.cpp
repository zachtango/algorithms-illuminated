#include <string>
#include <stack>
#include <iostream>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        string open = "([{";
        string close = ")]}";

        stack<char> stk;

        for (const auto &c : s) {
            if (open.find(c) != string::npos) {
                stk.push(c);
            } else {
                int i = close.find(c);

                if (stk.empty() || stk.top() != open[i]) {
                    return false;
                }

                stk.pop();
            }
        }
        
        return stk.empty();
    }
};