#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool match(char a /*待匹配字符*/, char b /*模式字符*/)
    {
        if (b == '.')
        {
            return true;
        }
        else
            return a == b;
    }

    bool isMatch(string s /*待匹配串*/, string p /*模式串*/)
    {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        // dp[j][i]表示s的前j个和p的前i个能匹配
        dp[0][0] = true;
        for (int i = 1; i <= n2; i++)
        {
            for (int j = 0; j <= n1; j++)
            {
                if (j > 0 && match(s[j - 1], p[i - 1]))
                {
                    dp[j][i] = dp[j - 1][i - 1];
                }
                else if (p[i - 1] == '*')
                {
                    dp[j][i] = dp[j][i - 2]; // 特殊:匹配0个

                    if (j > 0 && match(s[j - 1], p[i - 2]))
                    {
                        dp[j][i] = dp[j][i] || dp[j - 1][i]; // 匹配多个
                        // 只要匹配串的第j个和模式串的第i-1个能匹配,就可以从dp[j-1][i]状态转移到dp[j][i]
                    }
                }
            }
        }
        return dp[n1][n2];
    }
};
