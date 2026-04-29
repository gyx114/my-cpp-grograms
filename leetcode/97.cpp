#include <bits/stdc++.h>
using namespace std;

// 依旧字符串，依旧dp
// 不能双指针，因为当两边都可选时，由于两个字符串的地位相当，不能决定选取哪个
// 可以dfs做分支
// 为防止反复计算，可以记忆化，记录s1选i个，s2选j个行不行
// 典型的记忆化搜索，dp
// 当然也可以写成自顶向下的迭代式dp

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.length();
        int n = s2.length();
        if (m + n != s3.length())
        {
            return false;
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int j = 1; j < n + 1; j++)
        {
            if (s3[j - 1] == s2[j - 1] && dp[j - 1])
            {
                dp[j] = true;
            }
        }

        for (int i = 1; i < m + 1; i++)
        {
            if (dp[0] && s1[i - 1] == s3[i - 1])
            {
                dp[0] = true;
            }
            else
            {
                dp[0] = false;
            }
            for (int j = 1; j < n + 1; j++)
            {
                if ((dp[j - 1] && s2[j - 1] == s3[i + j - 1]) || (dp[j] && s1[i - 1] == s3[i + j - 1]))
                {
                    dp[j] = true;
                }
                else
                {
                    dp[j] = false;
                }
            }
        }
        return dp[n];
    }
};
