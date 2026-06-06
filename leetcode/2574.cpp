#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n + 2, 0);
        vector<int> ans(n);
        for (int i = 1; i <= n + 1; i++)
        {
            pre[i] = pre[i - 1] + (i == n + 1 ? 0 : nums[i - 1]);
        }
        for (int i = 1; i <= n; i++)
        {
            ans[i - 1] = abs(pre[i - 1] - (pre[n + 1] - pre[i]));
        }
        return ans;
    }
};
