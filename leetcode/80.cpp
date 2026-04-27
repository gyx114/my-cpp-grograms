#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        int lft_move = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                cnt = 1;
            }

            else if (nums[i] == nums[i - 1])
            {
                cnt++;
                if (cnt > 2)
                {
                    lft_move++;
                }
            }
            else
            {
                cnt = 1;
            }
            if (lft_move != 0)
            {
                nums[i - lft_move] = nums[i];
            }
        }
        return n - lft_move;
    }
};
