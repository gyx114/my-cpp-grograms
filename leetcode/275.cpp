#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &nums)
    {
        int n = nums.size();
        int l = 1;
        int r = n;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid - 1] < n - mid + 1)
            {
                l = mid + 1;
            }
            else
            {
                if (mid == 1 || nums[mid - 2] < n - mid + 2)
                {
                    return n - mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return 0;
    }
};
