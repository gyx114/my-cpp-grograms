#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        for (int i = 0; i < n;)
        {
            if (nums[i] == 0)
            {
                if (i > l)
                {
                    swap(nums[l], nums[i]);
                }
                l++;
                i++;
            }
            else if (nums[i] == 2)
            {
                if (i < r)
                {
                    swap(nums[r], nums[i]);
                    r--;
                }
                else
                {
                    break;
                }
            }
            else
            {
                i++;
            }
        }
    }
};
