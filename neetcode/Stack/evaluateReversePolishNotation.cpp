#include <vector>
#include <string>
#include <stack>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string op = "+-*/";
        stack<int> stk;

        for (const auto &s : tokens) {
            if (op.find(s) != string::npos) {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();

                switch (s[0]) {
                    case '+':
                        stk.push(a + b);
                        break;
                    case '-':
                        stk.push(a - b);
                        break;
                    case '*':
                        stk.push(a * b);
                        break;
                    case '/':
                        stk.push(a / b);
                        break;
                }

            } else {
                stk.push(stoi(s));
            }
        }

        return stk.top();
    }
};