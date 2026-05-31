#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 想复杂了，直接排序后从小吃到大即可
    int binseaech(long long &tar, vector<int> &nums, int l, int r)
    {
        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (tar < nums[mid])
            {
                r = mid - 1;
            }
            else
            {
                if (mid + 1 < nums.size() && nums[mid + 1] <= tar)
                {
                    l = mid + 1;
                }
                else
                {
                    return mid;
                }
            }
        }
        return -1;
    }

    bool asteroidsDestroyed(int massss, vector<int> &nums)
    {
        long long mass = massss;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> presum(n, nums[0]);
        for (int i = 1; i < n; i++)
        {
            presum[i] = presum[i - 1] + nums[i];
        }

        int l = 0;
        int r = n - 1;
        for (; l <= r;)
        {
            int x = binseaech(mass, nums, l, r);
            long long lft = l == 0 ? 0 : presum[l - 1];
            if (x >= 0)
            {
                mass += (presum[x] - lft);
                l = x + 1;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
