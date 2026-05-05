#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                int down = (i == n - 1) ? 0 : dp[j];
                int down_right = (i == n - 1) ? 0 : dp[j + 1];
                dp[j] = triangle[i][j] + min(down, down_right);
            }
        }
        return dp[0];
    }
};
