#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return nums[0];
        }
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        dp[0] = nums[0];
        dp[1] = nums[0];
        for (int i = 2; i < n - 1; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int ans = dp[n - 2];

        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        ans = max(ans, dp[n - 1]);
        return ans;
    }
};

// 可以滚动数组优化空间到O(1)
