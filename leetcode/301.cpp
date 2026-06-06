#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void is_valid(string &s)
    {
        int val = 0;
        string tmp;
        for (int i = 0; i < s.size(); i++)
        {
            auto &c = s[i];

            if (to_be_deleted.count(i))
            {
                continue;
            }

            if (c == '(')
            {
                val++;
            }
            else if (c == ')')
            {
                val--;
            }

            tmp += c;

            if (val < 0)
            {
                return;
            }
        }
        if (val == 0)
        {
            ans.insert(move(tmp));
        }
    }

    unordered_set<string> ans;
    unordered_set<int> to_be_deleted;
    // cnt:还要删几个
    // beg:开始下标
    void backtrack(string &s, int l, int r, int beg)
    {
        if (l == 0 && r == 0)
        {
            is_valid(s);
            return;
        }
        else if (l < 0 || r < 0)
        {
            return;
        }
        else if (beg >= s.size() || s.size() - beg < l + r)
        {
            return;
        }

        if (s[beg] == '(')
        {
            // 删
            to_be_deleted.insert(beg);
            backtrack(s, l - 1, r, beg + 1);
            to_be_deleted.erase(beg);

            // 不删
            backtrack(s, l, r, beg + 1);
        }
        else if (s[beg] == ')')
        {
            // 删
            to_be_deleted.insert(beg);
            backtrack(s, l, r - 1, beg + 1);
            to_be_deleted.erase(beg);

            // 不删
            backtrack(s, l, r, beg + 1);
        }
        else
        {
            // 不删
            backtrack(s, l, r, beg + 1);
        }
    }

    vector<string> removeInvalidParentheses(string &s)
    {
        int l = 0;
        int r = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                l++;
            }
            else if (c == ')')
            {
                l--;
                if (l < 0)
                {
                    r++;
                    l = 0;
                }
            }
        }
        backtrack(s, l, r, 0);
        vector<string> ret(ans.begin(), ans.end());
        return ret;
    }
};
