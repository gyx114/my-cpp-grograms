#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxsub(int l, int r, vector<int> &nums)
    {
        int mid = (l + r) / 2;
        if (l == r)
        {
            return nums[mid];
        }
        else
        {
            // 左侧
            int lftmax = maxsub(l, mid, nums);
            // 右侧
            int rhtmax = maxsub(mid + 1, r, nums);

            // 跨越中点

            // 中点左侧
            int midlftmax = INT_MIN;
            int midlfttmp = 0;
            for (int i = mid; i >= l; i--)
            {
                midlfttmp += nums[i];
                midlftmax = max(midlftmax, midlfttmp);
            }

            // 中点右侧
            int midrhtmax = INT_MIN;
            int midrhttmp = 0;
            for (int i = mid + 1; i <= r; i++)
            {
                midrhttmp += nums[i];
                midrhtmax = max(midrhtmax, midrhttmp);
            }

            int crossmidmax = midlftmax + midrhtmax;
            return max(max(lftmax, rhtmax), crossmidmax);
        }
    }

    int maxSubArray(vector<int> &nums)
    {
        return maxsub(0, nums.size() - 1, nums);
    }
};
