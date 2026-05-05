#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i].resize(i + 1);
            for (int j = 0; j <= i; j++)
            {
                int down = ((i == n - 1) ? 0 : dp[i + 1][j]);
                int down_right = ((i == n - 1) ? 0 : dp[i + 1][j + 1]);
                dp[i][j] = triangle[i][j] + min(down, down_right);
            }
        }
        return dp[0][0];
    }
};
