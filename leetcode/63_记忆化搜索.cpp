#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int d_p(vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid, int x, int y)
    {
        if (dp[x][y] != -1)
        {
            return dp[x][y];
        }
        else if (obstacleGrid[x][y] == 1)
        {
            dp[x][y] = 0;
            return 0;
        }
        else
        {
            if (x == 0 && y == 0)
            {
                return dp[x][y] = 1;
            }
            int up = x > 0 ? d_p(dp, obstacleGrid, x - 1, y) : 0;
            int lft = y > 0 ? d_p(dp, obstacleGrid, x, y - 1) : 0;
            return dp[x][y] = up + lft;
        }
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return d_p(dp, obstacleGrid, m - 1, n - 1);
    }
};
