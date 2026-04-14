#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans;
        for (int i = 0; i <= n - 3; i++)
        {
            int lft = i + 1, rht = n - 1;
            int da_min = INT_MAX;
            int xiao_max = INT_MIN;
            int have_da = 0;
            int have_xiao = 0;
            while (lft < rht)
            {
                int val_lft = nums[lft];
                int val_rht = nums[rht];
                int sum = val_lft + val_rht + nums[i];
                if (sum > target)
                {
                    have_da = 1;
                    if (sum < da_min)
                    {
                        da_min = sum;
                    }
                    rht--;
                }
                else if (sum < target)
                {
                    have_xiao = 1;
                    if (sum > xiao_max)
                    {
                        xiao_max = sum;
                    }
                    lft++;
                }
                else
                {
                    return target;
                }
            }

            int cur;
            if (!have_da)
            {
                cur = xiao_max;
            }
            else if (!have_xiao)
            {
                cur = da_min;
            }
            else
            {
                if (da_min - target < target - xiao_max)
                {
                    cur = da_min;
                }
                else
                {
                    cur = xiao_max;
                }
            }
            if ((abs(cur - target) < abs(ans - target)) || i == 0)
            {
                ans = cur;
            }
        }
        return ans;
    }
};
