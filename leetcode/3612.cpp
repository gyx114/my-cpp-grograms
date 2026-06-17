#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string processStr(string s)
    {
        deque<char> ans;
        bool is_reversed = false;
        for (auto c : s)
        {
            if (c >= 'a' && c <= 'z')
            {
                is_reversed ? ans.push_front(c) : ans.push_back(c);
            }
            else if (c == '*')
            {
                if (ans.size())
                {
                    is_reversed ? ans.pop_front() : ans.pop_back();
                }
            }
            else if (c == '%')
            {
                is_reversed = !is_reversed;
            }
            else
            {
                if (is_reversed)
                {
                    int sz = ans.size();
                    for (int i = 0; i < sz; i++)
                    {
                        ans.push_front(ans[sz - 1]); // 如果重新分配会导致迭代器失效，因此不用迭代器
                        // 用insert似乎更好
                    }
                }
                else
                {
                    int sz = ans.size();
                    for (int i = 0; i < sz; i++)
                    {
                        ans.push_back(ans[i]);
                    }
                }
            }
        }
        if (is_reversed)
        {
            reverse(ans.begin(), ans.end());
        }
        string ret(ans.begin(), ans.end());
        return ret;
    }
};
