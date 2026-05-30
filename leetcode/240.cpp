#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 难点：想到从右上角开始
    // 如果target比当前数小，向左走
    // 如果target比当前数大，向下走
    // 出界了，说明没有target

    // 体会：
    // 我们需要确定两个相反的变化方向
    // 这样才能在target>num[x][y]或target<num[x][y]时有明确的缩小范围的方向
    // 例如本题，
    // 向右和向下增大，向左和向上减小
    // 我们要在增大组和减小组中各选一个，才能有效缩小范围
    // 比如选择向下和向左,如果target>num[x][y]就向下走,target<num[x][y]就向左走，对应从右上角开始
    // 但如果选择左上角开始，向下和向右都是增大,无法选择向哪走,无法有效缩小范围

    bool searchMatrix(vector<vector<int>> &nums, int target)
    {
        int m = nums.size();
        int n = nums[0].size();
        int x = 0;
        int y = n - 1;
        while (x < m && y >= 0)
        {
            if (nums[x][y] == target)
            {
                return true;
            }
            else if (target < nums[x][y])
            {
                y--;
            }
            else
            {
                x++;
            }
        }
        return false;
    }
};
