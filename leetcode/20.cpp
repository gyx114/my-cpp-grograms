#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        unordered_map<char, char> mp = {{'}', '{'}, {']', '['}, {')', '('}};
        for (auto c : s)
        {
            if (c == '{' || c == '(' || c == '[')
            {
                st.push(c);
            }
            else
            {
                // 一定要检查栈是否为空！！！！！
                if (st.empty() || mp[c] != st.top())
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
