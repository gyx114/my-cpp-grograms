#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &nums)
    {
        int m = nums.size();
        int n = nums[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1)); //(i,j)开始的最长路径长度

        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret = max(ret, dfs(nums, ans, i, j));
            }
        }
        return ret;
    }

    static constexpr pair<int, int> dir[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // 上下左右四个方向

    int dfs(vector<vector<int>> &nums, vector<vector<int>> &ans, int x, int y) // 记忆化搜索
    {
        if (ans[x][y] != -1)
        {
            return ans[x][y];
        }
        else
        {
            int max_len = 0;
            for (auto p : dir)
            {
                int x1 = x + p.first;
                int y1 = y + p.second;
                if (x1 >= 0 && x1 < nums.size() && y1 >= 0 && y1 < nums[0].size() && nums[x1][y1] > nums[x][y]) // 找比当前大的扩展
                {
                    max_len = max(max_len, dfs(nums, ans, x1, y1));
                }
            }
            return ans[x][y] = 1 + max_len;
        }
    }
};
