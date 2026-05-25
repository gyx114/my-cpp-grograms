#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &nums)
    {
        int m = nums.size();
        int n = nums[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0)); // 以(i,j)为右下角  的正方形的最大边长
        int max_side = 0;                             // 全局的最大边长
        for (int j = 0; j < n; j++)
        {
            dp[0][j] = nums[0][j] - '0';
            max_side = max(max_side, dp[0][j]);
        }
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = nums[i][0] - '0';
            max_side = max(max_side, dp[i][0]);
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (nums[i][j] == '0')
                {
                    dp[i][j] = 0;
                }
                else if (!dp[i - 1][j - 1])
                {
                    dp[i][j] = 1;
                    max_side = max(max_side, dp[i][j]);
                }
                else
                {
                    dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
                    // 要想扩展，受3个约束：左边扩展长度dp[i][j-1]，上方扩展长度dp[i-1][j],左上方扩展长度dp[i-1][j-1]
                    max_side = max(max_side, dp[i][j]);
                }
            }
        }
        return max_side * max_side;
    }
};
