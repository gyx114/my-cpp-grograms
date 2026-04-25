#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int maxpos = 0;
        int tmp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == maxpos)
            {
                if (i < nums.size() - 1 && nums[i] == 0)
                {
                    return false;
                }
                maxpos = maxpos + nums[i];
            }
            else
            {
                tmp = i + nums[i];
                maxpos = max(maxpos, tmp);
            }
        }
        return true;
    }
};
