#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 虽然是int，但是只存0和1，只用到最后一位
    // 可以考虑利用其他位
    // 我们利用最后两位:
    // 最后一位存当前状态，倒数第二位存将来状态
    // 最后把每个数右移一位即可
    int check(vector<vector<int>> &nums, int x, int y)
    {
        int m = nums.size();
        int n = nums[0].size();

        int l = y == 0 ? 0 : nums[x][y - 1] & 1;
        int r = y == n - 1 ? 0 : nums[x][y + 1] & 1;
        int u = x == 0 ? 0 : nums[x - 1][y] & 1;
        int d = x == m - 1 ? 0 : nums[x + 1][y] & 1;
        int lu = (x > 0 && y > 0) ? nums[x - 1][y - 1] & 1 : 0;
        int ru = (x > 0 && y < n - 1) ? nums[x - 1][y + 1] & 1 : 0;
        int ld = (x < m - 1 && y > 0) ? nums[x + 1][y - 1] & 1 : 0;
        int rd = (x < m - 1 && y < n - 1) ? nums[x + 1][y + 1] & 1 : 0;
        return l + r + u + d + lu + ru + ld + rd;
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int surround = check(board, i, j);
                if (board[i][j] == 1)
                {
                    if (surround == 2 || surround == 3)
                    {
                        board[i][j] += 2;
                    }
                }
                else
                {
                    if (surround == 3)
                    {
                        board[i][j] += 2;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] >>= 1;
            }
        }
    }
};
