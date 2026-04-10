#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        int is_two = 0;
        int which = 0;
        int nums[2];
        int idx_1 = 0;
        int idx_2 = 0;

        if (total % 2 == 0)
        {
            is_two = 1;
            which = total / 2;
        }
        else
        {
            is_two = 0;
            which = (total + 1) / 2;
        }

        int cnt = 1;
        for (; cnt < which + 2 && cnt <= total; cnt++)
        {
            int cur = 0;
            if (idx_1 > m - 1)
            {
                cur = nums2[idx_2];
                idx_2++;
            }
            else if (idx_2 > n - 1)
            {
                cur = nums1[idx_1];
                idx_1++;
            }
            else
            {
                if (nums1[idx_1] < nums2[idx_2])
                {
                    cur = nums1[idx_1];
                    idx_1++;
                }
                else
                {
                    cur = nums2[idx_2];
                    idx_2++;
                }
            }
            if (cnt == which)
            {
                nums[0] = cur;
            }
            else if (cnt == which + 1)
            {
                nums[1] = cur;
            }
        }
        if (is_two)
        {
            return (nums[0] + nums[1]) / 2.0;
        }
        else
        {
            return nums[0];
        }
    }
};
