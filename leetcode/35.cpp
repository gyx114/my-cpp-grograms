#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid = (l + r) / 2;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (l == r)
            {
                if (target > nums[mid])
                {
                    return mid + 1;
                }
                else
                {
                    return mid;
                }
            }
            else
            {
                if (target > nums[mid])
                {
                    if (mid == nums.size() - 1 || target < nums[mid + 1])
                    {
                        return mid + 1;
                    }
                    else
                        l = mid + 1;
                }
                else
                {
                    if (mid == 0 || target > nums[mid - 1])
                    {
                        return mid;
                    }
                    else
                        r = mid - 1;
                }
            }
        }
        return 0;
    }
};
