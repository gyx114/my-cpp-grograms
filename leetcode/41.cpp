#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
        {
            if (nums[i] < 1 || nums[i] > sz)
            {
                nums[i] = sz + 1;
            }
        }

        for (auto i : nums)
        {
            if (abs(i) >= 1 && abs(i) <= sz)
            {
                nums[abs(i) - 1] = -abs(nums[abs(i) - 1]);
            }
        }
        for (int i = 0; i < sz; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }
        return sz + 1;
    }
};
