#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 最长回文前缀的长度
    int max_pali_pre_len(string &s)
    {
        // 为了找最长回文前缀，
        // 我们把s和其反序拼接
        // 然后求出kmp算法中的next数组即可
        // 因为kmp中的next数组就是用来指示公共前后缀长度的

        int n = s.size();
        string connect = s;
        connect += '$'; // 分隔正序和反序
        for (int i = n - 1; i >= 0; i--)
        {
            connect += s[i];
        }
        vector<int> next(connect.size(), -1); // 表示匹配的下标

        next[0] = -1;
        for (int i = 1; i < connect.size(); i++)
        {
            int j = next[i - 1];
            if (j == -1)
            {
                next[i] = connect[i] == connect[0] ? 0 : -1;
            }
            else
            {
                if (connect[i] == connect[j + 1])
                {
                    next[i] = j + 1;
                }
                else
                {
                    while (j != -1 && connect[i] != connect[j + 1])
                    {
                        j = next[j];
                    }
                    if (j == -1)
                    {
                        next[i] = connect[i] == connect[0] ? 0 : -1;
                    }
                    else
                    {
                        next[i] = j + 1;
                    }
                }
            }
        }
        return next[connect.size() - 1] + 1;
    }

    string shortestPalindrome(string &s)
    {
        if (s.empty())
        {
            return s;
        }
        int n = s.size();
        int l = max_pali_pre_len(s);

        string remain = s.substr(l);
        reverse(remain.begin(), remain.end());
        remain += s;
        return remain;
    }
};
