#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 1)
        {
            return nums[0] == target ? 0 : -1;
        }
        if (nums.size() == 0)
        {
            return -1;
        }
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
            else
            {
                // 左侧有序
                if (nums[mid] >= nums[0])
                {

                    if (target >= nums[l] && target < nums[mid])
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        l = mid + 1;
                    }
                }
                // 右侧有序
                else
                {
                    if (target > nums[mid] && target <= nums[r])
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};
