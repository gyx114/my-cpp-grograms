#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool binsearch(vector<int> &nums, int target, int l, int r)
    {
        if (l > r || r >= nums.size() || l < 0)
        {
            return false;
        }
        if (target > nums[r] || target < nums[l])
        {
            return false;
        }

        else
        {
            int mid;
            while (l <= r)
            {
                mid = l + (r - l) / 2;
                if (nums[mid] == target)
                {
                    return true;
                }
                else
                {
                    if (nums[mid] > target)
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
            }
        }
        return false;
    }
    bool search(vector<int> &nums, int target)
    {
        int divide = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] < nums[i - 1])
            {
                divide = i - 1;
            }
        }
        return binsearch(nums, target, 0, divide) || binsearch(nums, target, divide + 1, nums.size() - 1);
    }
};
