#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans = {-1, -1};
        auto lo = lower_bound(nums.begin(), nums.end(), target);
        auto up = upper_bound(nums.begin(), nums.end(), target);
        if (lo != up)
        {
            ans = {static_cast<int>(lo - nums.begin()), static_cast<int>(up - nums.begin() - 1)};
        }
        return ans;
    }
};
