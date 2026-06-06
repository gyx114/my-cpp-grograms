#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        set<int> st;
        int n = nums.size();
        vector<int> dp(n, 0);
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            int idx = i;
            int maxn = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] > maxn)
                    {
                        maxn = dp[j];
                        idx = j;
                    }
                }
            }
            dp[i] = dp[idx] + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
