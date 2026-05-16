#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    inline bool is_ok(vector<int> &nums, int idx)
    {
        int lft = idx == 0 ? INT_MIN : nums[idx - 1];
        int rht = idx == nums.size() - 1 ? INT_MIN : nums[idx + 1];
        return (nums[idx] >= lft && nums[idx] >= rht);
    }
    int findpeak(vector<int> &nums, int l, int r)
    {
        if (l > r)
        {
            return -1;
        }
        int mid = (l + r) / 2;
        if (is_ok(nums, mid))
        {
            return mid;
        }
        int ret = -1;
        ret = findpeak(nums, l, mid - 1);
        if (ret != -1)
        {
            return ret;
        }
        ret = findpeak(nums, mid + 1, r);
        if (ret != -1)
        {
            return ret;
        }
        return -1;
    }
    int findPeakElement(vector<int> &nums)
    {
        int ret = findpeak(nums, 0, nums.size() - 1);
        return ret;
    }
};
