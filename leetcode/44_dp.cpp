#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        auto dp = vector<vector<bool>>(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = true;
            }
            else
            {
                break;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            char moshi = p[j - 1];
            for (int i = 1; i <= m; i++)
            {
                if (moshi == '?')
                {
                    dp[i][j] = i >= 1 ? dp[i - 1][j - 1] : false;
                }
                else if (moshi == '*')
                {
                    dp[i][j] = dp[i][j - 1] // 匹配串前i个能与模式串前(j-1)个匹配，此时*匹配0个即可
                               ||
                               dp[i - 1][j]; // 匹配串前(i-1)个能与模式串前j个匹配，此时*再多把匹配串的第i个匹配了即可
                                             // 注意，这不表明*从模式串的第i个开始匹配，从之前开始匹配dp[i-1][j]照样为1，*多匹配1个也没问题
                }
                else
                {

                    dp[i][j] = (dp[i - 1][j - 1]) && (s[i - 1] == p[j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
