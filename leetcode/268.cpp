#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        nums.push_back(nums.back());
        int n = nums.size();
        for (auto &ni : nums)
        {
            if (ni == 0)
            {
                ni = INT_MAX;
            }
            if (ni == INT_MAX || ni == INT_MIN)
            {
                nums[0] = nums[0] == INT_MAX ? INT_MIN : (nums[0] == INT_MIN ? INT_MIN : -abs(nums[0]));
            }
            else if (abs(ni) <= n)
            {
                auto absni = abs(ni);
                if (nums[absni] == 0 || nums[absni] == INT_MAX || nums[absni] == INT_MIN)
                {
                    nums[absni] = INT_MIN;
                }
                else
                {
                    nums[absni] = -abs(nums[absni]);
                }
            }
        }
        for (int i = 0; i <= n; i++)
        {
            auto ni = nums[i];
            if (ni > 0)
            {
                return i;
            }
        }
        return 0;
    }
};
