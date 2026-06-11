#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string add(string &s1, string &s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        int n = max(n1, n2);
        string ans;
        ans.resize(n + 1);
        int jinwei = 0;
        int remain = 0;
        int tmp = 0;
        for (int i = 1; i <= n; i++)
        {
            tmp = jinwei + (n1 - i < 0 ? 0 : s1[n1 - i] - '0') + (n2 - i < 0 ? 0 : s2[n2 - i] - '0');
            remain = tmp % 10;
            jinwei = tmp / 10;
            ans[n + 1 - i] = remain + '0';
        }
        if (jinwei != 0)
        {
            ans[0] = jinwei + '0';
        }
        else
        {
            ans.erase(ans.begin());
        }
        return ans;
    }
    bool is_ok = false;
    void backtrack(string &num, int beg, string to_check, string pre, int processed)
    {
        if (is_ok)
        {
            return;
        }
        if (num.size() - beg < to_check.size())
        {
            return;
        }

        if (num[beg] == '0')
        {
            if (to_check != "" && pre != "")
            {
                if (to_check != "0")
                {
                    return;
                }
                processed++;
                if (beg + to_check.size() == num.size())
                {
                    is_ok = processed >= 3;
                    return;
                }
                backtrack(num, beg + 1, add(to_check, pre), "0", processed);
            }
            else if (pre == "")
            {
                backtrack(num, beg + 1, "", "0", 1);
            }
            else
            {
                backtrack(num, beg + 1, pre, "0", 2);
            }
        }
        else
        {
            if (to_check != "" && pre != "")
            {
                bool is_prefix = true;
                for (int i = 0; i < to_check.size(); i++)
                {
                    if (num[beg + i] != to_check[i])
                    {
                        is_prefix = false;
                        break;
                    }
                }
                if (!is_prefix)
                {
                    return;
                }
                else
                {
                    processed++;
                    if (beg + to_check.size() == num.size())
                    {
                        is_ok = processed >= 3;
                        return;
                    }

                    backtrack(num, beg + to_check.size(), add(to_check, pre), to_check, processed);
                }
            }
            else if (pre == "")
            {
                string now;
                for (int i = beg + to_check.size(); i < num.size(); i++)
                {
                    now.push_back(num[i]);
                    backtrack(num, i + 1, "", now, 1);
                }
            }
            else if (to_check == "")
            {
                string now;
                for (int i = beg + to_check.size(); i < num.size(); i++)
                {
                    now.push_back(num[i]);
                    backtrack(num, i + 1, add(pre, now), now, 2);
                }
            }
        }
    }

    bool isAdditiveNumber(string &num)
    {
        backtrack(num, 0, "", "", 0);
        return is_ok;
    }
};
