#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    stack<int> st1;
    stack<int> st2;
    bool which;
    bool need_move;
    MyQueue() : which(true), need_move(true)
    {
    }

    void push(int x)
    {
        if (!need_move)
        {
            mv();
            need_move = true;
        }
        if (which)
        {
            st1.push(x);
        }
        else
        {
            st2.push(x);
        }
    }

    void mv()
    {
        if (which)
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        else
        {
            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
        }
        which = !which;
        need_move = false;
    }

    int pop()
    {
        if (need_move)
        {
            mv();
        }
        int ret;
        if (which)
        {
            ret = st1.top();
            st1.pop();
        }
        else
        {
            ret = st2.top();
            st2.pop();
        }
        return ret;
    }

    int peek()
    {
        if (need_move)
        {
            mv();
        }
        if (which)
        {
            return st1.top();
        }
        else
        {
            return st2.top();
        }
        return 0;
    }

    bool empty()
    {
        if (which)
        {
            return st1.empty();
        }
        else
        {
            return st2.empty();
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
