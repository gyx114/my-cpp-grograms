#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 涉及最小，bfs是最优的
    vector<string> removeInvalidParentheses(string &s)
    {
        for (auto it = s.begin(); it != s.end();)
        {
            if (*it == ')')
            {
                it = s.erase(it);
            }
            else if (*it == '(')
            {
                break;
            }
            else
            {
                it++;
                continue;
            }
        }

        unordered_set<string> ans;
        unordered_set<string> st; // 用set代替queue，去重
        st.insert(s);
        bool flag = true;
        while (flag)
        {
            unordered_set<string> tmp;
            int sz = st.size();
            for (auto si : st)
            {
                int l = 0;
                bool is_ok = true; // 左括号>=右括号
                for (int j = 0; j < si.size(); j++)
                {
                    if (is_ok)
                    {
                        if (si[j] == '(')
                        {
                            l++;
                        }
                        else if (si[j] == ')')
                        {
                            l--;
                            if (l < 0)
                            {
                                is_ok = false;
                            }
                        }
                    }
                    if (flag && (j == 0 || si[j] != si[j - 1]))
                    {
                        auto t = si;
                        t.erase(t.begin() + j);
                        tmp.insert(move(t));
                    }
                }
                if (is_ok && l == 0)
                {
                    flag = false;
                    ans.insert(move(si));
                }
            }
            st = move(tmp);
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
