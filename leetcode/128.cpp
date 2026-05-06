#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int max_len = 1;
        int len = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                len++;
            }
            else
            {
                if (nums[i] == nums[i - 1])
                {
                    continue;
                }
                else
                {
                    max_len = max(len, max_len);
                    len = 1;
                }
            }
        }
        max_len = max(len, max_len);
        return max_len;
    }
};
