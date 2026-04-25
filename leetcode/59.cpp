#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rht(vector<vector<int>> &ans, int x, int y, int len, int begin)
    {
        for (int i = begin; i <= begin + len - 1; i++)
        {
            ans[x][y + i - begin] = i;
        }
    }
    void lft(vector<vector<int>> &ans, int x, int y, int len, int begin)
    {
        for (int i = begin; i <= begin + len - 1; i++)
        {
            ans[x][y - (i - begin)] = i;
        }
    }

    void down(vector<vector<int>> &ans, int x, int y, int len, int begin)
    {
        for (int i = begin; i <= begin + len - 1; i++)
        {
            ans[x + i - begin][y] = i;
        }
    }
    void up(vector<vector<int>> &ans, int x, int y, int len, int begin)
    {
        for (int i = begin; i <= begin + len - 1; i++)
        {
            ans[x - (i - begin)][y] = i;
        }
    }

    void fill(vector<vector<int>> &ans, int x, int y, int len, int begin)
    {
        if (len <= 0)
        {
            return;
        }
        else
        {
            rht(ans, x, y, len, begin);
            begin += len;
            if (len > 1)
            {
                down(ans, x + 1, y + len - 1, len - 1, begin);
                begin += len - 1;
                lft(ans, x + len - 1, y + len - 1 - 1, len - 1, begin);
                begin += len - 1;
                if (len > 2)
                {
                    up(ans, x + len - 1 - 1, y, len - 2, begin);
                    begin += len - 2;
                }
            }
            fill(ans, x + 1, y + 1, len - 2, begin);
        }
    }
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n));
        fill(ans, 0, 0, n, 1);
        return ans;
    }
};
