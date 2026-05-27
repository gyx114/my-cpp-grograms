#include <bits/stdc++.h>
using namespace std;
class MyStack
{
public:
    int size;
    queue<int> q;
    MyStack() : size(0)
    {
    }

    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < size; i++)
        {
            auto fr = q.front();
            q.pop();
            q.push(fr);
        }
        size++;
    }

    int pop()
    {
        auto ret = q.front();
        q.pop();
        size--;
        return ret;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return !size;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
