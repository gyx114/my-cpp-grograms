#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> ans;
    void rht(vector<vector<int>> &nums, int i, int begin_j, int len)
    {
        for (int j = begin_j; j < begin_j + len; j++)
        {
            ans.push_back(nums[i][j]);
        }
    }
    void lft(vector<vector<int>> &nums, int i, int begin_j, int len)
    {
        for (int j = begin_j; j > begin_j - len; j--)
        {
            ans.push_back(nums[i][j]);
        }
    }

    void down(vector<vector<int>> &nums, int begin_i, int j, int len)
    {

        for (int i = begin_i; i < begin_i + len; i++)
        {
            ans.push_back(nums[i][j]);
        }
    }
    void up(vector<vector<int>> &nums, int begin_i, int j, int len)
    {
        for (int i = begin_i; i > begin_i - len; i--)
        {
            ans.push_back(nums[i][j]);
        }
    }

    void roll(vector<vector<int>> &nums, int i, int j, int m, int n)
    {
        if (m <= 0 || n <= 0)
        {
            return;
        }
        rht(nums, i, j, n);
        if (m > 1)
        {
            down(nums, i + 1, n + j - 1, m - 1);
            if (n > 1)
            {
                lft(nums, m + i - 1, n + j - 1 - 1, n - 1);
                if (m > 2)
                {
                    up(nums, m + i - 1 - 1, j, m - 2);
                    if (n > 2)
                    {
                        roll(nums, i + 1, j + 1, m - 2, n - 2);
                    }
                }
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int m = matrix.size();
        int n = matrix[0].size();
        roll(matrix, 0, 0, m, n);

        return ans;
    }
};
