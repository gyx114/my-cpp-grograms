#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int d_p(vector<vector<int>> &grid, vector<vector<int>> &dp, int x, int y)
    {
        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }
        else
        {
            if (x == 0 && y == 0)
            {
                return dp[x][y] = grid[x][y];
            }
            else
            {
                int up = x > 0 ? d_p(grid, dp, x - 1, y) : INT_MAX;
                int lft = y > 0 ? d_p(grid, dp, x, y - 1) : INT_MAX;
                return dp[x][y] = min(up, lft) + grid[x][y];
            }
        }
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return d_p(grid, dp, m - 1, n - 1);
    }
};
