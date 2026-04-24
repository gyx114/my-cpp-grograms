#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxsub = INT_MIN;
        int tmp = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (tmp < 0)
            {
                maxsub = max(maxsub, nums[i]);
                tmp = nums[i];
                continue;
            }
            if (nums[i] < 0)
            {
                maxsub = max(maxsub, tmp);
            }
            tmp += nums[i];
        }
        maxsub = max(maxsub, tmp);
        return maxsub;
    }
};
