#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int ni;
            if (i == n)
            {
                ni = nums[0];
            }
            else
            {
                ni = nums[i];
            }
            if (ni < nums[i - 1])
            {
                cnt++;
            }
            if (cnt > 1)
            {
                return false;
            }
        }
        return true;
    }
};
