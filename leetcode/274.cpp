#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 1; i <= n; i++)
        {
            if (nums[i - 1] < i)
            {
                return i - 1;
            }
        }
        return n;
    }
};
