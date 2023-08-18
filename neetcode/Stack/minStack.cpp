#include <algorithm>
#include <utility>
#include <stack>
#include <iostream>

using namespace std;

class MinStack {
private:
    stack<pair<int, int>> stk;

public:
    MinStack() {
    }
    
    void push(int val) {
        int minSoFar = val;

        if (!stk.empty()) {
            minSoFar = min(minSoFar, stk.top().second);
        }
    
        stk.push({val, minSoFar});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        const auto [top, minSoFar] = stk.top();

        return top;

    }
    
    int getMin() {
        const auto [top, minSoFar] = stk.top();

        return minSoFar;
    }
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
