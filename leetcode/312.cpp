#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 经典的区间dp
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        // dp[i][j]表示在扩展数组(两侧加上1)中，开区间(i,j)的最大得分
        for (int i = n + 1; i >= 0; i--)
        {
            for (int j = i + 2; j <= n + 1; j++)
            {
                auto l = i - 1 >= 0 ? nums[i - 1] : 1;
                auto r = j - 1 < n ? nums[j - 1] : 1;
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + l * r * nums[k - 1]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
