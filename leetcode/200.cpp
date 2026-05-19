#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void check_island(vector<vector<char>> &grid, int x, int y)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == '0')
        {
            return;
        }
        else
        {
            grid[x][y] = '0';
            check_island(grid, x, y + 1);
            check_island(grid, x + 1, y);
            check_island(grid, x - 1, y);
            check_island(grid, x, y - 1);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    check_island(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
