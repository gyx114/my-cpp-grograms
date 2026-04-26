#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void setzero(vector<vector<int>> &nums)
    {
        int m = nums.size();
        int n = nums[0].size();
        int first_row_has_zero = 0;
        int first_col_has_zero = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[i][j] == 0)
                {
                    if (i == 0)
                    {
                        first_row_has_zero = 1;
                    }
                    if (j == 0)
                    {
                        first_col_has_zero = 1;
                    }
                    nums[0][j] = 0;
                    nums[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (nums[0][j] == 0 || nums[i][0] == 0)
                {
                    nums[i][j] = 0;
                }
            }
        }
        if (first_row_has_zero)
        {
            nums[0].assign(n, 0);
        }
        if (first_col_has_zero)
        {
            for (int i = 0; i < m; i++)
            {
                nums[i][0] = 0;
            }
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        setzero(matrix);
    }
};
