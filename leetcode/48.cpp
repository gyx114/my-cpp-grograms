#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // 翻转+转置
        for (int i = 0; i < n / 2; i++)
        {
            swap(matrix[i], matrix[n - 1 - i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
