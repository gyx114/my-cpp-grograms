#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int total = m * n;
        int l = 0;
        int r = total - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int i = mid / n;
            int j = mid % n;
            int val = matrix[i][j];
            if (val == target)
            {
                return true;
            }
            else
            {
                if (val > target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return false;
    }
};
