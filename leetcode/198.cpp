#include <bits/stdc++.h>
using namespace std;
// class Solution
// {
// public:
//     int rob(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> dp(n, 0);
//         if (n < 1)
//         {
//             return 0;
//         }
//         dp[0] = nums[0];
//         if (n >= 2)
//         {
//             dp[1] = max(dp[0], nums[1]);
//         }
//         for (int i = 2; i < n; i++)
//         {
//             dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//         }
//         return dp[n - 1];
//     }
// };

// 滚动数组优化

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int pre = 0;
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp_pre = pre;
            pre = cur;
            cur = max(tmp_pre + nums[i], cur);
        }
        return cur;
    }
};
