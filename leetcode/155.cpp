#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    stack<int> st_val; // 专门存值
    stack<int> st_min; // 专门存当前最小值

public:
    MinStack()
    {
    }

    void push(int val)
    {
        st_val.push(val);
        st_min.push(st_min.empty() ? val : min(st_min.top(), val));
    }

    void pop()
    {
        st_min.pop();
        st_val.pop();
    }

    int top()
    {
        return st_val.top();
    }

    int getMin()
    {
        return st_min.top();
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
