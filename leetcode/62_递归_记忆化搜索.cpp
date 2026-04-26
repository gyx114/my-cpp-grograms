#include <bits/stdc++.h>
using namespace std;

// 一般的递归会有大量重复计算(不同路径可能会包含同一节点)
// do a trick
// 初始化dp全为-1，递归时如果不是-1，表明已计算过，直接用

class Solution
{
public:
    int d_p(vector<vector<int>> &dp, int x, int y)
    {
        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }
        else
        {
            if (x == 0 && y == 0)
            {
                dp[x][y] = 1;
                return 1;
            }
            int up = x > 0 ? d_p(dp, x - 1, y) : 0;
            int lft = y > 0 ? d_p(dp, x, y - 1) : 0;
            dp[x][y] = up + lft;
            return dp[x][y];
        }
    }
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return d_p(dp, m - 1, n - 1);
    }
};
