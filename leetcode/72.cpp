#include <bits/stdc++.h>
using namespace std;

// just dp
// 维护一个二维dp表，dp[i][j]表示
// word1前i个字符转成word2的前j个字符的编辑距离
// 状态转移：
// 如果word1第i个字符和word2第j个字符相同，
// 显然有dp[i][j]=dp[i-1][j-1]
// 否则要考虑以下三种的最小:
// 1.word1先转成word2的前j-1个字符，最后插入最后一个字符
// 2.word1前i-1个字符转成Word2，最后一个字符删掉
// 3.前i-1转成前j-1，再把word1第i个字符替换成word2第j个字符

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length() + 1;
        int n = word2.length() + 1;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = i;
        }
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = j;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                int lftup = dp[i - 1][j - 1];
                int lft = dp[i][j - 1];
                int up = dp[i - 1][j];
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = lftup;
                }
                else
                {
                    dp[i][j] = min(min(lft + 1, up + 1), lftup + 1);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
