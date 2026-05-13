#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (l == r)
            {
                return nums[mid];
            }
            int tmp = mid;
            int num_mid = nums[mid];
            int lft = mid;
            int c = 0;
            while (nums[tmp] == num_mid)
            {
                if (tmp == 0)
                {
                    tmp = n - 1;
                    c++;
                }
                else
                {
                    tmp--;
                    c++;
                }
                if (c == n)
                {
                    return num_mid;
                }
            }
            lft = tmp;
            tmp = mid;
            int rht = mid;
            while (nums[tmp] == num_mid)
            {
                if (tmp == n - 1)
                {
                    tmp = 0;
                }
                else
                {
                    tmp++;
                }
                if (tmp == mid)
                {
                    return num_mid;
                }
            }
            rht = tmp;

            if (num_mid < nums[lft] && num_mid < nums[rht])
            {
                return num_mid;
            }
            else
            {
                if (num_mid > nums[r])
                {
                    l = rht;
                }
                else
                {
                    r = lft;
                }
            }
        }
        return nums[0];
    }
};
