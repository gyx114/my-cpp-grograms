#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int reverse(int n)
    {
        int ret = 0;
        while (n != 0)
        {
            ret = ret * 10 + n % 10;
            n /= 10;
        }
        return ret;
    }

    int minMirrorPairDistance(vector<int> &nums)
    {
        int min_diff = -1;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int ni = nums[i];
            int rni = reverse(ni);
            if (mp.count(ni))
            {
                int diff = i - mp[ni];
                if (min_diff == -1)
                {
                    min_diff = diff;
                }
                else
                {
                    min_diff = diff < min_diff ? diff : min_diff;
                }
                if (min_diff == 1)
                {
                    return 1;
                }
            }
            mp[rni] = i;
        }
        return min_diff;
    }
};
