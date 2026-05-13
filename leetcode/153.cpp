#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    inline bool is_min(vector<int> &nums, int i)
    {
        int n = nums.size();
        int lft = i == 0 ? nums.back() : nums[i - 1];
        int rht = i == n - 1 ? nums.front() : nums[i + 1];
        int ni = nums[i];
        return (ni < lft && ni < rht);
    }
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (is_min(nums, mid))
            {
                return nums[mid];
            }
            else
            {
                if (nums[mid] < nums[0])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
        }
        return nums[0];
    }
};
