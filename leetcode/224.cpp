#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int calculate(string sss)
    {
        string s;
        for (int i = 0; i < sss.size(); i++)
        {
            auto c = sss[i];
            if (c == ' ')
            {
                continue;
            }
            else
            {
                s += c;
            }
        }
        stack<bool> op;
        // true:+   false:-
        int ans = 0;
        op.push(true); // 总基调为+
        for (int i = 0; i < s.size(); i++)
        {
            auto si = s[i];
            if (si == '+')
            {
                auto tp = op.top();
                if (tp)
                {
                    op.push(true);
                }
                else
                {
                    op.push(false);
                }
            }
            else if (si == '-')
            {
                auto tp = op.top();
                if (tp)
                {
                    op.push(false);
                }
                else
                {
                    op.push(true);
                }
            }
            else if (si == '(')
            {
                if (i == 0 || s[i - 1] == '(')
                {
                    op.push(op.top());
                }
            }
            else if (si == ')')
            {
                op.pop();
            }
            else
            {
                int beg = i;
                long long num = 0;
                for (int j = i; j <= s.size(); j++)
                {
                    if (j == s.size())
                    {
                        i = j;
                        break;
                    }
                    else if (s[j] >= '0' && s[j] <= '9')
                    {
                        num = num * 10 + (s[j] - '0');
                    }
                    else
                    {
                        i = j - 1;
                        break;
                    }
                }
                auto o = op.top();
                if (o)
                {
                    ans += num;
                }
                else
                {
                    ans -= num;
                }

                if (beg != 0 && (s[beg - 1] == '-' || s[beg - 1] == '+'))
                {
                    op.pop();
                }
            }
        }
        return ans;
    }
};
